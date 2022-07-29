#include <iostream>
#include <map>
#include <vector>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "AccelerationEvent.h"
#include "constants.h"


AccelerationEvent::AccelerationEvent(std::vector<Team> &teams, std::string which_driverless)
{
    m_which_driverless = which_driverless;
    m_teams_participating = teams;
    if (m_which_driverless == "DV")
    {
        m_event_type = acceleration_DV;
        m_event_categories = CATEGORY_LISTS.at(acceleration_DV);
    }
    else if (m_which_driverless == "DC")
    {
        m_event_type = acceleration_DC;
        m_event_categories = CATEGORY_LISTS.at(acceleration_DC);
    }
    else
    {
        m_event_type = acceleration;
        m_event_categories = CATEGORY_LISTS.at(acceleration_DC);
    }
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

    if ((m_event_type == acceleration) or (m_event_type == acceleration_DC))
    {
        for (auto& [team, team_best_time]: teams_and_best_times)
        {
            double team_final_score;

            if (team_best_time == 0)
            {
                team_final_score = 0;  // Case od DNF or DSQ
            }
            else if ((m_event_type == acceleration) and (team_best_time < 1.5*best_time_overall))  // FIXME: Split this
            {
                team_final_score = base_points + get_additional_points(best_time_overall, team_best_time);  // Calculating teams` final score in non - driverless.
            }
            else if ((m_event_type == acceleration_DC) and (team_best_time < 2*best_time_overall))
            {
                team_final_score = base_points + get_additional_points_DC(best_time_overall, team_best_time);
            }
            else
            {
                team_final_score = 3.5;
            }
            m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their final score to the classification.
        }
    }
    else  // TODO: Investigate if this works
    {
        int non_zero_times = count_non_zero_times(teams_and_best_times);  // Counting teams that were not DNFed or DSQed

        // Sorting the teams by their times
        for (auto& [team, team_best_time]: teams_and_best_times)
        {
            m_classification.insert({const_cast<Team&>(team), team_best_time});  // Inserting teams and their times to classification map
        }
        //

        int current_place = 1;
        std::map<Team, double> buffor_m_classification;  // creating buffor classification map
        make_event_classification();  // Sorting teams results by their times

        // Calculating points for every team
        for (auto& [team, team_best_time]: m_sorted_classification)
        {
            double team_final_score;
            if (team_best_time == 0)  // In case of only DNFs and only DSQs
            {
                team_final_score = 0;  // Team`s time is zero so the final score is zero
            }
            else
            {
                team_final_score = get_additional_points_DV(current_place, non_zero_times);  // Calculating team`s points according to the rules
            }
            buffor_m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});  // Inserting team and their points to buffor classification
            current_place++;  // Incrementing the current place
        }
        //

        m_classification = buffor_m_classification;  // Re-writing the m_classification atrribute (in order not to duplicate teams and their scores)
        m_sorted_classification.clear(); // Clearing the m_sorted_classification atrribute (as it doesn`t store points)

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


double AccelerationEvent::get_additional_points_DC(const double best_time_overall, const double team_best_time) const
{
    double points = 71.5*(2*(best_time_overall/team_best_time) - 1);  // calculating additional points

    if (points < 0)  // Checking if additional points are not negative
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}


double AccelerationEvent::get_additional_points_DV(int team_place, int non_zero_times) const
{
    double points = (75*(1 + non_zero_times - team_place))/non_zero_times;  // calculating additional points

    if (points <= 0)  // Checking if additional points are not negative or zero
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
