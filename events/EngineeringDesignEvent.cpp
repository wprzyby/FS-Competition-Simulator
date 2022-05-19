#include <iostream>
#include <map>
#include <vector>
#include "EngineeringDesignEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"
#include "../exceptions.h"


EngineeringDesignEvent::EngineeringDesignEvent(std::vector<Team> &teams)
{
    m_teams_participating = teams;
    m_event_type = engineering_design;
    m_event_categories = category_lists.at(engineering_design);
}
EngineeringDesignEvent::EngineeringDesignEvent()
{
    m_event_type = engineering_design;
    m_event_categories = category_lists.at(engineering_design);
}
EngineeringDesignEvent::~EngineeringDesignEvent(){}


void EngineeringDesignEvent::calculate_teams_points(int finalists, std::map<Team, double> points_to_set)
{
    // Calculating teams points and adding them to the classification map:
    for (auto& [team, results]: m_teams_and_results)
    {
        const double team_points = sum_all_teams_results(results);  // summing all team`s point
        m_classification.insert({team, team_points});  // inserting team and their final result into classification
    }
}


std::string EngineeringDesignEvent::get_file_info_name()
{
    std::string name = "CostAndManufacturingEventInfo.pdf";
    return name;
}