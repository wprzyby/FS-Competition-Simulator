#include <iostream>
#include <map>
#include <vector>
#include "BuisnessPlanEvent.h"
#include "Team.h"


BuisnessPlanEvent::virtual void create_teams_and_results_map()
{
    // Creating sophisticated map for this event:
    std::map<std::string, double> event_attributes;
    event_attributes.insert(std::pair<std::string, double> ("pitch_video", 0));
    event_attributes.insert(std::pair<std::string, double> ("novelty", 0));
    event_attributes.insert(std::pair<std::string, double> ("content", 0));
    event_attributes.insert(std::pair<std::string, double> ("finances", 0));
    event_attributes.insert(std::pair<std::string, double> ("deep_dive_topic", 0));
    event_attributes.insert(std::pair<std::string, double> ("demontration_and_structure", 0));
    event_attributes.insert(std::pair<std::string, double> ("delivery", 0));
    event_attributes.insert(std::pair<std::string, double> ("questions", 0));
    event_attributes.insert(std::pair<std::string, double> ("general_impression", 0));
    //

    // Inserting created map into the map with teams:
    for (int i = 0; i < teams_participating.size(); i++)
    {
        teams_and_results.insert(std::pair<Team, std::map<std::string, double>> (teams_participating[i], event_attributes));
    }
    //
}


BuisnessPlanEvent::virtual void calculate_teams_points()
{
    // Finding best result among all teams:
    const unsigned double max_points = find_max_points(teams_and_results);
    //

    // Calculating teams points and adding them to the classification map:
    for (itr = teams_and_results.begin(); itr != teams_and_results.end(); ++itr)
    {
        unsigned double team_total_result = sum_all_teams_results(itr);  // summing all team`s point
        unsigned double team_points = 70*(team_total_result/max_points);  // calculating team`s points based on the formula
        classification.insert(std::pair<Team, double> (teams_participating[i], team_points));  // inserting team and their final result into classification
    }
    //
}


BuisnessPlanEvent::virtual void open_info_file()
{

}