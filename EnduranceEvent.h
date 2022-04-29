#ifndef ENDURANCE_EVENT_H
#define ENDURANCE_EVENT_H
#include <map>
#include <vector>
#include "Team.h"
#include "Event.h"


class EnduranceEvent : public Event  // EnduranceEvent class that inherits from the abstract class Event
{
    // Methods:
    virtual void create_teams_and_results_map();  // Function to create teams_and_results map.
    virtual void set_teams_results();  // Function to set results in the event for every team participating.
    virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).
    virtual void open_info_file();  // Opens the file with information about the Event.

    public:
    // Constructor:
    EnduranceEvent(std::vector<Team> teams);  // Constructor with demanded argument - vector of teams participating in the Event.
};

#endif
