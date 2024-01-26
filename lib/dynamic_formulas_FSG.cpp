#include "PointsCalculatorFSG.h"
#include <cmath>
#include <map>


double PointsCalculatorFSG::m_acceleration_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double p_max = 50;
    double base_points = p_max * 0.05;
    double t_max = best_time_overall * 1.5;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + p_max * 0.95 * ((t_max / t_team) - 1) / 0.5;
}

double PointsCalculatorFSG::dv_acceleration_points(const EventData& event_data, std::string team_name)
{
    double non_zero_times = event_data.at("non_zero_times");
    double team_place = event_data.at(team_name);

    double p_max = 75;
    if (team_place == 0) return 0.0;
    return p_max * (non_zero_times + 1 - team_place) / non_zero_times;
}


double PointsCalculatorFSG::dc_acceleration_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double p_max = 75;
    double base_points = p_max * 0.05;
    double t_max = best_time_overall * 2;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + p_max * 0.95 * ((t_max / t_team) - 1);
}


double PointsCalculatorFSG::m_autocross_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double p_max = 100;
    double base_points = p_max * 0.05;
    double t_max = best_time_overall * 1.25;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + p_max * 0.95 * ((t_max / t_team) - 1) / 0.25;
}


double PointsCalculatorFSG::dc_autocross_points(const EventData& event_data, std::string team_name)
{
    double t_min = event_data.at("best_time_overall");
    double t_max = event_data.at("t_6ms");
    double t_team_total = event_data.at(team_name);

    double p_max = 100;
    double base_points = p_max * 0.10;
    if (t_team_total == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team_total > t_max) return base_points;
    return base_points + 0.9 * p_max * (t_max - t_team_total) / (t_max - t_min);
}


double PointsCalculatorFSG::endurance_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double p_max = 250;
    double base_points = p_max * 0.10;
    double t_max = best_time_overall * 1.333;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + p_max * 0.90 * ((t_max / t_team) - 1) / 0.333;
}


double PointsCalculatorFSG::efficiency_points(const EventData& event_data, std::string team_name)
{
    double ef_min = event_data.at("best_eff_factor");
    double best_uncorr_time = event_data.at("best_uncorr_time");
    double ef_team = event_data.at("eff_factor_" + team_name);


    double p_max = 75;
    double ef_max = 1.5 * ef_min;
    if (event_data.at("uncorr_time_" + team_name) > 1.333 * best_uncorr_time) return 0.0;
    return p_max * (ef_max - ef_team) / (ef_max - ef_min);
}


double PointsCalculatorFSG::m_skidpad_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double p_max = 50.0;
    double base_points = p_max * 0.05;
    double t_max = best_time_overall * 1.25;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + p_max * 0.95 * (std::pow(t_max / t_team, 2) - 1) / 0.5625;
}


double PointsCalculatorFSG::dv_skidpad_points(const EventData& event_data, std::string team_name)
{
    double non_zero_times = event_data.at("non_zero_times");
    double team_place = event_data.at(team_name);

    double p_max = 75;
    if (team_place == 0) return 0.0;
    return p_max * (non_zero_times + 1 - team_place) / non_zero_times;
}


double PointsCalculatorFSG::dc_skidpad_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);

    double p_max = 75;
    double base_points = p_max * 0.05;
    double t_max = best_time_overall * 1.5;
    if (t_team == 0) return 0.0;    // time=0 means DNF/DQ
    if (t_team > t_max) return base_points;
    return base_points + 0.95 * p_max * (std::pow(t_max / t_team, 2) - 1) / 1.25;
}

double PointsCalculatorFSG::trackdrive_points(const EventData& event_data, std::string team_name)
{
    double best_time_overall = event_data.at("best_time_overall");
    double t_team = event_data.at(team_name);
    double team_laps = event_data.at("laps_" + team_name);


    double p_max = 200;
    double t_max = best_time_overall * 2;

    double lap_points = team_laps * 0.025 * p_max;
    if (t_team == 0) return lap_points;    // time=0 means DNF/DQ
    return lap_points + 0.75 * p_max * ((t_max / t_team) - 1);
}
