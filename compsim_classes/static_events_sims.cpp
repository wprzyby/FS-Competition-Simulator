#include "Competition.h"
#include "static_points_formulas.h"

void Competition::simulate_businessplan()
{
    std::vector<EventCategory> categories = Competition::BUSINESSPLAN_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_static_finals(categories, businessplan_finals_score);
    for (auto& team: m_teams) {
        m_events_and_teams_points[businessplan][team.name()] = businessplan_points(event_data, team.name());
    }
}


void Competition::simulate_cost_and_manufacturing()
{
    std::vector<EventCategory> categories = Competition::COST_AND_MANUFACTURING_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_static_finals(categories, cost_and_manufacturing_finals_score);
    for (auto& team: m_teams) {
        m_events_and_teams_points[cost_and_manufacturing][team.name()] = cost_and_manufacturing_points(event_data, team.name());
    }
}


void Competition::simulate_engineering_design()
{
    std::vector<EventCategory> categories = Competition::ENGINEERING_DESIGN_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_static_no_finals(categories);
    for (auto& team: m_teams) {
        m_events_and_teams_points[engineering_design][team.name()] = engineering_design_points(event_data, team.name());
    }
}


void Competition::simulate_dc_engineering_design()
{
    std::vector<EventCategory> categories = Competition::DC_ENGINEERING_DESIGN_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_static_no_finals(categories);
    for (auto& team: m_teams) {
        m_events_and_teams_points[engineering_design_DC][team.name()] = engineering_design_points(event_data, team.name());
    }
}


