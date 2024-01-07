#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>
#include "constants.h"


class EnduranceEvent : public DynamicEvent  // EnduranceEvent class that inherits from the abstract class Event
{
    private:
      bool m_run_efficiency;

    public:
      EnduranceEvent(bool run_efficiency=false): m_run_efficiency(run_efficiency) {init_event_config();}
      EnduranceEvent(std::vector<Team> &teams, bool run_efficiency=false)
                    : DynamicEvent(teams), m_run_efficiency(run_efficiency) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
      std::map<Team, double> find_teams_best_times() override;
      void additional_points_filling() override;
      double get_efficiency_points(double best_eff_factor, double team_eff_factor) const;
};
