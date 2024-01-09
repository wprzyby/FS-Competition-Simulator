#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>
#include <cmath>

#include "Competition.h"
#include "Team.h"
#include "event_tools.h"

#include "constants.h"
#include "exceptions.h"
#include <compsim_enums/enums.h>

const std::vector<EventCategory> Competition::BUSINESSPLAN_EVENT_CATEGORIES = {pitch_video, novelty, content, finances, deep_dive_topic, demonstration_and_structure, delivery, questions, general_impression};
const std::vector<EventCategory> Competition::COST_AND_MANUFACTURING_EVENT_CATEGORIES = {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case};
const std::vector<EventCategory> Competition::ENGINEERING_DESIGN_EVENT_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, driver_interface, autonomous_functionality, design_report};
const std::vector<EventCategory> Competition::DC_ENGINEERING_DESIGN_EVENT_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, autonomous_functionality};
const std::vector<EventCategory> Competition::SKIDPAD_EVENT_CATEGORIES = {first_skid_left_time, first_skid_right_time, second_skid_left_time, second_skid_right_time};
const std::vector<EventCategory> Competition::ACCELERATION_EVENT_CATEGORIES = {first_acc_time, second_acc_time};
const std::vector<EventCategory> Competition::AUTOCROSS_EVENT_CATEGORIES = {first_aut_time, second_aut_time, third_aut_time, fourth_aut_time};
const std::vector<EventCategory> Competition::DC_AUTOCROSS_EVENT_CATEGORIES = {first_aut_time, second_aut_time};
const std::vector<EventCategory> Competition::ENDURANCE_EVENT_CATEGORIES = {end_corrected_time, end_uncorrected_time, end_energy_used, end_energy_produced};
const std::vector<EventCategory> Competition::TRACKDRIVE_EVENT_CATEGORIES = {tra_time, tra_laps};


Competition::Competition(std::vector<Team> &teams, std::vector<EventType> &events)
{
    set_teams(teams);
    set_events(events);
}


void Competition::set_events(std::vector<EventType> &events)
{
    m_events = events;
}


void Competition::set_teams(std::vector<Team> &teams)
{
    m_teams = teams;
}


void Competition::simulate()
{
    m_events_and_teams_points.clear();
    m_events_and_classifications.clear();

    for(auto& event: m_events)
    {
        switch(event) {
            case acceleration:
                simulate_m_acceleration();
                break;
            case acceleration_DV:
                simulate_dv_acceleration();
                break;
            case acceleration_DC:
                simulate_dc_acceleration();
                break;
            case autocross:
                simulate_m_autocross();
                break;
            case autocross_DC:
                simulate_dc_autocross();
                break;
            case businessplan:
                simulate_businessplan();
                break;
            case cost_and_manufacturing:
                simulate_cost_and_manufacturing();
                break;
            case endurance:
                simulate_endurance();
                break;
            case efficiency:
                simulate_efficiency();
                break;
            case engineering_design:
                simulate_engineering_design();
                break;
            case engineering_design_DC:
                simulate_dc_engineering_design();
                break;
            case skidpad:
                simulate_m_skidpad();
                break;
            case skidpad_DV:
                simulate_dv_skidpad();
                break;
            case skidpad_DC:
                simulate_dc_skidpad();
                break;
            case trackdrive:
                simulate_trackdrive();
                break;
            default:
                throw std::invalid_argument("Invalid event type selected");
        }
    }
}


void Competition::create_classification()
{
    m_comp_classification.clear();
    m_teams_and_comp_points.clear();
    simulate();

    // summing points from each event for every team to obtain total competition points
    for(auto& [_, event_points]: m_events_and_teams_points)
        {
            for(auto& [team, points]: event_points)
            {
                m_teams_and_comp_points[team] += points;
            }
        }

    // assigning final points to teams, adding {team, total_points} pair to final classification
    for(auto& team: m_teams)
    {
        m_comp_classification.push_back({team.name(), m_teams_and_comp_points.at(team.name())});
    }

    // sorting the final classification by team's points in descending order
    auto is_team_better = [](std::pair<std::string, double> pair1, std::pair<std::string, double> pair2)
    {
        return pair1.second > pair2.second;
    };
    std::sort(m_comp_classification.begin(), m_comp_classification.end(), is_team_better);

}


std::map<std::string, double> Competition::preprocessing_standard(std::vector<EventCategory> categories)
{
    std::map<std::string, double> event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: m_teams) {
        double best_time = find_best_time_for_team(team, categories);
        event_data[team.name()] = best_time;
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}

std::map<std::string, double> Competition::preprocessing_ranks_based(std::vector<EventCategory> categories)
{
    std::map<std::string, double> event_data;
    std::vector<std::pair<std::string, double>> teams_and_best_times = {};
    for (auto& team: m_teams) {
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


std::map<std::string, double> Competition::preprocessing_static_finals(std::vector<EventCategory> categories, EventCategory finals_category)
{
    std::map<std::string, double> event_data;
    double best_result_non_finalist = 0;
    for (auto& team: m_teams) {
        if (team.result_of_category(finals_category) != 0) {
            event_data[team.name()] == team.result_of_category(finals_category);
            continue;
        }
        double sum_of_results = sum_results(team, categories, {finals_category});
        event_data[team.name()] = sum_of_results;
        if (sum_of_results > best_result_non_finalist) {
            best_result_non_finalist = sum_of_results;
        }
    }
    event_data["best_result_non_finalist"] = best_result_non_finalist;
    return event_data;
}

std::map<std::string, double> Competition::preprocessing_static_no_finals(std::vector<EventCategory> categories)
{
    std::map<std::string, double> event_data;
    for (auto& team: m_teams) {
        event_data[team.name()] = sum_results(team, categories);
    }
    return event_data;
}


std::map<std::string, double> Competition::preprocessing_dc_autocross()
{
    std::map<std::string, double> event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: m_teams) {
        double best_time = find_best_time_for_team_dc_autocross(team, m_t_6ms);
        event_data[team.name()] = best_time;
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}


std::map<std::string, double> Competition::preprocessing_efficiency()
{
    std::map<std::string, double> event_data;
    std::map<std::string, double> teams_and_uncorr_times;
    double best_uncorr_time = std::numeric_limits<double>::infinity();
    double best_eff_factor = std::numeric_limits<double>::infinity();

    for (auto& team: m_teams) {
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


std::map<std::string, double> Competition::preprocessing_skidpad()
{
    std::map<std::string, double> event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: m_teams) {
        double best_time = find_best_time_for_team_skidpad(team);
        event_data[team.name()] = best_time;
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}


std::map<std::string, double> Competition::preprocessing_skidpad_ranks_based()
{
    std::map<std::string, double> event_data;
    std::vector<std::pair<std::string, double>> teams_and_best_times = {};
    for (auto& team: m_teams) {
        double best_time = find_best_time_for_team_skidpad(team.name());
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