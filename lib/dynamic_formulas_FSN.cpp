#include "PointsCalculatorFSN.h"
#include <cmath>

double PointsCalculatorFSN::m_acceleration_points(const EventData& event_data, std::string team_name) {
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double base_points = 3.5;
    double t_max = best_time_overall * 1.5;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return 3.5;
    return base_points + 71.5 * ((t_max / t_team) - 1) / 0.5;
}

double PointsCalculatorFSN::m_skidpad_points(const EventData& event_data, std::string team_name) {
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double base_points = 3.5;
    double t_max = best_time_overall * 1.25;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + 71.5 * (std::pow(t_max / t_team, 2) - 1) / 0.5625;
}

double PointsCalculatorFSN::endurance_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double base_points = 25;
    double t_max = best_time_overall * 1.333;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + 300 * ((t_max / t_team) - 1) / 0.333;
}