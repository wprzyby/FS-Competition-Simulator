#include <iostream>
#include <vector>
#include <map>

#include "AutocrossEvent.h"
#include "../base_classes/Team.h"

#include "../Event_tools.h"
#include "../constants.h"
#include "../enums/enums.h"
#include "../exceptions.h"


AutocrossEvent::AutocrossEvent()
{
    m_event_type = autocross;
    m_event_categories = category_lists.at(autocross);
}

AutocrossEvent::AutocrossEvent(std::vector<Team> &teams)
{
    m_teams_participating = teams;
    m_event_type = autocross;
    m_event_categories = category_lists.at(autocross);
}


void AutocrossEvent::calculate_teams_points()
{
    std::map<Team, double> teams_and_best_times;

    for(auto& [team, team_results]: m_teams_and_results)
    {
        double best_time = find_best_time_for_team(team_results);
        teams_and_best_times[team] = best_time;
    }

    double best_time_overall = find_best_time_overall(teams_and_best_times);
    // TODO: wziąć to z constants.h i jeśli się powtarza w innych eventach to też
    double base_points = 4.5;

    for(auto& [team, team_best_time]: teams_and_best_times)
    {
        double team_final_score;
        if(team_best_time <= 0)
        {
            team_final_score = 0;
        }
        else if(team_best_time < best_time_overall * 1.25)
        {
            team_final_score = get_additional_points(best_time_overall, team_best_time) + base_points;
        }
        else
        {
            team_final_score = base_points;
        }

        m_classification.insert({const_cast<Team&>(team), rd_to_n_places(team_final_score, 1)});
    }

}


double AutocrossEvent::get_additional_points(double best_time_overall, double team_best_time) const
{
    double points = 95.5 * ( ( ( (best_time_overall * 1.25) / team_best_time) - 1 ) / 0.25 );

    if (points < 0)
    {
        throw NegativeAdditionalPointsError();
    }

    return points;

}
// DONE
