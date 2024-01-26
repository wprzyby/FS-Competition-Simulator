#include "PointsCalculatorFSG.h"

double PointsCalculatorFSG::get_points(EventType event_type, const EventData& event_data, std::string team_name) {
    double points;
    switch (event_type) {
        case acceleration:
            points = m_acceleration_points(event_data, team_name);
            break;
        case acceleration_DV:
            points = dv_acceleration_points(event_data, team_name);
            break;
        case acceleration_DC:
            points = dc_acceleration_points(event_data, team_name);
            break;
        case autocross:
            points = m_autocross_points(event_data, team_name);
            break;
        case autocross_DC:
            points = dc_autocross_points(event_data, team_name);
            break;
        case endurance:
            points = endurance_points(event_data, team_name);
            break;
        case efficiency:
            points = efficiency_points(event_data, team_name);
            break;
        case skidpad:
            points = m_skidpad_points(event_data, team_name);
            break;
        case skidpad_DV:
            points = dv_skidpad_points(event_data, team_name);
            break;
        case skidpad_DC:
            points = dc_skidpad_points(event_data, team_name);
            break;
        case trackdrive:
            points = trackdrive_points(event_data, team_name);
            break;
        case engineering_design:
            points = engineering_design_points(event_data, team_name);
            break;
        case engineering_design_DC:
            points = engineering_design_points(event_data, team_name);
            break;
        case businessplan:
            points = businessplan_points(event_data, team_name);
            break;
        case cost_and_manufacturing:
            points = cost_and_manufacturing_points(event_data, team_name);
            break;
        default:
            throw std::invalid_argument("Invalid event type chosen to simulate");
    }
    
    return points;
}