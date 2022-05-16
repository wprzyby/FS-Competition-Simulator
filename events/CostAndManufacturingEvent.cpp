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


void CostAndManufacturingEvent::calculate_teams_points()
{
    // TODO: Implement this method
}


std::string CostAndManufacturingEvent::get_file_info_name()
{
    std::string name = "CostAndManufacturingEventInfo.pdf";
    return name;
}
