#pragma once
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class AutocrossEvent : public Event  // AutocrossEvent class that inherits from the abstract class Event
{
    private:
      double static get_additional_points(double best_time_overall, double team_best_time);

    protected:
      void fill_teams_points() override;  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
      AutocrossEvent() {init_event_type(autocross);}
      AutocrossEvent(std::vector<Team> &teams): Event(teams) {init_event_type(autocross);}
};


class DCAutocrossEvent: public Event {
    private:
      double m_t_max;

    protected:
      std::map<Team, double> find_teams_best_times() override;
      void fill_teams_points() override;

    public:
      DCAutocrossEvent(double time_6ms): m_t_max(time_6ms) {init_event_type(autocross_DC);}
      DCAutocrossEvent(double time_6ms, std::vector<Team>& teams): Event(teams), m_t_max(time_6ms) {init_event_type(autocross_DC);}

    private:
      double get_additional_points(double best_time_overall, double team_best_time);

};