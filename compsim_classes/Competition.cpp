#include <iostream>
#include <memory>
#include <algorithm>

#include "Competition.h"
#include "Team.h"

#include "event_tools.h"
#include "constants.h"
#include "exceptions.h"
#include <compsim_enums/enums.h>


Competition::Competition(std::vector<Team> &teams, std::vector<std::unique_ptr<Event>> events)
{
    set_teams(teams);
    set_events(std::move(events));
}


void Competition::set_events(std::vector<std::unique_ptr<Event>> events)
{
    m_events = std::move(events);
}


void Competition::set_teams(std::vector<Team> &teams)
{
    // Checking if all teams are unique
    // for (std::vector<Team>::iterator team = teams.begin(); team != teams.end(); ++team)
    // {
    //     std::vector<Team>::iterator other_team = team;
    //     other_team++;
    //     while(other_team != teams.end())
    //     {
    //         if (*team == *other_team){throw DuplicateTeamError();}
    //         other_team++;
    //     }
    // }

    m_teams = teams;
}


void Competition::simulate()
{
    for(auto& event_ptr: m_events)
    {
        event_ptr->simulate();
        std::map<Team, double> event_classification = event_ptr->get_teams_and_points();

        EventType type = event_ptr->get_event_type();

        m_events_and_teams_points[type] = event_classification;
        m_events_and_classifications[type] = event_ptr->get_classification();
    }
}


void Competition::create_classification()
{
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
        m_comp_classification.push_back({team, m_teams_and_comp_points.at(team)});
    }

    // sorting the final classification by team's points in descending order
    std::sort(m_comp_classification.begin(), m_comp_classification.end(), better_team);

}
