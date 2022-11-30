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
      std::map<Team, double> find_teams_best_times() override;
      void fill_teams_points() override;

    public:
      TrackdriveEvent(): Event() {init_event_type(trackdrive);}
      TrackdriveEvent(std::vector<Team> &teams): Event(teams) {init_event_type(trackdrive);}
};

