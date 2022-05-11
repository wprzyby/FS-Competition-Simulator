#include <iostream>
#include <map>
#include <vector>
#include "BuisnessPlanEvent.h"
#include "Team.h"
#include "Event_tools.h"


BuisnessPlanEvent::BuisnessPlanEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
}
BuisnessPlanEvent::BuisnessPlanEvent(){}


void Event::set_results(std::map<Team, std::map<std::string, double>> &results)
{
    enum keys_check {pitch_video, novelty, content, finances, deep_dive_topic, demontration_and_structure, delivery, questions, general_impression};
    for (auto& [team, inner_map]: results)
    {
        for (auto& [category, points]: inner_map)
        {
            if (category not in keys_check)  //TODO Fix the semantics of this line.
            {
                //TODO: Create an exception for this
            }
        }
    }
    teams_and_results = results;
}


void BuisnessPlanEvent::calculate_teams_points()
{
    // Finding best result among all teams:
    const double max_points = find_max_points(teams_and_results);
    //

    // Calculating teams points and adding them to the classification map:
    int i = 0;
    for (std::map<Team,std::map<std::string,double>>::iterator itr = teams_and_results.begin(); itr != teams_and_results.end(); ++itr)
    {
        const double team_total_result = sum_all_teams_results((*itr).second);  // summing all team`s point
        const double team_points = 70*(team_total_result/max_points);  // calculating team`s points based on the formula
        classification.insert({teams_participating[i], team_points});  // inserting team and their final result into classification
        i++;
    }
    //
}


std::string BuisnessPlanEvent::get_file_info_name()
{
    std::string name = "BuisnessPlanEventInfo.pdf";
    return name;
}
