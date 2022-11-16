#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class EnduranceEvent : public Event  // EnduranceEvent class that inherits from the abstract class Event
{
    private:
      bool m_run_efficiency;

    protected:
      virtual void fill_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
      EnduranceEvent(bool run_efficiency=false): m_run_efficiency(run_efficiency) {init_event_type(endurance);}
      EnduranceEvent(std::vector<Team> &teams, bool run_efficiency=false)
                    : Event(teams), m_run_efficiency(run_efficiency) {init_event_type(endurance);}

    private:
      static double get_endurance_points(double best_time_overall, double team_best_time);
      static double get_efficiency_points(double best_eff_factor, double team_eff_factor);
};
