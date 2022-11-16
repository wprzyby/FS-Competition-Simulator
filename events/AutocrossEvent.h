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
      void calculate_teams_points() override;  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
      AutocrossEvent() {init_event_type(autocross);}
      AutocrossEvent(std::vector<Team> &teams): Event(teams) {init_event_type(autocross);}
      ~AutocrossEvent() {};
};
