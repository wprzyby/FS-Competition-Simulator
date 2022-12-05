#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "TrackdriveEvent.h"
#include "constants.h"

void TrackdriveEvent::init_event_config() {
    m_event_type = trackdrive;
    m_name = "Trackdrive Event";
    m_event_categories = CATEGORY_LISTS.at(trackdrive);
    m_base_points = 0;
    m_time_threshold_coefficient = 2;
}


std::map<Team, double> TrackdriveEvent::find_teams_best_times() {
    std::map<Team, double> teams_and_best_times;
    for (auto& team: m_teams) {
        teams_and_best_times[team] = team.result_of_category(tra_time);
    }
    return teams_and_best_times;
}


void TrackdriveEvent::additional_points_filling() {
    for (auto& team: m_teams) {
        double number_of_laps = team.result_of_category(tra_laps);
        double points_to_add = number_of_laps * m_points_per_lap;
        m_teams_and_points[team] += points_to_add;
    }
}


double TrackdriveEvent::get_additional_points(double best_time_overall, double team_best_time) const {
    double points = 150*(((best_time_overall*2/team_best_time) - 1));

    if (points <= 0) {
        throw NegativeAdditionalPointsError();
    }

    return points;
}