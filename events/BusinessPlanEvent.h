#ifndef BUSINESS_PLAN_EVENT_H
#define BUSINESS_PLAN_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class BusinessPlanEvent : public Event  // BusinessEvent class that inherits from the abstract class Event
{
    private:
        // Methods:
        double get_points(double team_total_result, double max_points) const;


    protected:
        // Methods:
        // FIXME: adjust for the fixme below
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        // FIXME: add finalists and their scores to constructor call
        BusinessPlanEvent();
        BusinessPlanEvent(std::vector<Team> &teams);
        // Destructor:
        ~BusinessPlanEvent();
        // Methods:
        virtual std::string get_info_file_name();
};

#endif

// DONE
