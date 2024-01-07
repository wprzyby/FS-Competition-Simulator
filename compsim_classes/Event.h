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
      bool m_is_dynamic;
      std::string m_name;
      std::vector<EventCategory> m_event_categories;
      std::vector<Team> m_teams;
      std::map<Team, double> m_teams_and_points;
      std::vector<std::pair<Team, double>> m_classification;

    public:
      Event() {}
      Event(std::vector<Team>& teams_participating): m_teams(teams_participating) {}
      virtual ~Event() {};

      std::map<Team, double> get_teams_and_points() const {return m_teams_and_points;}
      std::vector<std::pair<Team, double>> get_classification() const {return m_classification;}
      EventType get_event_type() const {return m_event_type;}
      std::string name() const {return m_name;}
      bool is_dynamic() const {return m_is_dynamic;}

      void init_event_type(EventType event_type);
      void set_teams(std::vector<Team> &teams) {m_teams = teams;}
      void simulate();

    protected:
      virtual void fill_teams_points()=0;
      void fill_classification();
};

// Order of calling out the methods:
// event.simulate();
// event.get_classification();
