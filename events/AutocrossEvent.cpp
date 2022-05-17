#include <iostream>
#include <vector>
#include <map>

#include "AutocrossEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"


AutocrossEvent::AutocrossEvent()
{
    event_categories = AutEveCat;
    m_event_type = autocross;
}

AutocrossEvent::AutocrossEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
    event_categories = AutEveCat;
    m_event_type = autocross;
}

void AutocrossEvent::calculate_teams_points()
{
    std::map<Team, double> teams_and_best_times;
    double best_time = 0;

    for(auto& [team, team_results]: teams_and_results)
    {
        best_time = find_best_time_for_team(team_results);
        // teams_and_results[team][aut_best_time] = best_time; TODO: ??
        teams_and_best_times[team] = best_time;
    }

    double best_time_overall = find_best_time_overall(teams_and_best_times);
    double t_max = best_time_overall * 1.25;

    double team_final_score = 0;
    for(auto& [team, team_best_time]: teams_and_best_times)
    {
        // TODO: tutaj zakładam, że jeśli jest DNF albo DQ to jest czas ustawiany na 0
        // jeśli tak jednak nie będziemy robić, to to do zmiany
        if(team_best_time == 0)
        {
            team_final_score = 0;
        }
        else if(team_best_time < t_max)
        {
            team_final_score = 382 * ( (t_max / team_best_time) - 1 );
        }
        else
        {
            team_final_score = 4.5;
        }

        classification.insert({team, team_final_score});
    }

}

