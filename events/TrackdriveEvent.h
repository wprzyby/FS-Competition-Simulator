#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>
#include "constants.h"

class TrackdriveEvent : public DynamicEvent
{
    private:
      double m_points_per_lap=5;

    public:
      TrackdriveEvent(): DynamicEvent() {init_event_config();}
      TrackdriveEvent(std::vector<Team> &teams): DynamicEvent(teams) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
      std::map<Team, double> find_teams_best_times() override;
      void additional_points_filling() override;
};

