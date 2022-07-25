#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>



class AccelerationEvent : public Event  // AccelerationEvent class that inherits from the abstract class Event
{
    private:
        // Methods:
        double get_additional_points(double best_time_overall, double team_best_time) const;
        double get_additional_points_DC(const double best_time_overall, const double team_best_time) const;


    protected:
        // Methods:
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        AccelerationEvent();
        AccelerationEvent(std::vector<Team> &teams);
        // Destructor:
        ~AccelerationEvent() {};
};

