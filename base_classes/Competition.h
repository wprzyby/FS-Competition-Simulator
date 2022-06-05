#ifndef COMPETITION_H
#define COMPETITION_H

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "../constants.h"
#include "Team.h"
#include "Event.h"

class Competition
{
    private:
        std::vector<std::unique_ptr<Event>> m_events;
        std::vector<Team> m_teams;
        std::map<EventType, std::map<Team, double>> m_events_points;
        std::map<Team, double> m_competition_points;
        std::vector< std::pair<Team, double> > m_final_classification;

        void simulate();

    public:
        Competition();

        // getters:
        //std::vector<std::unique_ptr<Event>> get_events() const {return m_events;}
        std::vector<Team> get_teams() const {return m_teams;}
        std::map<EventType, std::map<Team, double>> get_events_points() const {return m_events_points;}
        std::vector< std::pair<Team, double> > get_final_classification() const {return m_final_classification;}

        // setters:
        // (boolean returns to communicate whether the setter succeeded or failed)
        bool set_events(std::vector<std::unique_ptr<Event>> events);
        bool set_teams(std::vector<Team> teams);

        // essential competition functionality:
        void create_classification();
};




#endif