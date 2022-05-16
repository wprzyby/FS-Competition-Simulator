#ifndef COST_AND_MANUFACTURING_EVENT_H
#define COST_AND_MANUFACTURING_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"

//TODO: Change this according to new implementation
class CostAndManufacturingEvent : public Event  // CostAndManufacturingEvent class that inherits from the abstract class Event
{
    protected:
        // Methods:
        virtual void set_results(std::map<Team, std::map<EventsCategories, double>> &results);  // Function to create teams_and_results map.
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
        // Constructors:
        CostAndManufacturingEvent();
        CostAndManufacturingEvent(std::vector<Team> &teams);
        // Destructor:
        ~CostAndManufacturingEvent();
        // Methods
        virtual std::string get_file_info_name();
};

#endif
