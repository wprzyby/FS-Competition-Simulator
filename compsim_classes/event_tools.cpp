#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#include "constants.h"
#include "Team.h"
#include "event_tools.h"
#include <compsim_enums/enums.h>


double find_max(const double number1, const double number2)  // Function finding bigger value among two numbers provided
{
    if (number1 >= number2){return number1;}
    else {return number2;}
}


double find_min(const double number1, const double number2)  // Function finding lower value among two numbers provided
{
    // handling time=0 (in our convention this means DSQ/DNF/DNA)
    if (number1 == 0){return number2;}
    if (number2 == 0){return number1;}

    // no handling of negative times - inputting negative times not allowed
    if (number1 <= number2){return number1;}
    else {return number2;}
}


double find_max_points(std::map<Team, std::map<EventsCategories, double>> teams_and_results)
{
    double max_points = 0;
    for (auto& [_, results]: teams_and_results)
    {
        double team_points = sum_all_teams_results(results);  // Summing team`s points
        max_points = find_max(max_points, team_points);  // Finding biggest amount among max_points and current team`s points
    }
    return max_points;
}


double sum_all_teams_results(std::map<EventsCategories, double> results)
{
    double summed_points = 0;
    for (auto& [_, points]: results)  // Getting row in the map
    {
        summed_points += points;  // Summing all points in the map
    }
    return summed_points;  // Returning points scored in an event by  the team.
}


double find_best_time_for_team(std::map<EventsCategories, double> team_and_times)
{
    double best_time = team_and_times.begin()->second;  // getting first time as a refference
    for (auto& [_, time]: team_and_times)
    {
        best_time = find_min(time, best_time);  // finding lower value among current best and global best
    }
    return best_time;
}


double find_best_time_overall(std::map<Team, double> &teams_and_times)
{
    double best_time = teams_and_times.begin()->second;  // getting the first time as a refference
    for (auto& [_, time]: teams_and_times)
    {
        best_time = find_min(time, best_time);  // finding lower value among current best and global best
    }
    return best_time;
}


bool check_if_category_in_vector(EventsCategories const &category, std::vector<EventsCategories> const &categories_in_event)
{
    bool result = false;
    for (auto& category_in_event: categories_in_event)  // getting category from vector
    {
        if (category == category_in_event) {result = true; break;}  // if category is in the vector then result is true and the loop is broken
    }
    return result;
}


bool compare(std::pair<EventsCategories, double> const &first_pair, std::pair<EventsCategories, double> const &second_pair)
{
    return first_pair.second < second_pair.second;
}


bool compare_teams(std::pair<Team, double> const &first_pair, std::pair<Team, double> const &second_pair)
{
    return first_pair.second > second_pair.second;
}


double rd_to_n_places(double number, int n)
{
    return round(number*pow(10, n))/pow(10, n);
}