#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

#include "Event.h"
#include "Team.h"

#include "constants.h"
#include "events/constants.h"
#include "exceptions.h"
#include <compsim_enums/enums.h>
#include "event_tools.h"


void Event::init_event_type(EventType event_type) {
    m_event_type = event_type;
    m_event_categories = CATEGORY_LISTS.at(m_event_type);

}


void Event::set_results(std::map<Team, std::map<EventsCategories, double>> &results) {
    for (auto& [_, result]: results) {
        for(auto& [category, score]: result) {
            if (!is_category_in_vector(category, m_event_categories)) {
                throw NoSuchCategoryInTheEventError(category);
            }
        }
    }

    m_teams_and_results = results;
}


void Event::simulate() {
    calculate_teams_points();
    fill_sorted_classification();
}


std::map<Team, double> Event::find_teams_best_times() {
    std::map<Team, double> teams_and_best_times;
    for (auto& [team, team_results]: m_teams_and_results) {
        double time_to_set = find_best_time_for_team(team_results);  // Finding best team`s time
        teams_and_best_times[team] = time_to_set;  // inserting team and their best result into the bufforing map.
    }
    return teams_and_best_times;
}


void Event::fill_sorted_classification() {
    // creates classification in the form of a vector of [Team, points] pairs sorted according to points
    m_sorted_classification = sort_teams_and_points(m_classification, true);
}


void Event::fill_points_std_dynamic(double base_pts, double time_thresh_coefficient,
                                    std::map<Team, double>& teams_and_best_times,
                                    std::function<double(const double,const double)> pts_formula)
{
    /*
    Standard approach to calculating points in dynamic events in which the points of a team
    are based strictly on its best time and the overall best time.
    If a team's best time is below (overall_best_time * time_thresh_coefficient), then it gets additional points
    beyond the base points for completion. Those points are defined by the pts_formula
    */

    double best_time_overall = find_best_time_overall(teams_and_best_times);  // Finding the best time overall

    for (auto& [team, team_best_time]: teams_and_best_times) {
        double team_final_score;

        if (team_best_time == 0) {
            team_final_score = 0;  // Case of DNF or DSQ
        } else if (team_best_time < time_thresh_coefficient*best_time_overall) {
            team_final_score = base_pts + pts_formula(best_time_overall, team_best_time);  // Calculating teams` final score in non - driverless.
        } else {
            team_final_score = base_pts;
        }

        m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their final score to the classification.
    }
}