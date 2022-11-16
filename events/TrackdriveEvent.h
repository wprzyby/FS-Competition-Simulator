#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>



class TrackdriveEvent : public Event
{
    private:
      static double get_additional_points(double best_time_overall, double team_best_time);

    protected:
      void fill_teams_points() override;  

    public:
      TrackdriveEvent(): Event() {}
      TrackdriveEvent(std::vector<Team> &teams): Event(teams) {}
};

