#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "CostAndManufacturingEvent.h"
#include "constants.h"


void CostAndManufacturingEvent::fill_teams_points()
{
    if (m_finalists == 0) {
        // Finding best result among all teams:
        const double max_points = find_max_points(m_teams_and_results);
        //

        // Calculating teams points and adding them to the classification map:
        for (auto& [team, results]: m_teams_and_results)
        {
            const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
            const double team_points = get_points(team_total_result, max_points);  // calculating team`s points based on the formula
            m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_points, 1)});  // inserting team and their final result into classification
        }
        //
    } else if (m_finalists > 0) {
        if (m_points_to_set.size() != m_finalists) {
            throw UnmatchedNumberOfFinalistsError();
        }

        std::vector<double> points_scored_by_teams;  // creating a buffor vector
        for (auto& [team, results]: m_teams_and_results) {
            const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
            points_scored_by_teams.push_back(team_total_result);  // appending teams` points to the vector
            m_teams_and_points[team] = team_total_result;
        }

        std::sort(points_scored_by_teams.begin(), points_scored_by_teams.end(), std::greater<double>());  // sorting points scored by teams
        double fixed_best_result = points_scored_by_teams[m_finalists];  // getting best non-finalist result

        fill_classification();  // sorting teams by their total score

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


double CostAndManufacturingEvent::get_points(double team_total_result, double max_points) const
{
    double points = 95*(team_total_result/max_points);  // calculating additional points

    if (points < 0)  // Checking if points are not negative
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
