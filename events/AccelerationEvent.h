#pragma once

#include <map>
#include <vector>
#include <iostream>
#include "compsim_classes/Event.h"
#include "constants.h"

#include <compsim_classes/event_base.h>



class AccelerationEvent : public Event  // AccelerationEvent class that inherits from the abstract class Event
{
    private:
      static double get_additional_points(double best_time_overall, double team_best_time);
      double get_additional_points_DC(const double best_time_overall, const double team_best_time) const;
      double get_additional_points_DV(int team_place, int non_zero_times) const;

    protected:
      void calculate_teams_points() override;  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
      AccelerationEvent() {init_event_type(acceleration);}
      AccelerationEvent(std::vector<Team> &teams) : Event(teams) {init_event_type(acceleration);}
      ~AccelerationEvent() {}
};

class DCAccelerationEvent : public Event
{
    private:
      double static get_additional_points(double best_time_overall, double team_best_time);
    protected:
      void calculate_teams_points() override;
    public:
      DCAccelerationEvent() {init_event_type(acceleration_DC);}
      DCAccelerationEvent(std::vector<Team> &teams) : Event(teams) {init_event_type(acceleration_DC);}
};

class DVAccelerationEvent : public Event
{
    private:
      double get_additional_points(int team_place, int non_zero_times) const;
    protected:
      void calculate_teams_points() override;
    public:
      DVAccelerationEvent() {init_event_type(acceleration_DV);}
      DVAccelerationEvent(std::vector<Team> &teams) : Event(teams) {init_event_type(acceleration_DV);}
};