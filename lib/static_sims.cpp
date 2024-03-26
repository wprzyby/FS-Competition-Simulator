#include "EventSimulatorStandard.h"


EventResults EventSimulatorStandard::simulate_businessplan(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(businessplan);
    std::map<std::string, double> event_data = preprocessing_static_finals(teams, categories, businessplan_finals_score);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(businessplan, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_cost_and_manufacturing(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(cost_and_manufacturing);
    std::map<std::string, double> event_data = preprocessing_static_finals(teams, categories, cost_and_manufacturing_finals_score);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(cost_and_manufacturing, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_engineering_design(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(engineering_design);
    std::map<std::string, double> event_data = preprocessing_static_no_finals(teams, categories);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(engineering_design, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_dc_engineering_design(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(engineering_design_DC);
    std::map<std::string, double> event_data = preprocessing_static_no_finals(teams, categories);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(engineering_design_DC, event_data, team.name());
    }
    return results;
}


