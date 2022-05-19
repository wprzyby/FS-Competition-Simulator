#include <iostream>
#include <memory>
#include <algorithm>


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
    // FIXME: check if this assignment works
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

void Competition::simulate()
{
    for(auto& event_ptr: m_events)
    {
        event_ptr->simulate();
        std::map<Team, double> event_classification = event_ptr->get_classification();

        EventType type = event_ptr->get_event_type();

        m_events_points[type] = event_classification;
    }
}

void Competition::create_classification()
{
    simulate();

    // summing points from each event for every team to obtain total competition points
    for(auto& [_, event_points]: m_events_points)
        {
            for(auto& [team, points]: event_points)
            {
                m_competition_points[team] += points;
            }
        }

    // assigning final points to teams, adding {team, total_points} pair to final classification
    for(auto& team: m_teams)
    {
        team.set_total_points(m_competition_points[team]);
        m_final_classification.push_back( {team, team.get_total_points()} );
    }

    // sorting the final classification by team's points in descending order
    std::sort(m_final_classification.begin(), m_final_classification.end(), std::greater<Team>());

}