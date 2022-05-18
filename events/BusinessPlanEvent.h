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
        virtual void calculate_teams_points(int finalists, std::map<Team, double> points_to_set);  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        BusinessPlanEvent();
        BusinessPlanEvent(std::vector<Team> &teams);
        // Destructor:
        ~BusinessPlanEvent();
        // Methods:
        virtual std::string get_file_info_name();
};

#endif

// DONE
