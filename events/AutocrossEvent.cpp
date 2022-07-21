#include <iostream>
#include <vector>
#include <map>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "AutocrossEvent.h"
#include "constants.h"



AutocrossEvent::AutocrossEvent()
{
    m_event_type = autocross;
    m_event_categories = CATEGORY_LISTS.at(autocross);
}

AutocrossEvent::AutocrossEvent(std::vector<Team> &teams)
{
    m_teams_participating = teams;
    m_event_type = autocross;
    m_event_categories = CATEGORY_LISTS.at(autocross);
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
    double base_points = BASE_COMPLETION_POINTS.at(m_event_type);

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
