#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "Team.h"
#include "Event.h"

#include "constants.h"
#include <compsim_enums/enums.h>

#include <string>

class Competition
{
    public:
      const static std::vector<EventCategory> BUSINESSPLAN_EVENT_CATEGORIES;
      const static std::vector<EventCategory> COST_AND_MANUFACTURING_EVENT_CATEGORIES;
      const static std::vector<EventCategory> ENGINEERING_DESIGN_EVENT_CATEGORIES;
      const static std::vector<EventCategory> DC_ENGINEERING_DESIGN_EVENT_CATEGORIES;
      const static std::vector<EventCategory> SKIDPAD_EVENT_CATEGORIES;
      const static std::vector<EventCategory> ACCELERATION_EVENT_CATEGORIES;
      const static std::vector<EventCategory> AUTOCROSS_EVENT_CATEGORIES;
      const static std::vector<EventCategory> DC_AUTOCROSS_EVENT_CATEGORIES;
      const static std::vector<EventCategory> ENDURANCE_EVENT_CATEGORIES;
      const static std::vector<EventCategory> TRACKDRIVE_EVENT_CATEGORIES;
    private:
      std::vector<Team> m_teams;
      std::vector<EventType> m_events;
      std::map<EventType, std::map<std::string, double>> m_events_and_teams_points;
      std::map<EventType, std::vector<std::pair<std::string, double>>> m_events_and_classifications;
      std::map<std::string, double> m_teams_and_comp_points;
      std::vector< std::pair<std::string, double> > m_comp_classification;

    public:
      Competition() {};
      Competition(std::vector<Team> &teams, std::vector<EventType> &events);
      std::vector<Team> get_teams() const {return m_teams;}
      std::map<EventType, std::map<std::string, double>> get_events_and_teams_points() const {return m_events_and_teams_points;}
      std::map<EventType, std::vector<std::pair<std::string, double>>> get_events_classifications() const {return m_events_and_classifications;}
      std::vector< std::pair<std::string, double> > get_final_classification() const {return m_comp_classification;}
      void set_teams(std::vector<Team> &teams);
      void set_events(std::vector<EventType> &events);
      void create_classification();

    private:
      void simulate();

      std::map<std::string, double> preprocessing_standard(std::vector<EventCategory> categories);
      std::map<std::string, double> preprocessing_ranks_based(std::vector<EventCategory> categories);
      std::map<std::string, double> preprocessing_dc_autocross();
      std::map<std::string, double> preprocessing_efficiency();
      std::map<std::string, double> preprocessing_skidpad(bool is_ranks_based);

      void simulate_m_acceleration();
      void simulate_dv_acceleration();
      void simulate_dc_acceleration();
      void simulate_m_autocross();
      void simulate_dc_autocross();
      void simulate_endurance();
      void simulate_efficiency();
      void simulate_m_skidpad();
      void simulate_dv_skidpad();
      void simulate_dc_skidpad();
      void simulate_trackdrive();

      void simulate_engineering_design();
      void simulate_dc_engineering_design();
      void simulate_businessplan();
      void simulate_cost_and_manufacturing();
};
