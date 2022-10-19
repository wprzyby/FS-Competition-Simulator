#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>

#include "SkidpadEvent.h"
#include "constants.h"

SkidpadEvent::SkidpadEvent(std::string which_driverless) : Event(which_driverless)
{
    if (m_which_driverless == "DV")
    {
        m_event_type = skidpad_DV;
        m_event_categories = CATEGORY_LISTS.at(skidpad_DV);
    }
    else if (m_which_driverless == "DC")
    {
        m_event_type = skidpad_DC;
        m_event_categories = CATEGORY_LISTS.at(skidpad_DC);
    }
    else
    {
        m_event_type = skidpad;
        m_event_categories = CATEGORY_LISTS.at(skidpad);
    }
    // TODO: tutaj się powtarza identyczny kod w obu konstruktorach, przemyśleć
}


SkidpadEvent::SkidpadEvent(std::vector<Team> &teams, std::string which_driverless) : Event(teams, which_driverless)
{
    if (m_which_driverless == "DV")
    {
        m_event_type = skidpad_DV;
        m_event_categories = CATEGORY_LISTS.at(skidpad_DV);
    }
    else if (m_which_driverless == "DC")
    {
        m_event_type = skidpad_DC;
        m_event_categories = CATEGORY_LISTS.at(skidpad_DC);
    }
    else
    {
        m_event_type = skidpad;
        m_event_categories = CATEGORY_LISTS.at(skidpad);
    }
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
    double base_points = BASE_COMPLETION_POINTS.at(m_event_type);

    if ((m_event_type == skidpad) or (m_event_type == skidpad_DC))
    {
        for (auto& [team, team_best_time]: teams_and_best_times)
        {
            double team_final_score;
            if (team_best_time == 0)  // In case of only DNFs and only DSQs
            {
                team_final_score = 0;
            }
            else if ((m_event_type == skidpad) and (team_best_time < 1.25*best_time_overall))  // Calculating every team score if time < 1.25 times best time (normal skidpad) ...
            {
                team_final_score = base_points + get_additional_points(best_time_overall, team_best_time);
            }
            else if ((m_event_type == skidpad_DC) and (team_best_time < 1.5*best_time_overall))  // ...  or < 1.5 times best time (DC skidpad)
            {
                team_final_score = base_points + get_additional_points_DC(best_time_overall, team_best_time);
            }
            else  // Team score if time >= 1.25 best time
            {
                team_final_score = base_points;
            }
            m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their final score to the classification.
        }
    }
    else  // TODO: Investigate if this works
    {
        int non_zero_times = count_non_zero_times(teams_and_best_times);  // Counting teams that were not DNFed or DSQed

        int current_place = 1;
        std::vector<std::pair<Team, double>> sorted_teams_and_times = sort_teams_and_points(teams_and_best_times, false);

        // Calculating points for every team
        for (auto& [team, team_best_time]: sorted_teams_and_times)
        {
            double team_final_score;
            if (team_best_time == 0)  // In case of only DNFs and only DSQs
            {
                team_final_score = 0;  // Team`s time is zero so the final score is zero
            }
            else
            {
                team_final_score = get_additional_points_DV(current_place, non_zero_times);  // Calculating team`s points according to the rules
                current_place++;  // Incrementing the current place
            }
            m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their points to buffor classification

        }
        //
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


double SkidpadEvent::get_additional_points_DC(double best_time_overall, double team_best_time) const
{
    double points = (71.5*(pow((1.5*best_time_overall)/team_best_time, 2) - 1))/1.25;  // calculating additional points

    if (points <= 0)  // Checking if additional points are not negative or zero
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}


double SkidpadEvent::get_additional_points_DV(int team_place, int non_zero_times) const
{
    double points = (75*(1 + non_zero_times - team_place))/static_cast<double>(non_zero_times);  // calculating additional points

    if (points <= 0)  // Checking if additional points are not negative or zero
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}


// DONE
