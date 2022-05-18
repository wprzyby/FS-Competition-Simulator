#ifndef BUISNESS_PLAN_EVENT_H
#define BUISNESS_PLAN_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class BuisnessPlanEvent : public Event  // BuisnessEvent class that inherits from the abstract class Event
{
    private:
        // Methods:
        double get_points(double team_total_result, double max_points) const;


    protected:
        // Methods:
        virtual void calculate_teams_points(int finalists, std::map<Team, double> points_to_set);  // Function that calculates points for teams (based on the map: teams_and_results).


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

// DONE
