#ifndef BUISNESS_PLAN_EVENT_H
#define BUISNESS_PLAN_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "Event.h"


class BuisnessPlanEvent : public Event  // BuisnessEvent class that inherits from the abstract class Event
{
    protected:
        // Methods:
        virtual void set_results(std::map<Team, std::map<EventsCategories, double>> &results);
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        BuisnessPlanEvent();
        BuisnessPlanEvent(std::vector<Team> &teams);
        // Destructor:
        ~BuisnessPlanEvent();
        // Methods:
        virtual std::string get_file_info_name();
};

#endif
