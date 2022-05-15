#include <iostream>
#include <map>
#include <vector>
#include "BuisnessPlanEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"


BuisnessPlanEvent::BuisnessPlanEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
}
BuisnessPlanEvent::BuisnessPlanEvent(){}
BuisnessPlanEvent::~BuisnessPlanEvent(){}


void BuisnessPlanEvent::set_results(std::map<Team, std::map<EventsCategories, double>> &results)
{
    teams_and_results = results;
}


void BuisnessPlanEvent::calculate_teams_points()
{
    // Finding best result among all teams:
    const double max_points = find_max_points(teams_and_results);
    //

    // Calculating teams points and adding them to the classification map:
    for (auto& [team, results]: teams_and_results)
    {
        const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
        const double team_points = 70*(team_total_result/max_points);  // calculating team`s points based on the formula
        classification.insert({team, team_points});  // inserting team and their final result into classification
    }
    //
}


std::string BuisnessPlanEvent::get_file_info_name()
{
    std::string name = "BuisnessPlanEventInfo.pdf";
    return name;
}
