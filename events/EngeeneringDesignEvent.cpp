#include <iostream>
#include <map>
#include <vector>
#include "EngeeneringDesignEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"
#include "../exceptions.h"


EngeeneringDesignEvent::EngeeneringDesignEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
    event_categories = CosAndManEveCat;
}
EngeeneringDesignEvent::EngeeneringDesignEvent()
{
    event_categories = CosAndManEveCat;
}
EngeeneringDesignEvent::~EngeeneringDesignEvent(){}


void EngeeneringDesignEvent::calculate_teams_points()
{
    // TODO: Implement this method
}


std::string EngeeneringDesignEvent::get_file_info_name()
{
    std::string name = "CostAndManufacturingEventInfo.pdf";
    return name;
}
