#ifndef AUTOCROSS_EVENT_H
#define AUTOCROSS_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "Event.h"


class AutocrossEvent : public Event  // AutocrossEvent class that inherits from the abstract class Event
{
    // Methods:
    virtual void create_teams_and_results_map();  // Function to create teams_and_results map.
    virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).
    virtual void open_info_file();  // Opens the file with information about the Event.

    public:
    // Constructor:
    AutocrossEvent(std::vector<Team> teams);  // Constructor with demanded argument - vector of teams participating in the AutocrossEvent Event.
};

#endif
