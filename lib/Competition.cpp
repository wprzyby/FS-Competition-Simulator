#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>
#include <cmath>

#include "Competition.h"
#include "Team.h"
#include "event_tools.h"

#include "constants.h"
#include "exceptions.h"
#include "enums.h"


Competition::Competition(EventSimulatorPtr event_simulator, std::vector<Team> &teams, std::vector<EventType> &events)
                        : event_simulator_(event_simulator)
{
    set_teams(teams);
    set_events(events);
}


void Competition::set_events(std::vector<EventType> &events)
{
    m_events = events;
}


void Competition::set_teams(std::vector<Team> &teams)
{
    m_teams = teams;
}


void Competition::simulate()
{
    m_events_and_teams_points.clear();
    m_events_and_classifications.clear();

    for(auto& event: m_events)
    {
        EventResults results = event_simulator_->simulate_event(event, m_teams);
        m_events_and_teams_points[event] = results;
    }
}


void Competition::create_classification()
{
    m_comp_classification.clear();
    m_teams_and_comp_points.clear();
    simulate();

    // summing points from each event for every team to obtain total competition points
    for(auto& [_, event_points]: m_events_and_teams_points)
        {
            for(auto& [team, points]: event_points)
            {
                m_teams_and_comp_points[team] += points;
            }
        }

    // assigning final points to teams, adding {team, total_points} pair to final classification
    for(auto& team: m_teams)
    {
        m_comp_classification.push_back({team.name(), m_teams_and_comp_points.at(team.name())});
    }

    // sorting the final classification by team's points in descending order
    auto is_team_better = [](std::pair<std::string, double> pair1, std::pair<std::string, double> pair2)
    {
        return pair1.second > pair2.second;
    };
    std::sort(m_comp_classification.begin(), m_comp_classification.end(), is_team_better);

}


