#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#include "SkidpadEvent.h"
#include "../base_classes/Team.h"

#include "../event_tools.h"
#include "../constants.h"
#include "../enums/enums.h"
#include "../exceptions.h"


SkidpadEvent::SkidpadEvent(std::vector<Team> &teams)
{
    m_teams_participating = teams;
    m_event_type = skidpad;
    m_event_categories = category_lists.at(skidpad);
}

SkidpadEvent::SkidpadEvent()
{
    m_event_type = skidpad;
    m_event_categories = category_lists.at(skidpad);
}


void SkidpadEvent::calculate_teams_points()
{
    std::map<Team, double> teams_and_best_times;
    for (auto& [team, team_results]: m_teams_and_results)
    {
        double first_time = round(0.5*(team_results[first_left_time] + team_results[first_right_time]));  // Calculating first run time with accuracy to miliseconds
        double second_time = round(0.5*(team_results[second_left_time] + team_results[second_right_time]));  // Calculating second run time with accuracy to miliseconds

        // Inserting team results into buffor map
        std::map<EventsCategories, double> times;
        times.insert({skid_first_time, first_time});
        times.insert({skid_second_time, second_time});
        //

        double time_to_set = find_best_time_for_team(times);  // Finding best team`s time
        teams_and_best_times[team] = time_to_set;  // inserting team and their best result into the map.
    }

    double best_time_overall = find_best_time_overall(teams_and_best_times);  // Finding the best time overall

    for (auto& [team, team_best_time]: teams_and_best_times)
    {
        double team_final_score;
        if (team_best_time == 0)  // In case of only DNFs and only DSQs
        {
            team_final_score = 0;
        }
        else if (team_best_time < 1.5*best_time_overall)  // Calculating every team score if time < 1.5 times best time
        {
            team_final_score = 3.5 + get_additional_points(best_time_overall, team_best_time);
        }
        else  // Team score if time >= 1.5 best time
        {
            team_final_score = 3.5;
        }
        m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their final score to the classification.
    }
}


double SkidpadEvent::get_additional_points(double best_time_overall, double team_best_time) const
{
    double points = (46.5*(pow((1.25*best_time_overall)/team_best_time, 2) - 1))/0.5625;  // calculating additional points

    if (points <= 0)  // Checking if additional points are not negative or zero
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}

// DONE
