#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include "SkidpadEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"


SkidpadEvent::SkidpadEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
    event_categories = SkidEveCat;
}
SkidpadEvent::SkidpadEvent()
{
    event_categories = SkidEveCat;
}
SkidpadEvent::~SkidpadEvent(){}


void SkidpadEvent::calculate_teams_points()
{
    std::map<Team, double> teams_and_best_times;
    for (auto& [team, team_results]: teams_and_results)
    {
        double time_to_set = find_best_time_for_team(team_results);  // Finding best team`s time
        teams_and_results[team][acc_best_time] = time_to_set;  // Inserting team`s best time to the attribute
        teams_and_best_times[team] = time_to_set;  // inserting team and their best result into the map.
    }
    double best_time_overall = find_best_time_overall(teams_and_best_times);  // Finding the best time overall
    for (auto& [team, team_best_time]: teams_and_best_times)
    {
        double team_final_score = (46.5*(pow((1.25*best_time_overall)/team_best_time, 2) - 1))/0.5625;  // Calculating every team score
        classification.insert({team, team_final_score});  // Inserting team and their final score to the classification.
    }
}


std::string SkidpadEvent::get_file_info_name()
{
    std::string name = "SkidpadEventInfo.pdf";
    return name;
}

// DONE
