#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "CostAndManufacturingEvent.h"
#include "Event_tools.h"


CostAndManufacturingEvent::CostAndManufacturingEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
}


void CostAndManufacturingEvent::create_teams_and_results_map()
{
    // Creating sophisticated map for this event:
    std::map<std::string, double> event_attributes;
    event_attributes.insert(std::pair<std::string, double> ("format_and_accuracy_of_documents", 0));
    event_attributes.insert(std::pair<std::string, double> ("knowledge_of_documents_and_vehicle", 0));
    event_attributes.insert(std::pair<std::string, double> ("bom_discussion", 0));
    event_attributes.insert(std::pair<std::string, double> ("cost_understanding", 0));
    event_attributes.insert(std::pair<std::string, double> ("real_case", 0));
    event_attributes.insert(std::pair<std::string, double> ("assembly", 0));
    event_attributes.insert(std::pair<std::string, double> ("part", 0));
    event_attributes.insert(std::pair<std::string, double> ("process/material", 0));
    //

    // Inserting created map into the map with teams:
    for (int i = 0; i < teams_participating.size(); i++)
    {
        teams_and_results.insert(std::pair<Team,std::map<std::string,double>> (teams_participating[i], event_attributes));
    }
    //
}


void CostAndManufacturingEvent::calculate_teams_points(bool finals, const int finalists=0)  // This Event can have two stages. Max four finalists can be jugded separetly
{
    if (finals)
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