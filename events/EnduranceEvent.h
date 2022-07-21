#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


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
