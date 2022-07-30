#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class EngineeringDesignEvent : public Event  // EngineeringDesignEvent class that inherits from the abstract class Event
{
    protected:
        // Methods:
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        EngineeringDesignEvent() {};
        EngineeringDesignEvent(std::vector<Team> &teams, std::string which_driverless="");
        // Destructor:
        ~EngineeringDesignEvent() {};
};
