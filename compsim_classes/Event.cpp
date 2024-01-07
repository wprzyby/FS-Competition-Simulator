#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

#include "Event.h"
#include "Team.h"

#include "constants.h"
#include "events/constants.h"
#include "exceptions.h"
#include <compsim_enums/enums.h>
#include "event_tools.h"


void Event::init_event_type(EventType event_type) {
    m_event_type = event_type;
    m_event_categories = CATEGORY_LISTS.at(m_event_type);
    m_name = EVENT_TYPE_TO_STRING.at(m_event_type);
}


void Event::simulate() {
    fill_teams_points();
    fill_classification();
}


void Event::fill_classification() {
    // creates classification in the form of a vector of [Team, points] pairs sorted according to points
    m_classification = sort_teams_and_points(m_teams_and_points, true);
}
