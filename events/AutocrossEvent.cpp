#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "AutocrossEvent.h"
#include "constants.h"

void AutocrossEvent::fill_teams_points()
{
    double base_points = BASE_COMPLETION_POINTS.at(autocross);
    double time_threshold_coefficient = 1.25;
    std::map<Team, double> teams_and_best_times = find_teams_best_times();

    fill_points_std_dynamic(base_points, time_threshold_coefficient,
                            teams_and_best_times, &get_additional_points);
}


double AutocrossEvent::get_additional_points(double best_time_overall, double team_best_time)
{
    double points = 95.5 * ( ( ( (best_time_overall * 1.25) / team_best_time) - 1 ) / 0.25 );

    if (points < 0)
    {
        throw NegativeAdditionalPointsError();
    }

    return points;

}


std::map<Team, double> DCAutocrossEvent::find_teams_best_times() {
    std::map<Team, double> teams_and_best_times;
    for (auto& [team, team_results]: m_teams_and_results) {
        double first_time = team_results.at(first_aut_time);
        double second_time = team_results.at(second_aut_time);

        // DNFs in both runs result in not scoring base points
        // hence best time set to 0 as demonstration of DNF of whole event
        if (first_time == 0 && second_time == 0) {
            teams_and_best_times[team] = 0;
            continue;
        }

        // if DNF/DQ or time exceeded Tmax, the time for the run is set to Tmax
        if (first_time == 0 || first_time>m_t_max) {first_time = m_t_max;}
        if (second_time == 0 || second_time>m_t_max) {second_time = m_t_max;}

        double avg_time = (first_time + second_time) / 2;
        double time_to_set = std::min(first_time, avg_time);
        teams_and_best_times[team] = time_to_set;
    }
    return teams_and_best_times;
}


void DCAutocrossEvent::fill_teams_points() {
    double base_points = BASE_COMPLETION_POINTS.at(autocross_DC);
    std::map<Team, double> teams_and_best_times = find_teams_best_times();
    double best_time_overall = find_best_time_overall(teams_and_best_times);

    for (auto& [team, team_best_time]: teams_and_best_times) {
        double team_final_score = 0;
        if (team_best_time != 0) {
            team_final_score += base_points + get_additional_points(best_time_overall, team_best_time);
        }
        m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});
    }
}


double DCAutocrossEvent::get_additional_points(double best_time_overall, double team_best_time) {
    double points = 90 * ((m_t_max - team_best_time) / (m_t_max - best_time_overall));
    if (points <= 0) {
        throw NegativeAdditionalPointsError();
    }
    return points;

}