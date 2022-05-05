#ifndef COMPETITION_H
#define COMPETITION_H

#include <iostream>
#include <vector>
#include <map>

// FIXME: using relative import, risky, better to change include path within IDE (?)
#include "../constants.h"
#include "Team.h"

class Competition
{
    private:
    std::vector<event_type> events;
    std::vector<Team> teams;
    std::map<event_type, std::map<Team, int>> event_results;

    public:
    Competition();

    // getters:
    std::vector<event_type> get_events();
    std::vector<Team> get_teams();
    std::map<event_type, std::map<Team, int>> get_results();

    // setters:
    // (boolean returns to communicate whether the setter succeeded or failed)
    bool set_events(std::vector<event_type> p_events);
    bool set_teams(std::vector<Team>);

    // essential competition functionality:
    void simulate_competition();
    void create_classification();
    void show_classification();
};




#endif