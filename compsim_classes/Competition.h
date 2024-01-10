#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "Team.h"
#include "EventSimulatorInterface.h"

#include "constants.h"
#include <compsim_enums/enums.h>

#include <string>

using EventSimulatorPtr = std::shared_ptr<EventSimulatorInterface>;

class Competition
{
    private:
      std::vector<Team> m_teams;
      std::vector<EventType> m_events;
      EventSimulatorPtr event_simulator_;
      std::map<EventType, std::map<std::string, double>> m_events_and_teams_points;
      std::map<EventType, std::vector<std::pair<std::string, double>>> m_events_and_classifications;
      std::map<std::string, double> m_teams_and_comp_points;
      std::vector< std::pair<std::string, double> > m_comp_classification;

    public:
      Competition(EventSimulatorPtr event_simulator): event_simulator_(event_simulator) {}
      Competition(EventSimulatorPtr event_simulator, std::vector<Team> &teams, std::vector<EventType> &events);
      std::vector<Team> get_teams() const {return m_teams;}
      std::map<EventType, std::map<std::string, double>> get_events_and_teams_points() const {return m_events_and_teams_points;}
      std::map<EventType, std::vector<std::pair<std::string, double>>> get_events_classifications() const {return m_events_and_classifications;}
      std::vector< std::pair<std::string, double> > get_final_classification() const {return m_comp_classification;}
      void set_teams(std::vector<Team> &teams);
      void set_events(std::vector<EventType> &events);
      void create_classification();

    private:
      void simulate();
};
