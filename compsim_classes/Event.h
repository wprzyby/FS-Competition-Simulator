#pragma once

#include <map>
#include <iostream>
#include <vector>
#include <functional>

#include "Team.h"
#include "constants.h"
#include <compsim_enums/enums.h>



class Event  // Abstract class
{
    protected:
      EventType m_event_type;
      std::vector<EventsCategories> m_event_categories;
      std::vector<Team> m_teams_participating;
      std::map<Team, std::map<EventsCategories, double>> m_teams_and_results;
      std::map<Team, double> m_teams_and_points;
      std::vector<std::pair<Team, double>> m_classification;

    public:
      Event() {}
      Event(std::vector<Team>& teams_participating): m_teams_participating(teams_participating) {}
      virtual ~Event() {};

      void init_event_type(EventType event_type);
      void set_teams(std::vector<Team> &teams) {m_teams_participating = teams;}
      void set_results(std::map<Team, std::map<EventsCategories, double>> &results);
      void simulate();

      std::map<Team, double> get_teams_and_points() const {return m_teams_and_points;}
      std::vector<std::pair<Team, double>> get_classification() const {return m_classification;}
      EventType get_event_type() const {return m_event_type;}

    protected:
      virtual void fill_teams_points()=0;
      virtual std::map<Team, double> find_teams_best_times();
      void fill_classification();
      void fill_points_std_dynamic(double base_pts, double time_thresh_coefficient,
                                   std::map<Team, double>& teams_and_best_times,
                                   std::function<double(const double,const double)> pts_formula);
};

// Order of calling out the methods:
// event.set_results(results);
// event.simulate();
// event.get_classification();
