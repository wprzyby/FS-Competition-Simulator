#include <iostream>
#include <map>
#include <vector>
#include "Event_tools.h"


double find_max(const double number1, const double number2)  // Function finding bigger value among two numbers provided
{
    if (number1 >= number2){return number1;}
    else {return number2;}
}


double find_max_points(std::map<Team,std::map<std::string,double>> &teams_and_results)
{
    double max_points = 0;
    for (std::map<Team,std::map<std::string,double>>::iterator itr = teams_and_results.begin(); itr != teams_and_results.end(); ++itr)
    {
        double team_points = sum_all_teams_results((*itr).second);  // Summing team`s points
        max_points = find_max(max_points, team_points);  // Finding biggest amount among max_points and current team`s points
    }
}


double sum_all_teams_results(std::map<std::string,double> results)
{
    double points = 0;
    for (std::map<std::string,double>::iterator itr = results.begin(); itr != results.end(); ++itr)  // Getting row in the map
    {
        points += itr->second;  // Summing all points in the map
    }
    return points;  // Returning points scored in an event by  the team.
}
