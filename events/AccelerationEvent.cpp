#include <iostream>
#include <map>
#include <vector>
#include "AccelerationEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"


AccelerationEvent::AccelerationEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
}
AccelerationEvent::AccelerationEvent(){}
AccelerationEvent::~AccelerationEvent(){}


void AccelerationEvent::set_results(std::map<Team, std::map<EventsCategories, double>> &results)
{
    teams_and_results = results;
}


void AccelerationEvent::calculate_teams_points()
{
    // TODO: Finish implementation of this method
}


std::string AccelerationEvent::get_file_info_name()
{
    std::string name = "AccelerationEventInfo.pdf";
    return name;
}
