#pragma once

#include <map>
#include <vector>
#include <iostream>
#include "compsim_classes/constants.h"
#include "constants.h"

#include <compsim_classes/event_base.h>



class AccelerationEvent : public DynamicEvent  // AccelerationEvent class that inherits from the abstract class Event
{
    public:
      AccelerationEvent() {init_event_config();}
      AccelerationEvent(std::vector<Team> &teams) : DynamicEvent(teams) {init_event_config();}

     private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
};

class DCAccelerationEvent : public DynamicEvent
{
    public:
      DCAccelerationEvent() {init_event_config();}
      DCAccelerationEvent(std::vector<Team> &teams) : DynamicEvent(teams) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
};

class DVAccelerationEvent : public DynamicEvent
{
    public:
      DVAccelerationEvent() {init_event_config();}
      DVAccelerationEvent(std::vector<Team> &teams) : DynamicEvent(teams) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(int team_place, int non_zero_times) const override;
      void basic_points_filling() override;
};