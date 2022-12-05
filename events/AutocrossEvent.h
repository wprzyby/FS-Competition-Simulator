#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "constants.h"

#include <compsim_classes/event_base.h>


class AutocrossEvent : public DynamicEvent  // AutocrossEvent class that inherits from the abstract class Event
{
    public:
      AutocrossEvent() {init_event_config();}
      AutocrossEvent(std::vector<Team> &teams): DynamicEvent(teams) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
};


class DCAutocrossEvent: public DynamicEvent {
    private:
      double m_t_max;

    public:
      DCAutocrossEvent(double time_6ms): m_t_max(time_6ms) {init_event_config();}
      DCAutocrossEvent(double time_6ms, std::vector<Team>& teams): DynamicEvent(teams), m_t_max(time_6ms) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
      std::map<Team, double> find_teams_best_times() override;

};