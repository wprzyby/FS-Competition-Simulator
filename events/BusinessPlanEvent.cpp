#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "BusinessPlanEvent.h"
#include "constants.h"


void BusinessPlanEvent::fill_teams_points()
{
    if (m_finalists == 0) {
        // Finding best result among all teams:
        const double max_points = find_max_points(m_teams, m_event_categories);
        //

        // Calculating teams points and adding them to the classification map:
        for (auto& team: m_teams) {
            const double team_total_result = sum_team_results(team, m_event_categories);  // summing all team`s point
            const double team_points = get_points(team_total_result, max_points);  // calculating team`s points based on the formula
            m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_points, 1)});  // inserting team and their final result into classification
        }
        //
    } else if (m_finalists > 0) {
        if (m_points_to_set.size() != m_finalists) {
            throw UnmatchedNumberOfFinalistsError();
        }

        std::vector<double> points_scored_by_teams;  // creating a buffor vector
        for (auto& team: m_teams) {
            const double team_total_result = sum_team_results(team, m_event_categories);  // summing all team`s point
            points_scored_by_teams.push_back(team_total_result);  // appending teams` points to the vector
            m_teams_and_points[team] = team_total_result;
        }

        fill_classification();
        double fixed_best_result = m_classification.at(m_finalists).second;
        // std::sort(points_scored_by_teams.begin(), points_scored_by_teams.end(), std::greater<double>());  // sorting points scored by teams
        // double fixed_best_result = points_scored_by_teams.at(m_finalists);  // getting best non-finalist result

        for (auto& [team, total_result]: m_teams_and_points) {
            try {
                m_teams_and_points.at(team) = m_points_to_set.at(team);
            } catch (std::out_of_range const&) {
                m_teams_and_points.at(team) = rd_to_n_places(get_points(total_result, fixed_best_result), 1);  // setting points from formula with fixed best result
            }
        }

    } else {
        throw NegativeAmountOfFinalitsError();
    }

}


double BusinessPlanEvent::get_points(double team_total_result, double max_points) const
{
    double points = 70*(team_total_result/max_points);  // calculating additional points

    if (points < 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
