#include "EventSimulatorStandard.h"

/*
This section specifies what steps to take when simulating dynamic events.
For each event, a preprocessing step and points formula is defined.
For events using generic preprocessing functions, categories to process are additionally specified.
*/


EventResults EventSimulatorStandard::simulate_m_acceleration(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(acceleration);
    std::map<std::string, double> event_data = preprocessing_standard(teams, categories);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(acceleration, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_dc_acceleration(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(acceleration_DC);
    std::map<std::string, double> event_data = preprocessing_standard(teams, categories);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(acceleration_DC, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_dv_acceleration(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(acceleration_DV);
    std::map<std::string, double> event_data = preprocessing_ranks_based(teams, categories);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(acceleration_DV, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_m_autocross(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = this->get_event_categories(autocross);
    std::map<std::string, double> event_data = preprocessing_standard(teams, categories);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(autocross, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_dc_autocross(const Teams& teams)
{
    EventResults results = {};
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_dc_autocross(teams);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(autocross_DC, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_endurance(const Teams& teams)
{
    EventResults results = {};
    std::vector<EventCategory> categories = {end_corrected_time};   // special case, only category used in determining team's time
    std::map<std::string, double> event_data = preprocessing_standard(teams, categories);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(endurance, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_efficiency(const Teams& teams)
{
    EventResults results = {};
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_efficiency(teams);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(efficiency, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_m_skidpad(const Teams& teams)
{
    EventResults results = {};
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_skidpad(teams);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(skidpad, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_dc_skidpad(const Teams& teams)
{
    EventResults results = {};
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_skidpad(teams);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(skidpad_DC, event_data, team.name());
    }
    return results;
}


EventResults EventSimulatorStandard::simulate_dv_skidpad(const Teams& teams)
{
    EventResults results = {};
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_skidpad_ranks_based(teams);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(skidpad_DV, event_data, team.name());
    }
    return results;
}

EventResults EventSimulatorStandard::simulate_trackdrive(const Teams& teams) {
    EventResults results = {};
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_trackdrive(teams);
    for (auto& team: teams) {
        results[team.name()] = points_calculator_->get_points(trackdrive, event_data, team.name());
    }
    return results;
}
