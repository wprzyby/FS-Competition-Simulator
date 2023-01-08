#include "tools.h"
#include "events/constants.h"
#include "qt_interface/constants.h"

std::vector<EventCategory> get_event_queries(EventType event_type) {
    if (event_type == endurance) {
        return ENDURANCE_INPUT_CATEGORIES;
    }

    return CATEGORY_LISTS.at(event_type);
}