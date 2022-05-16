#ifndef AUTOCROSS_EVENT_H
#define AUTOCROSS_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class AutocrossEvent : public Event  // AutocrossEvent class that inherits from the abstract class Event
{
    protected:
        // Methods:
        virtual void set_results(std::map<Team, std::map<EventsCategories, double>> &results);  // Function to create teams_and_results map.
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        AutocrossEvent();
        AutocrossEvent(std::vector<Team> &teams);
        // Destructor:
        ~AutocrossEvent();
        // Methods
        virtual std::string get_file_info_name();
};

#endif
