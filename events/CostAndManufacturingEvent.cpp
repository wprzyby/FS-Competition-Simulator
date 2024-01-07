#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "CostAndManufacturingEvent.h"
#include "constants.h"

void CostAndManufacturingEvent::init_event_config(unsigned int finalists, std::map<Team, double> points_to_set)  {
        m_event_type = cost_and_manufacturing;
        m_name = "Cost and Manufacturing Event";
        m_event_categories = CATEGORY_LISTS.at(cost_and_manufacturing);
        m_number_of_finalists = finalists;
        m_points_to_set = points_to_set;
}


double CostAndManufacturingEvent::get_points(double team_total_result, double max_points) const
{
    double points = 95*(team_total_result/max_points);  // calculating additional points

    if (points < 0)  // Checking if points are not negative
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
