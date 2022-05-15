#ifndef COST_AND_MANUFACTURING_EVENT_H
#define COST_AND_MANUFACTURING_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "Event.h"


class CostAndManufacturingEvent : public Event  // CostAndManufacturingEvent class that inherits from the abstract class Event
{
    // Methods:
    virtual void create_teams_and_results_map();  // Function to create teams_and_results map.
    virtual void calculate_teams_points(bool finals, const int finalists=0);  // Function that calculates points for teams (based on the map: teams_and_results).
    virtual void open_info_file();  // Opens the file with information about the Event.

    public:
    // Constructor:
    CostAndManufacturingEvent::CostAndManufacturingEvent();  // Default constructor.
    CostAndManufacturingEvent(std::vector<Team> &teams);  // Constructor with demanded argument - vector of teams participating in the CostAndManufacturingEvent Event.
    virtual std::string get_file_info_name();
};

#endif
