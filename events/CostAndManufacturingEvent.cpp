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
    teams_participating = teams;
    event_categories = CosAndManEveCat;
}
CostAndManufacturingEvent::CostAndManufacturingEvent()
{
    event_categories = CosAndManEveCat;
}
CostAndManufacturingEvent::~CostAndManufacturingEvent(){}


void CostAndManufacturingEvent::calculate_teams_points(int finalists=0, std::map<Team, double> points_to_set={})
{

    // Finding best result among all teams:
    const double max_points = find_max_points(teams_and_results);
    //

    // Calculating teams points and adding them to the classification map:
    for (auto& [team, results]: teams_and_results)
    {
        const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
        const double team_points = get_points(team_total_result, max_points);  // calculating team`s points based on the formula
        classification.insert({team, team_points});  // inserting team and their final result into classification
    }
    //

    // In case there are finals:
    if (finalists > 0)
    {
        if (points_to_set.size() != finalists)  // Checking if number of provided results matches with number of finalists
        {
            throw UnmatchedNumberOfFinalistsError();
        }

        make_event_classification();  // making clasification (sorting teams)

        int iterator = 1;
        for (auto& [team, points]: points_to_set)  // modyfing best teams` results
        {
            if (iterator > finalists) {break;}
            classification.at(team) = points;
            iterator++;  // FIXME: Do I really want to this that way?
        }
    }
    //
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
