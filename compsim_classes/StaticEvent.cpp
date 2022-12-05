#include "StaticEvent.h"
#include "compsim_classes/event_tools.h"
#include "exceptions.h"

void StaticEvent::fill_teams_points() {
    if (m_number_of_finalists != 0) {
        finals_points_filling();
    } else {
        no_finals_points_filling();
    }
}

void StaticEvent::no_finals_points_filling() {
    for (auto& team: m_teams) {
        double points_to_set = sum_team_results(team, m_event_categories);
        m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(points_to_set, 1)});
    }
}

void StaticEvent::finals_points_filling() {
    if (m_points_to_set.size() != m_number_of_finalists) {
            throw UnmatchedNumberOfFinalistsError();
        }

        for (auto& team: m_teams) {
            const double team_total_result = sum_team_results(team, m_event_categories);  // summing all team`s point
            m_teams_and_points[team] = team_total_result;
        }

        fill_classification(); // used to obtain sorted teams and points to use in assigning points adjusted for finalists
        double fixed_best_result = m_classification.at(m_number_of_finalists).second;

        for (auto& [team, total_result]: m_teams_and_points) {
            try {
                m_teams_and_points.at(team) = m_points_to_set.at(team);
            } catch (std::out_of_range const&) {
                m_teams_and_points.at(team) = rd_to_n_places(get_points(total_result, fixed_best_result), 1);  // setting points from formula with fixed best result
            }
        }
}