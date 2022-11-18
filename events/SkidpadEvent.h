#pragma once

#include "compsim_enums/enums.h"
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class SkidpadEvent : public Event  // SkidpadEvent class that inherits from the abstract class Event
{
    private:
        double static get_additional_points(double best_time_overall, double team_best_time);
        // double get_additional_points_DC(double best_time_overall, double team_best_time) const;
        // double get_additional_points_DV(int team_place, int non_zero_times) const;

    protected:
        std::map<Team, double> find_teams_best_times() override;
        void fill_teams_points() override;  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
        SkidpadEvent() {init_event_type(skidpad);}
        SkidpadEvent(std::vector<Team> &teams): Event(teams) {init_event_type(skidpad);}
};


class DVSkidpadEvent: public SkidpadEvent {
    private:
      double static get_additional_points(int team_place, int non_zero_times);

    protected:
      void fill_teams_points() override;

    public:
      DVSkidpadEvent() {init_event_type(skidpad_DV);}
      DVSkidpadEvent(std::vector<Team> &teams): SkidpadEvent(teams) {init_event_type(skidpad_DV);}
};

class DCSkidpadEvent: public SkidpadEvent {
    private:
      double static get_additional_points(double best_time_overall, double team_best_time);

    protected:
      void fill_teams_points() override;

    public:
      DCSkidpadEvent() {init_event_type(skidpad_DC);}
      DCSkidpadEvent(std::vector<Team> &teams): SkidpadEvent(teams) {init_event_type(skidpad_DC);}

};

