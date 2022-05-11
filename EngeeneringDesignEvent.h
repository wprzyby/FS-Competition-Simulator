#ifndef ENGEENERING_DESIGN_EVENT_H
#define ENGEENERING_DESIGN_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "Event.h"


class EngeeneringDesignEvent : public Event  // EngeeneringDesignEvent class that inherits from the abstract class Event
{
    // Methods:
    virtual void set_results(std::map<Team, std::map<std::string, double>> &results);  // Function to create teams_and_results map.
    virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
    // Constructor:
    EngeeneringDesignEvent(std::vector<Team> teams);  // Constructor with demanded argument - vector of teams participating in the Event.
    virtual std::string get_file_info_name();
};

#endif
