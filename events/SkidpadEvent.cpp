#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "SkidpadEvent.h"
#include "constants.h"

// FINDING BEST TIMES FOR BOTH SKIDPADS:
std::map<Team, double> SkidpadEventBase::find_teams_best_times() {

    std::map<Team, double> teams_and_best_times;
    for (auto& team: m_teams) {
        double first_time = round(0.5*(team.result_of_category(first_skid_left_time) + team.result_of_category(first_skid_right_time)));  // Calculating first run time with accuracy to miliseconds
        double second_time = round(0.5*(team.result_of_category(second_skid_left_time) + team.result_of_category(second_skid_right_time)));  // Calculating second run time with accuracy to miliseconds

        teams_and_best_times[team] = find_min(first_time, second_time);  // inserting team and their best result into the map.
    }
    return teams_and_best_times;
}
//-----------------------------

// MANUAL VERSION:
void SkidpadEvent::init_event_config()  {
    m_event_type = skidpad;
    m_name = "Skidpad Event (manual)";
    m_event_categories = CATEGORY_LISTS.at(skidpad);
    m_base_points = 3.5;
    m_time_threshold_coefficient = 1.25;
}

double SkidpadEvent::get_additional_points(double best_time_overall, double team_best_time) const
{
    double points = (46.5*(pow((1.25*best_time_overall)/team_best_time, 2) - 1))/0.5625;  // calculating additional points

    if (points <= 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
//-----------------------------

// DC VERSION:
void DCSkidpadEvent::init_event_config() {
    m_event_type = skidpad_DC;
    m_name = "Skidpad Event (DC)";
    m_event_categories = CATEGORY_LISTS.at(skidpad_DC);
    m_base_points = 3.5;
    m_time_threshold_coefficient = 1.5;
}

double DCSkidpadEvent::get_additional_points(double best_time_overall, double team_best_time) const
{
    double points = (71.5*(pow((1.5*best_time_overall)/team_best_time, 2) - 1))/1.25;  // calculating additional points

    if (points <= 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
//-----------------------------

// DV VERSION:
void DVSkidpadEvent::init_event_config() {
    m_event_type = skidpad_DV;
    m_name = "Skidpad Event (DV)";
    m_event_categories = CATEGORY_LISTS.at(skidpad_DV);
    m_base_points = 0;
    m_time_threshold_coefficient = 0;
}

void DVSkidpadEvent::basic_points_filling() {
    std::map<Team, double> teams_and_best_times = find_teams_best_times();
    int non_zero_times = count_non_zero_times(teams_and_best_times);  // Counting teams that were not DNFed or DSQed

    int current_place = 1;
    std::vector<std::pair<Team, double>> sorted_teams_and_times = sort_teams_and_points(teams_and_best_times, false);

    // Calculating points for every team
    for (auto& [team, team_best_time]: sorted_teams_and_times) {
        double team_final_score;
        if (team_best_time == 0) {
            team_final_score = 0;  // Team`s time is zero so the final score is zero
        } else {
            team_final_score = get_additional_points(current_place, non_zero_times);  // Calculating team`s points according to the rules
            current_place++;  // Incrementing the current place
        }

        m_teams_and_points.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their points to buffor classification
    }
}


double DVSkidpadEvent::get_additional_points(int team_place, int non_zero_times) const
{
    double points = (75*(1 + non_zero_times - team_place))/static_cast<double>(non_zero_times);  // calculating additional points

    if (points <= 0)  {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
//-----------------------------