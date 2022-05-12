#include <iostream>
#include <vector>
#include <map>
#include "Event.h"
#include "Team.h"


Event::Event(){}
Event::Event(std::vector<Team> p_teams_participating)
{
    teams_participating = p_teams_participating;
}
Event::~Event(){};


void Event::make_event_classification()
{
    //TODO: Implement this method.
}


void Event::simulate()
{
    calculate_teams_points();
    make_event_classification();
}


std::map<Team, const double> Event::get_classification() const
{
    return classification;
}
