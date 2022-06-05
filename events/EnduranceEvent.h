#ifndef ENDURANCE_EVENT_H
#define ENDURANCE_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class EnduranceEvent : public Event  // EnduranceEvent class that inherits from the abstract class Event
{
    private:
        double get_endurance_points(double best_time_overall, double team_best_time) const;
        double get_efficiency_points(double best_eff_factor, double team_eff_factor) const;
        bool m_run_efficiency;
    protected:
        // Methods:
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        EnduranceEvent(bool run_efficiency=false);
        EnduranceEvent(std::vector<Team> &teams, bool run_efficiency=false);
        // Destructor:
        ~EnduranceEvent() {};
};

#endif

// DONE
