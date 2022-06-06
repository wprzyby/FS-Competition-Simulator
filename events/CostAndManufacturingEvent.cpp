#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "CostAndManufacturingEvent.h"
#include "../base_classes/Team.h"

#include "../event_tools.h"
#include "../constants.h"
#include "../enums/enums.h"
#include "../exceptions.h"


CostAndManufacturingEvent::CostAndManufacturingEvent(std::vector<Team> &teams, int finalists, std::map<Team, double> points_to_set)
{
    m_teams_participating = teams;
    m_event_type = cost_and_manufacturing;
    m_event_categories = category_lists.at(cost_and_manufacturing);
    m_finalists = finalists;
    m_points_to_set = points_to_set;
}
CostAndManufacturingEvent::CostAndManufacturingEvent()
{
    m_event_type = cost_and_manufacturing;
    m_event_categories = category_lists.at(cost_and_manufacturing);
}


void CostAndManufacturingEvent::calculate_teams_points()
{
    if (m_finalists == 0)
    {
        // Finding best result among all teams:
        const double max_points = find_max_points(m_teams_and_results);
        //

        // Calculating teams points and adding them to the classification map:
        for (auto& [team, results]: m_teams_and_results)
        {
            const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
            const double team_points = get_points(team_total_result, max_points);  // calculating team`s points based on the formula
            m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_points, 1)});  // inserting team and their final result into classification
        }
        //
    }
    else if (m_finalists > 0)  // In case there are finals:
    {
        if (m_points_to_set.size() != m_finalists)  // Checking if number of provided results matches with number of finalists
        {
            throw UnmatchedNumberOfFinalistsError();
        }

        std::vector<double> points_scored_by_teams;  // creating a buffor vector
        for (auto& [team, results]: m_teams_and_results)
        {
            const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
            points_scored_by_teams.push_back(team_total_result);  // appending teams` points to the vector
            m_classification[team] = team_total_result;
        }

        std::sort(points_scored_by_teams.begin(), points_scored_by_teams.end(), std::greater<double>());  // sorting points scored by teams
        double fixed_best_result = points_scored_by_teams[m_finalists];  // getting best non-finalist result

        make_event_classification();  // sorting teams by their total score

        for (auto& [team, total_result]: m_classification)
        {
            try
            {
                m_classification.at(team) = m_points_to_set.at(team);
            }
            catch (std::out_of_range const&)
            {
                m_classification.at(team) = rd_to_n_places(get_points(total_result, fixed_best_result), 1);  // setting points from formula with fixed best result
            }
        }

    }
    else
    {
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
