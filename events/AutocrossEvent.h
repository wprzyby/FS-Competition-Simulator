#pragma once
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class AutocrossEvent : public Event  // AutocrossEvent class that inherits from the abstract class Event
{
    private:
        // Methods:
        double get_additional_points(double best_time_overall, double team_best_time) const;


    protected:
        // Methods:
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).



    public:
        // Constructors:
        AutocrossEvent();
        AutocrossEvent(std::vector<Team> &teams);
        // Destructor:
        ~AutocrossEvent() {};
};
