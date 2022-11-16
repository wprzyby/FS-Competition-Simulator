#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>



class TrackdriveEvent : public Event  // TrackdriveEvent class that inherits from the abstract class Event
{
    private:
      static double get_additional_points(double best_time_overall, double team_best_time);

    protected:
      void calculate_teams_points() override;  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
      TrackdriveEvent(): Event() {}
      TrackdriveEvent(std::vector<Team> &teams): Event(teams) {}
      ~TrackdriveEvent() {};
};

