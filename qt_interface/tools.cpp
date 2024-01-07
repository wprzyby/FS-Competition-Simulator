#include "tools.h"
#include "compsim_enums/enums.h"
#include "events/constants.h"
#include "qt_interface/constants.h"

std::vector<EventCategory> get_event_queries(EventType event_type) {


    if (event_type == endurance) {
        return ENDURANCE_INPUT_CATEGORIES;
    }

    if (event_type == cost_and_manufacturing) {
        std::vector<EventCategory> ret_val={};
        ret_val = CATEGORY_LISTS.at(event_type);
        ret_val.push_back(cost_and_manufacturing_finals_score);
        return ret_val;
    }

    if (event_type == businessplan) {
        std::vector<EventCategory> ret_val={};
        ret_val = CATEGORY_LISTS.at(event_type);
        ret_val.push_back(businessplan_finals_score);
        return ret_val;
    }

    return CATEGORY_LISTS.at(event_type);
}