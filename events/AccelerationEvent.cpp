#include <iostream>
#include <map>
#include <vector>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "AccelerationEvent.h"
#include "constants.h"

// MANUAL VERSION:
void AccelerationEvent::init_event_config()  {
    m_event_type = acceleration;
    m_name = "Acceleration Event (manual)";
    m_event_categories = CATEGORY_LISTS.at(acceleration);
    m_base_points = 3.5;
    m_time_threshold_coefficient = 1.5;
}

double AccelerationEvent::get_additional_points(const double best_time_overall, const double team_best_time) const
{
    double points = 93*(((1.5*best_time_overall)/team_best_time) - 1);  // calculating additional points

    if (points < 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
//-----------------------------


// DC VERSION:
void DCAccelerationEvent::init_event_config()  {
    m_event_type = acceleration_DC;
    m_name = "Acceleration Event (DC)";
    m_event_categories = CATEGORY_LISTS.at(acceleration_DC);
    m_base_points = 3.5;
    m_time_threshold_coefficient = 2;
}

double DCAccelerationEvent::get_additional_points(double best_time_overall, double team_best_time) const {
    double points = 71.5*(2*(best_time_overall/team_best_time) - 1);  // calculating additional points
    if (points < 0) {
        throw NegativeAdditionalPointsError();
    }
    return points;
}
//-----------------------------


// DV VERSION:
void DVAccelerationEvent::init_event_config() {
    m_event_type = acceleration_DV;
    m_name = "Acceleration Event (DV)";
    m_event_categories = CATEGORY_LISTS.at(acceleration_DV);
    m_base_points = 0;
    m_time_threshold_coefficient = 0;
}

void DVAccelerationEvent::basic_points_filling() {

    std::map<Team, double> teams_and_best_times = find_teams_best_times();
    int non_zero_times = count_non_zero_times(teams_and_best_times);  // Counting teams that were not DNFed or DSQed
    int current_place = 1;
    std::vector<std::pair<Team, double>> sorted_teams_and_times = sort_teams_and_points(teams_and_best_times, false);

    // Calculating points for every team
    for (auto& [team, team_best_time]: sorted_teams_and_times)
    {
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

double DVAccelerationEvent::get_additional_points(int team_place, int non_zero_times) const {

    double points = (75*(1 + non_zero_times - team_place))/static_cast<double>(non_zero_times);  // calculating additional points

    if (points <= 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
//-----------------------------