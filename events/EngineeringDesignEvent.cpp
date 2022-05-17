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
    teams_participating = teams;
    event_categories = CosAndManEveCat;
}
EngineeringDesignEvent::EngineeringDesignEvent()
{
    event_categories = CosAndManEveCat;
}
EngineeringDesignEvent::~EngineeringDesignEvent(){}


void EngineeringDesignEvent::calculate_teams_points()
{
    // TODO: Implement this method
}


std::string EngineeringDesignEvent::get_file_info_name()
{
    std::string name = "CostAndManufacturingEventInfo.pdf";
    return name;
}
