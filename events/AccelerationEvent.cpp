#include <iostream>
#include <map>
#include <vector>

#include "AccelerationEvent.h"
#include "../base_classes/Team.h"

#include "../Event_tools.h"
#include "../constants.h"
#include "../enums/enums.h"
#include "../exceptions.h"


// TODO: sprawdzić czy to się da zrobić listą inicjalizacji
AccelerationEvent::AccelerationEvent(std::vector<Team> &teams)
{
    m_teams_participating = teams;
    m_event_type = acceleration;
    m_event_categories = category_lists.at(acceleration);
}

AccelerationEvent::AccelerationEvent()
{
    m_event_type = acceleration;
    m_event_categories = category_lists.at(acceleration);
}


void AccelerationEvent::calculate_teams_points()
{
    std::map<Team, double> teams_and_best_times;
    for (auto& [team, team_results]: m_teams_and_results)
    {
        double time_to_set = find_best_time_for_team(team_results);  // Finding best team`s time
        teams_and_best_times[team] = time_to_set;  // inserting team and their best result into the bufforing map.
    }

    double best_time_overall = find_best_time_overall(teams_and_best_times);  // Finding the best time overall
    double base_points = BASE_COMPLETION_POINTS.at(m_event_type);

    for (auto& [team, team_best_time]: teams_and_best_times)
    {
        double team_final_score;

        if (team_best_time == 0)
        {
            team_final_score = 0;  // Case od DNF or DSQ
        }
        else if (team_best_time < 1.5*best_time_overall)
        {
            team_final_score = base_points + get_additional_points(best_time_overall, team_best_time);  // Calculating teams` final score.
        }
        else
        {
            team_final_score = 3.5;
        }
        m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their final score to the classification.
    }
}


double AccelerationEvent::get_additional_points(const double best_time_overall, const double team_best_time) const
{
    double points = 93*(((1.5*best_time_overall)/team_best_time) - 1);  // calculating additional points

    if (points < 0)  // Checking if additional points are not negative
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}

// DONE
