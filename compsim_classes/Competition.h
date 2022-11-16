#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "Team.h"
#include "Event.h"

#include "constants.h"
#include <compsim_enums/enums.h>

class Competition
{
    private:
      std::vector<Team> m_teams;
      std::vector<std::unique_ptr<Event>> m_events;
      std::map<EventType, std::map<Team, double>> m_events_and_teams_points;
      std::map<EventType, std::vector<std::pair<Team, double>>> m_events_and_classifications;
      std::map<Team, double> m_teams_and_comp_points;
      std::vector< std::pair<Team, double> > m_comp_classification;

    public:
      Competition() {};
      Competition(std::vector<Team> &teams, std::vector<std::unique_ptr<Event>> events);
      std::vector<Team> get_teams() const {return m_teams;}
      std::map<EventType, std::map<Team, double>> get_events_and_teams_points() const {return m_events_and_teams_points;}
      std::map<EventType, std::vector<std::pair<Team, double>>> get_events_classifications() const {return m_events_and_classifications;}
      std::vector< std::pair<Team, double> > get_final_classification() const {return m_comp_classification;}
      void set_teams(std::vector<Team> &teams);
      void create_classification();

    private:
      void simulate();
      void set_events(std::vector<std::unique_ptr<Event>> events);
};
