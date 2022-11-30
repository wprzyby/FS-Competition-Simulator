#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "TrackdriveEvent.h"
#include "constants.h"

std::map<Team, double> TrackdriveEvent::find_teams_best_times() {
    std::map<Team, double> teams_and_best_times;
    for (auto& team: m_teams) {
        teams_and_best_times[team] = team.result_of_category(tra_time);
    }
    return teams_and_best_times;
}


void TrackdriveEvent::fill_teams_points() {
    std::map<Team, double> teams_and_best_times = find_teams_best_times();
    double time_thresh_coefficient = 2;
    double points_per_lap = 5;
    double best_time_overall = find_best_time_overall(teams_and_best_times);

    for (auto& [team, team_best_time]: teams_and_best_times) {
        double team_final_score = team.result_of_category(tra_laps) * points_per_lap;

        if (team_best_time != 0 && team_best_time < time_thresh_coefficient*best_time_overall) {
            team_final_score += get_additional_points(best_time_overall, team_best_time);
        }

        m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});
    }
}


double TrackdriveEvent::get_additional_points(double best_time_overall, double team_best_time) {
    double points = 150*(((best_time_overall*2/team_best_time) - 1));

    if (points <= 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}


// DONE
