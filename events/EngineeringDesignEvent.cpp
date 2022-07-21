#include <iostream>
#include <map>
#include <vector>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "EngineeringDesignEvent.h"
#include "constants.h"



EngineeringDesignEvent::EngineeringDesignEvent(std::vector<Team> &teams)
{
    m_teams_participating = teams;
    m_event_type = engineering_design;
    m_event_categories = CATEGORY_LISTS.at(engineering_design);
}

EngineeringDesignEvent::EngineeringDesignEvent()
{
    m_event_type = engineering_design;
    m_event_categories = CATEGORY_LISTS.at(engineering_design);
}


void EngineeringDesignEvent::calculate_teams_points()
{
    // Calculating teams points and adding them to the classification map:
    for (auto& [team, results]: m_teams_and_results)
    {
        const double team_points = sum_all_teams_results(results);  // summing all team`s point
        m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_points, 1)});  // inserting team and their final result into classification
    }
}
