#ifndef ENGINERING_DESIGN_EVENT_H
#define ENGINERING_DESIGN_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class EngineeringDesignEvent : public Event  // EngineeringDesignEvent class that inherits from the abstract class Event
{
    protected:
        // Methods:
        virtual void calculate_teams_points(int finalists=0, std::map<Team, double> points_to_set={});  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        EngineeringDesignEvent();
        EngineeringDesignEvent(std::vector<Team> &teams);
        // Destructor:
        ~EngineeringDesignEvent();
        // Methods
        virtual std::string get_file_info_name();
};

#endif

// DONE
