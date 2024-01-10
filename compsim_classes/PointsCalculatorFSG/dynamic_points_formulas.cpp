#include "PointsCalculatorFSG.h"
#include <cmath>


double PointsCalculatorFSG::m_acceleration_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double team_best_time = event_data.at("team_best_time");
    double base_points = 2.5;
    double t_max = best_time_overall * 1.5;
    if (team_best_time == 0) return 0.0;    // time=0 means DNF/DQ
    if (team_best_time > t_max) return base_points;
    double points = base_points + 50 * 0.95 * ((t_max / team_best_time) - 1) / 0.5;
    return points;
}

double PointsCalculatorFSG::dv_acceleration_points(const EventData& event_data, std::string team_name)
{

}


double PointsCalculatorFSG::dc_acceleration_points(const EventData& event_data, std::string team_name)
{

}


double PointsCalculatorFSG::m_autocross_points(const EventData& event_data, std::string team_name)
{

}


double PointsCalculatorFSG::dc_autocross_points(const EventData& event_data, std::string team_name)
{

}


double PointsCalculatorFSG::endurance_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double team_best_time = event_data.at("team_best_time");

    double base_points = 250 * 0.1;
    double t_max = best_time_overall * 1.333;
    if (team_best_time == 0) return 0.0;    // time=0 means DNF/DQ
    if (team_best_time > t_max) return base_points;
    double points = base_points + 250 * 0.90 * ((t_max / team_best_time) - 1) / 0.333;
    return points;
}


double PointsCalculatorFSG::m_skidpad_points(const EventData& event_data, std::string team_name)
{

}


double PointsCalculatorFSG::dv_skidpad_points(const EventData& event_data, std::string team_name)
{

}


double PointsCalculatorFSG::dc_skidpad_points(const EventData& event_data, std::string team_name)
{

}