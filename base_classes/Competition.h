#ifndef COMPETITION_H
#define COMPETITION_H

#include <iostream>
#include <vector>
#include <memory>
#include <map>

// FIXME: using relative import, risky, better to change include path within IDE (?)
#include "../constants.h"
#include "Team.h"
#include "Event.h"

class Competition
{
    private:
        std::vector<std::unique_ptr<Event>> m_events;
        std::vector<Team> m_teams;
        std::map<event_type, std::map<Team, double>> m_events_points;
        std::map<Team, unsigned> m_competition_points;
        std::vector< std::pair<Team, double> > m_final_classification;

    public:
        Competition();

        // getters:
        std::vector<std::unique_ptr<Event>> get_events() const {return m_events;}
        std::vector<Team> get_teams() const {return m_teams;}
        std::map<event_type, std::map<Team, double>> get_events_points() const {return m_events_points;}
        std::vector< std::pair<Team, double> > get_final_classification() const {return m_final_classification;}

        // setters:
        // (boolean returns to communicate whether the setter succeeded or failed)
        bool set_events(std::vector<std::unique_ptr<Event>> events);
        bool set_teams(std::vector<Team> teams);

        // essential competition functionality:
        void simulate();
        void create_classification();
};




#endif