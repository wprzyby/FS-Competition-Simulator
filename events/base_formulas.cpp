#include <map>
#include <string>
#include <cmath>

double acceleration_m_points(const std::map<std::string, double> event_data)
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

double acceleration_dv_points(const std::map<std::string, double> event_data)
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


double acceleration_dc_points(const std::map<std::string, double> event_data)
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


double autocross_m_points(const std::map<std::string, double> event_data)
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


double autocross_dc_points(const std::map<std::string, double> event_data)
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


double endurance_points(const std::map<std::string, double> event_data)
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


double m_skidpad_points(const std::map<std::string, double> event_data)
{
    double best_time_overall = event_data.at("best_time_overall");
    double team_best_time = event_data.at("team_best_time");
    double base_points = 2.5;
    double t_max = best_time_overall * 1.5;
    if (team_best_time == 0) return 0.0;    // time=0 means DNF/DQ
    if (team_best_time > t_max) return base_points;
    double points = base_points + 50 * 0.95 * (std::pow(t_max / team_best_time, 2) - 1) / 0.5625;
    return points;
}


double dv_skidpad_points(const std::map<std::string, double> event_data)
{
    int non_zero_times = event_data.at("non_zero_times");
    int team_place = event_data.at("team_place");
    double team_time_no_penalties = event_data.at("team_time_no_penalties");
    double base_points = 2.5;
    double t_max = best_time_overall * 1.5;
    if (team_time_no_penalties > 25000) return 0.0;    // time=0 means DNF/DQ
    if (team_best_time > t_max) return base_points;
    double points = base_points + 50 * 0.95 * (std::pow(t_max / team_best_time, 2) - 1) / 0.5625;
    return points;
}


double dc_skidpad_points(const std::map<std::string, double> event_data)
{
    double best_time_overall = event_data.at("best_time_overall");
    double team_best_time = event_data.at("team_best_time");
    double base_points = 3.75;
    double t_max = best_time_overall * 1.5;
    if (team_best_time == 0) return 0.0;    // time=0 means DNF/DQ
    if (team_best_time > t_max) return base_points;
    double points = base_points + 75 * 0.95 * (std::pow(t_max / team_best_time, 2) - 1) / 1.25;
    return points;
}