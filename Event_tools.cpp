#include <iostream>
#include <map>
#include <vector>
#include "constants.h"
#include "base_classes/Team.h"
#include "Event_tools.h"


double find_max(const double number1, const double number2)  // Function finding bigger value among two numbers provided
{
    if (number1 >= number2){return number1;}
    else {return number2;}
}


double find_max_points(std::map<Team, std::map<EventsCategories, double>> teams_and_results)
{
    double max_points = 0;
    for (auto& [team, results]: teams_and_results)
    {
        double team_points = sum_all_teams_results(results);  // Summing team`s points
        max_points = find_max(max_points, team_points);  // Finding biggest amount among max_points and current team`s points
    }
}


double sum_all_teams_results(std::map<EventsCategories, double> results)
{
    double summed_points = 0;
    for (auto& [category, points]: results)  // Getting row in the map
    {
        summed_points += points;  // Summing all points in the map
    }
    return summed_points;  // Returning points scored in an event by  the team.
}

// TODO: Implement two ast funstions from header file!
