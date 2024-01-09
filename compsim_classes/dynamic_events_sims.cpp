#include "Competition.h"
#include "dynamic_points_formulas.h"

/*
This section specifies what steps to take when simulating dynamic events.
For each event, a preprocessing step and points formula is defined.
For events using generic preprocessing functions, categories to process are additionally specified.
*/


void Competition::simulate_m_acceleration()
{
    std::vector<EventCategory> categories = Competition::ACCELERATION_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_standard(categories);
    for (auto& team: m_teams) {
        m_events_and_teams_points[acceleration][team.name()] = m_acceleration_points(event_data, team.name());
    }
}


void Competition::simulate_dc_acceleration()
{
    std::vector<EventCategory> categories = Competition::ACCELERATION_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_standard(categories);
    for (auto& team: m_teams) {
        m_events_and_teams_points[acceleration_DC][team.name()] = dc_acceleration_points(event_data, team.name());
    }
}


void Competition::simulate_dv_acceleration()
{
    std::vector<EventCategory> categories = Competition::ACCELERATION_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_ranks_based(categories);
    for (auto& team: m_teams) {
        m_events_and_teams_points[acceleration_DV][team.name()] = dv_acceleration_points(event_data, team.name());
    }
}


void Competition::simulate_m_autocross()
{
    std::vector<EventCategory> categories = Competition::AUTOCROSS_EVENT_CATEGORIES;
    std::map<std::string, double> event_data = preprocessing_standard(categories);
    for (auto& team: m_teams) {
        m_events_and_teams_points[autocross][team.name()] = m_autocross_points(event_data, team.name());
    }
}


void Competition::simulate_dc_autocross()
{
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_dc_autocross();
    for (auto& team: m_teams) {
        m_events_and_teams_points[autocross_DC][team.name()] = dc_autocross_points(event_data, team.name());
    }
}


void Competition::simulate_endurance()
{
    std::vector<EventCategory> categories = {end_corrected_time};   // special case, only category used in determining team's time
    std::map<std::string, double> event_data = preprocessing_standard(categories);
    for (auto& team: m_teams) {
        m_events_and_teams_points[endurance][team.name()] = endurance_points(event_data, team.name());
    }
}


void Competition::simulate_efficiency()
{
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_efficiency();
    for (auto& team: m_teams) {
        m_events_and_teams_points[efficiency][team.name()] = efficiency_points(event_data, team.name());
    }
}


void Competition::simulate_m_skidpad()
{
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_skidpad();
    for (auto& team: m_teams) {
        m_events_and_teams_points[skidpad][team.name()] = m_skidpad_points(event_data, team.name());
    }
}


void Competition::simulate_dc_skidpad()
{
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_skidpad();
    for (auto& team: m_teams) {
        m_events_and_teams_points[skidpad_DC][team.name()] = dc_skidpad_points(event_data, team.name());
    }
}


void Competition::simulate_dv_skidpad()
{
    // no categories because proprietary preprocessing determines categories
    std::map<std::string, double> event_data = preprocessing_skidpad_ranks_based();
    for (auto& team: m_teams) {
        m_events_and_teams_points[skidpad_DV][team.name()] = dv_skidpad_points(event_data, team.name());
    }
}
