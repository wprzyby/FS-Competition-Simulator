#include <iostream>
#include <map>
#include <vector>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "EngineeringDesignEvent.h"
#include "constants.h"


void EngineeringDesignEvent::fill_teams_points()
{
    // Calculating teams points and adding them to the classification map:
    for (auto& [team, results]: m_teams_and_results)
    {
        const double team_points = sum_all_teams_results(results);  // summing all team`s point
        m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_points, 1)});  // inserting team and their final result into classification
    }
}
