#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "BusinessPlanEvent.h"
#include "constants.h"

void BusinessPlanEvent::init_event_config(unsigned int finalists, std::map<Team, double> points_to_set)  {
    m_event_type = businessplan;
    m_name = "Business Plan Event";
    m_event_categories = CATEGORY_LISTS.at(businessplan);
    m_number_of_finalists = finalists;
    m_points_to_set = points_to_set;
}


void BusinessPlanEvent::no_finals_points_filling() {
    const double max_points = find_max_points(m_teams, m_event_categories);

    for (auto& team: m_teams) {
        const double team_total_result = sum_team_results(team, m_event_categories);  // summing all team`s point
        const double team_points = get_points(team_total_result, max_points);  // calculating team`s points based on the formula
        m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_points, 1)});  // inserting team and their final result into classification
    }
}


double BusinessPlanEvent::get_points(double team_total_result, double max_points) const
{
    double points = 70*(team_total_result/max_points);  // calculating additional points

    if (points < 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
