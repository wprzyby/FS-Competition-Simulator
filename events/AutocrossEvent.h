#ifndef AUTOCROSS_EVENT_H
#define AUTOCROSS_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


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

#endif

// DONE
