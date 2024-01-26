#include "EventSimulatorStandard.h"

#include <limits>
#include "event_tools.h"
#include <cmath>


EventData EventSimulatorStandard::preprocessing_standard(const Teams& teams, std::vector<EventCategory> categories)
{
    EventData event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: teams) {
        double best_time = find_best_time_for_team(team, categories);
        event_data[team.name()] = best_time;
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}

EventData EventSimulatorStandard::preprocessing_ranks_based(const Teams& teams, std::vector<EventCategory> categories)
{
    EventData event_data;
    std::vector<std::pair<std::string, double>> teams_and_best_times = {};
    for (auto& team: teams) {
        double best_time = find_best_time_for_team(team.name(), categories);
        teams_and_best_times.push_back({team.name(), best_time});
    }
    sort_teams_and_best_times(teams_and_best_times);
    int current_place = 0;
    for (auto& [team_name, best_time]: teams_and_best_times) {
        if (best_time == 0) break;
        ++current_place;
        event_data[team_name] = current_place;
    }
    event_data["non_zero_times"] = current_place;
    return event_data;
}


EventData EventSimulatorStandard::preprocessing_dc_autocross(const Teams& teams)
{
    double t_6ms;
    try {
        t_6ms = events_constants_.at("dc_autocross_t_6ms");
    } catch (std::out_of_range &e) {
        throw missing_constant_error("t_6ms", autocross_DC);
    }
    EventData event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: teams) {
        double best_time = find_best_time_for_team_dc_autocross(team, t_6ms);
        event_data[team.name()] = best_time;
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["t_6ms"] = t_6ms;
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}


EventData EventSimulatorStandard::preprocessing_efficiency(const Teams& teams)
{
    EventData event_data;
    std::map<std::string, double> teams_and_uncorr_times;
    double best_uncorr_time = std::numeric_limits<double>::infinity();
    double best_eff_factor = std::numeric_limits<double>::infinity();

    for (auto& team: teams) {
        double uncorr_time = team.result_of_category(end_uncorrected_time);
        double energy_used = team.result_of_category(end_energy_used);
        double energy_produced = team.result_of_category(end_energy_produced);
        double efficiency_factor = (energy_used - energy_produced * 0.9) * std::pow(uncorr_time, 2);
        event_data["uncorr_time_" + team.name()] = uncorr_time;
        event_data["eff_factor_" + team.name()] = efficiency_factor;
        if (uncorr_time != 0 && uncorr_time < best_uncorr_time) {
            best_uncorr_time = uncorr_time;
        }
        best_eff_factor = std::min(best_eff_factor, efficiency_factor);
    }
    event_data["best_eff_factor"] = best_eff_factor;
    event_data["best_uncorr_time"] = best_uncorr_time;
    return event_data;

}


EventData EventSimulatorStandard::preprocessing_skidpad(const Teams& teams)
{
    EventData event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: teams) {
        double best_time = find_best_time_for_team_skidpad(team);
        event_data[team.name()] = best_time;
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}


EventData EventSimulatorStandard::preprocessing_skidpad_ranks_based(const Teams& teams)
{
    EventData event_data;
    std::vector<std::pair<std::string, double>> teams_and_best_times = {};
    for (auto& team: teams) {
        double best_time = find_best_time_for_team_skidpad(team.name());
        teams_and_best_times.push_back({team.name(), best_time});
    }
    sort_teams_and_best_times(teams_and_best_times);
    int current_place = 0;
    for (auto& [team_name, best_time]: teams_and_best_times) {
        if (best_time != 0) {
            ++current_place;
            event_data[team_name] = current_place;

        } else {
            event_data[team_name] = 0;
        }

    }
    event_data["non_zero_times"] = current_place;
    return event_data;
}


EventData EventSimulatorStandard::preprocessing_trackdrive(const Teams& teams) {
    EventData event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: teams) {
        double best_time = find_best_time_for_team(team, {tra_time});
        event_data[team.name()] = best_time;
        event_data["laps_" + team.name()] = team.result_of_category(tra_laps);
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}
