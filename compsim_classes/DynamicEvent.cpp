#include "DynamicEvent.h"
#include "compsim_classes/event_tools.h"

void DynamicEvent::fill_teams_points() {
    basic_points_filling();
    additional_points_filling();
}

void DynamicEvent::basic_points_filling() {
    std::map<Team, double> teams_and_best_times = find_teams_best_times();
    double best_time_overall = find_best_time_overall(teams_and_best_times);

    for (auto& [team, team_best_time]: teams_and_best_times) {
        double team_final_score;

        if (team_best_time == 0) {
            team_final_score = 0;  // Case of DNF or DSQ
        } else if (!m_use_time_threshold || team_best_time < m_time_threshold_coefficient*best_time_overall) {
            team_final_score = m_base_points + get_additional_points(best_time_overall, team_best_time);  // Calculating teams` final score in non - driverless.
        } else {
            team_final_score = m_base_points;
        }

        m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their final score to the classification.
    }
}

std::map<Team, double> DynamicEvent::find_teams_best_times() {
    std::map<Team, double> teams_and_best_times;
    for (auto& team: m_teams) {
        double time_to_set = find_best_time_for_team(team, m_event_categories);  // Finding best team`s time
        teams_and_best_times[team] = time_to_set;  // inserting team and their best result into the bufforing map.
    }
    return teams_and_best_times;
}

