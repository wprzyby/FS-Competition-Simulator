#include <iostream>
#include <map>
#include <vector>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "EngineeringDesignEvent.h"
#include "constants.h"


void EngineeringDesignEvent::init_event_config(unsigned int, std::map<Team, double>) {
    m_event_type = engineering_design;
        m_name = "Engineering Design Event";
        m_event_categories = CATEGORY_LISTS.at(engineering_design);
        m_number_of_finalists = 0;
        m_points_to_set = {};
}

void DCEngineeringDesignEvent::init_event_config(unsigned int, std::map<Team, double>) {
    m_event_type = engineering_design_DC;
        m_name = "Engineering Design Event (DC)";
        m_event_categories = CATEGORY_LISTS.at(engineering_design_DC);
        m_number_of_finalists = 0;
        m_points_to_set = {};
}
