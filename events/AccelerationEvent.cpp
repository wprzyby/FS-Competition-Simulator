#include <iostream>
#include <map>
#include <vector>
#include "AccelerationEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"
#include "../exceptions.h"


AccelerationEvent::AccelerationEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
    event_categories = AccEveCat;
    m_event_type = acceleration;
}
AccelerationEvent::AccelerationEvent()
{
    event_categories = AccEveCat;  // TODO: rewrite according to AutocrossEvent
}
AccelerationEvent::~AccelerationEvent(){}


void AccelerationEvent::calculate_teams_points()
{
    std::map<Team, double> teams_and_best_times;
    for (auto& [team, team_results]: teams_and_results)
    {
        double time_to_set = find_best_time_for_team(team_results);  // Finding best team`s time
        teams_and_best_times[team] = time_to_set;  // inserting team and their best result into the bufforing map.
    }

    double best_time_overall = find_best_time_overall(teams_and_best_times);  // Finding the best time overall

    for (auto& [team, team_best_time]: teams_and_best_times)
    {
        double team_final_score;
        if (team_best_time == 0)
        {
            team_final_score = 0;
        }
        else if (team_best_time < 1.5*best_time_overall)
        {
            team_final_score = 3.5 + 93*(((1.5*best_time_overall)/team_best_time) - 1);  // Calculating teams` final score.
        }
        else
        {
            team_final_score = 3.5;
        }
        classification.insert({team, team_final_score});  // Inserting team and their final score to the classification.
    }
}


std::string AccelerationEvent::get_file_info_name()
{
    std::string name = "AccelerationEventInfo.pdf";
    return name;
}


double AccelerationEvent::get_additional_points(double best_time_overall, double team_best_time) const
{
    double points = 93*(((1.5*best_time_overall)/team_best_time) - 1);  // calculating additional points

    if (points < 0)  // Checking if additional points are not negative
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}

// DONE | Wzorzec dla dynamicznych
