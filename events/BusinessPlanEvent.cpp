#include <iostream>
#include <map>
#include <vector>
#include "BusinessPlanEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"
#include "../exceptions.h"


BusinessPlanEvent::BusinessPlanEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
    event_categories = BuiPlaEveCat;
    m_event_type = businessplan;
}
BusinessPlanEvent::BusinessPlanEvent()
{
    event_categories = BuiPlaEveCat;
}
BusinessPlanEvent::~BusinessPlanEvent(){}


void BusinessPlanEvent::calculate_teams_points(int finalists=0, std::map<Team, double> points_to_set={})
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
            iterator++; 
        }
    }
    //
}


std::string BusinessPlanEvent::get_file_info_name()
{
    std::string name = "BusinessPlanEventInfo.pdf";
    return name;
}


double BusinessPlanEvent::get_points(double team_total_result, double max_points) const
{
    double points = 70*(team_total_result/max_points);  // calculating additional points

    if (points < 0)  // Checking if points are not negative
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}

// DONE | Wzorzec dla statycznych
