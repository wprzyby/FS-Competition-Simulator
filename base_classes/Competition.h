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
    // TODO: zobaczyć czy to w ogóle używam
    std::map<event_type, std::map<Team, double>> m_events_points;
    std::map<Team, unsigned> m_competition_points;

    public:
    Competition();

    // getters:
    std::vector<std::unique_ptr<Event>> get_events() const {return m_events;}
    std::vector<Team> get_teams() const {return m_teams;}
    std::map<event_type, std::map<Team, double>> get_events_points() const {return m_events_points;}
    std::map<Team, double> get_competition_results() const;

    // setters:
    // (boolean returns to communicate whether the setter succeeded or failed)
    bool set_events(std::vector<std::unique_ptr<Event>> events);
    bool set_teams(std::vector<Team> teams);

    // essential competition functionality:
    void simulate_competition();
    void create_classification();
    void show_classification();
    // classification - wektor par drużyna-wynik, posortowany od najwyższego wyniku do najniższego
};




#endif