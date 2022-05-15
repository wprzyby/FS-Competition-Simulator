#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "CostAndManufacturingEvent.h"
#include "Event_tools.h"

//TODO: Implement according to BuisnessPlanEvent implementation

CostAndManufacturingEvent::CostAndManufacturingEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
}
CostAndManufacturingEvent::~CostAndManufacturingEvent(){}
CostAndManufacturingEvent::CostAndManufacturingEvent(){}


void Event::set_results(std::map<Team, std::map<std::string, double>> &results)
{
    enum keys_check {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, bom_discussion, cost_understanding, real_case, assembly, part, process_material};
    for (auto& [team, inner_map]: results)
    {
        for (auto& [category, points]: inner_map)
        {
            if (category not in keys_check)
            {
            }
        }
    }
    teams_and_results = results;
}


void CostAndManufacturingEvent::calculate_teams_points(bool finals, const int finalists=0)  // This Event can have two stages. Max four finalists can be jugded separetly
{
    if (finals)  //TODO Implement 'final' case.
    {
        // 1. Sum teams` points
        // 2. Sort teams
        // 3. Exclude 'finalists' from classification and create an extra points request for them
    }
    else
    {
        int i = 0;
        for (std::map<Team,std::map<std::string,double>>::iterator itr = teams_and_results.begin(); itr != teams_and_results.end(); ++itr)
        {
            const double team_points = sum_all_teams_results((*itr).second);  // summing all team`s point
            classification.insert({teams_participating[i], team_points});  // inserting team and their final result into classification
            i++;
        }
    }
    //
}


std::string CostAndManufacturingEvent::get_file_info_name()
{
    std::string name = "CostAndManufacturingEvent.pdf";
    return name;
}