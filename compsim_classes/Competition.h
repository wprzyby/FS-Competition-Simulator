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
        std::vector<std::unique_ptr<Event>> m_events;
        std::vector<Team> m_teams;
        std::map<EventType, std::map<Team, double>> m_events_points;
        std::map<EventType, std::vector<std::pair<Team, double>>> m_final_events_classification;
        std::map<Team, double> m_competition_points;
        std::vector< std::pair<Team, double> > m_final_classification;

        void simulate();
        void set_events(std::vector<std::unique_ptr<Event>> events);


    public:
        Competition() {};
        Competition(std::vector<Team> &teams, std::vector<std::unique_ptr<Event>> events);

        // getters:
        std::vector<Team> get_teams() const {return m_teams;}
        std::map<EventType, std::map<Team, double>> get_events_points() const {return m_events_points;}
        std::map<EventType, std::vector<std::pair<Team, double>>> get_events_classification() const {return m_final_events_classification;}
        std::vector< std::pair<Team, double> > get_final_classification() const {return m_final_classification;}

        // setters:
        void set_teams(std::vector<Team> &teams);

        // essential competition functionality:
        void create_classification();
};
