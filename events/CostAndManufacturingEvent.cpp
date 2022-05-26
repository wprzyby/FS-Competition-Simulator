#include <iostream>
#include <map>
#include <vector>
#include "CostAndManufacturingEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"
#include "../exceptions.h"


CostAndManufacturingEvent::CostAndManufacturingEvent(std::vector<Team> &teams)
{
    m_teams_participating = teams;
    m_event_type = cost_and_manufacturing;
    m_event_categories = category_lists.at(cost_and_manufacturing);
}
CostAndManufacturingEvent::CostAndManufacturingEvent()
{
    m_event_type = cost_and_manufacturing;
    m_event_categories = category_lists.at(cost_and_manufacturing);
}
CostAndManufacturingEvent::~CostAndManufacturingEvent(){}


void CostAndManufacturingEvent::calculate_teams_points(int finalists, std::map<Team, double> points_to_set)
{
    if (finalists == 0)
    {
        // Finding best result among all teams:
        const double max_points = find_max_points(m_teams_and_results);
        //

        // Calculating teams points and adding them to the classification map:
        for (auto& [team, results]: m_teams_and_results)
        {
            const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
            const double team_points = get_points(team_total_result, max_points);  // calculating team`s points based on the formula
            m_classification.insert({team, team_points});  // inserting team and their final result into classification
        }
        //
    }
    else if (finalists > 0)  // In case there are finals:
    {
        if (points_to_set.size() != finalists)  // Checking if number of provided results matches with number of finalists
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

        std::sort(points_scored_by_teams.begin(), points_scored_by_teams.end(), compare);  // sorting points scored by teams  // FIXME: Same mistake one more time
        double fixed_best_result = points_scored_by_teams[finalists];  // getting best non-finalist result

        int iterator = 1;
        make_event_classification();  // sorting teams by their total score
        auto results_to_set_iterator = points_to_set.begin();  // setting map with points to set iterator at the first element

        for (auto& [team, total_result]: m_classification)
        {
            if (iterator <= finalists)
            {
                for (auto& [external_team, external_result]: points_to_set)
                {
                    if (external_team == team)  // searching fr current team among points_to_set
                    {
                        m_classification.at(team) = external_result;  // setting curent teams result
                    }
                }
            }
            else  // setting points according to the rules for non-finalists
            {
                m_classification.at(team) = rd_to_n_places(get_points(total_result, fixed_best_result), 1);  // setting points from formula with fixed best result
            }
            iterator++;
        }

    }
    else
    {
        throw NegativeAmountOfFinalitsError();
    }
}


std::string CostAndManufacturingEvent::get_file_info_name()
{
    std::string name = "CostAndManufacturingEventInfo.pdf";
    return name;
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
