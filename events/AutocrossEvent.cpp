#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "AutocrossEvent.h"
#include "constants.h"

// MANUAL VERSION:
void AutocrossEvent::init_event_config()  {
    m_event_type = autocross;
    m_name = "Autocross Event (manual)";
    m_event_categories = CATEGORY_LISTS.at(autocross);
    m_base_points = 4.5;
    m_time_threshold_coefficient = 1.25;
}


double AutocrossEvent::get_additional_points(double best_time_overall, double team_best_time) const {
    double points = 95.5 * ( ( ( (best_time_overall * 1.25) / team_best_time) - 1 ) / 0.25 );
    if (points < 0) {
        throw NegativeAdditionalPointsError();
    }
    return points;
}
//-----------------------------

// DC VERSION:
void DCAutocrossEvent::init_event_config() {
    m_event_type = autocross;
    m_name = "Autocross Event (manual)";
    m_event_categories = CATEGORY_LISTS.at(autocross);
    m_base_points = 4.5;
    m_time_threshold_coefficient = 1.25;
    m_use_time_threshold = true;
}


std::map<Team, double> DCAutocrossEvent::find_teams_best_times() {
    std::map<Team, double> teams_and_best_times;
    for (auto& team: m_teams) {
        double first_time = team.result_of_category(first_aut_time);
        double second_time = team.result_of_category(second_aut_time);

        // DNFs in both runs result in not scoring base points
        // hence best time set to 0 as demonstration of DNF of whole event
        if (first_time == 0 && second_time == 0) {
            teams_and_best_times[team] = 0;
            continue;
        }

        // if DNF/DQ or time exceeded Tmax, the time for the run is set to Tmax
        if (first_time == 0 || first_time>m_t_max) {first_time = m_t_max;}
        if (second_time == 0 || second_time>m_t_max) {second_time = m_t_max;}

        double avg_time = (first_time + second_time) / 2;
        double time_to_set = std::min(first_time, avg_time);
        teams_and_best_times[team] = time_to_set;
    }
    return teams_and_best_times;
}


double DCAutocrossEvent::get_additional_points(double best_time_overall, double team_best_time) const {
    double points = 90 * ((m_t_max - team_best_time) / (m_t_max - best_time_overall));
    if (points <= 0) {
        throw NegativeAdditionalPointsError();
    }
    return points;

}