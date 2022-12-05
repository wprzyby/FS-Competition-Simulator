#pragma once

#include "compsim_classes/Event.h"
#include "compsim_enums/enums.h"
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>
#include "constants.h"

class SkidpadEventBase : public DynamicEvent {
    protected:
      std::map<Team, double> find_teams_best_times() override;

    public:
      SkidpadEventBase(): DynamicEvent() {}
      SkidpadEventBase(std::vector<Team> &teams): DynamicEvent(teams) {}
};


class SkidpadEvent : public SkidpadEventBase  // SkidpadEvent class that inherits from the abstract class Event
{
    public:
        SkidpadEvent() {init_event_config();}
        SkidpadEvent(std::vector<Team> &teams): SkidpadEventBase(teams) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
};

class DCSkidpadEvent: public SkidpadEventBase {
    public:
      DCSkidpadEvent() {init_event_config();}
      DCSkidpadEvent(std::vector<Team> &teams): SkidpadEventBase(teams) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(double best_time_overall, double team_best_time) const override;
};


class DVSkidpadEvent: public SkidpadEventBase {
    public:
      DVSkidpadEvent() {init_event_config();}
      DVSkidpadEvent(std::vector<Team> &teams): SkidpadEventBase(teams) {init_event_config();}

    private:
      void init_event_config() override;
      double get_additional_points(int team_place, int non_zero_times) const override;
      void basic_points_filling() override;
};


