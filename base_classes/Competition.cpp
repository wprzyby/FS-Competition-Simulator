#include <iostream>
#include <memory>


// FIXME: also relative imports
#include "Competition.h"
#include "../constants.h"
#include "Team.h"

Competition::Competition()
{
    m_events = {};
    m_teams = {};
    m_events_points = {};
}

bool Competition::set_events(std::vector<std::unique_ptr<Event>> events)
{
    // does this even work with pointers?
    // TODO: test this
    m_events = events;
    return true;
}

bool Competition::set_teams(std::vector<Team> teams)
{
    // no checking of validity of given argument as of now
    // TODO: checking if every team is unique?
    m_teams = teams;
    return true;
}

void Competition::simulate_competition()
{
    for(auto& event_ptr: m_events)
    {
        // TODO: does make_final_classification do everything?
        event_ptr->make_final_classification();
        std::map<Team, double> event_classification = event_ptr->get_classification();

        // TODO: implement attribute and getter for event type (assign through overridden constructor)
        event_type type = event_ptr->get_type();

        m_events_points[type] = event_classification;
    }
}

void Competition::create_classification()
{
    for(auto [_, event_points]: m_events_points)
        {
            for(auto [team, points]: event_points)
            {
                m_competition_points[team] = points;
            }
        }
}
