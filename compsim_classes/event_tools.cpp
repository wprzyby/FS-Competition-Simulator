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


double find_max_points(const std::vector<Team>& teams, const std::vector<EventCategory>& categories_to_count)
{
    double max_points = 0;
    for (auto& team: teams) {
        max_points = find_max(max_points, sum_team_results(team, categories_to_count));  // Finding biggest amount among max_points and current team`s points
    }
    return max_points;
}


double sum_team_results(const Team& team, const std::vector<EventCategory>& categories_to_count)
{
    double summed_points = 0;
    for (auto& category: categories_to_count)
    {
        summed_points += team.result_of_category(category);
    }
    return summed_points;
}

double find_best_time_for_team(const Team& team, const std::vector<EventCategory>& timed_categories)
{
    double best_time = team.result_of_category(timed_categories.at(0));
    for (auto& category: timed_categories) {
        best_time = find_min(team.result_of_category(category), best_time);
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


bool is_category_in_vector(EventCategory const &category, std::vector<EventCategory> const &categories_in_event)
{
    bool result = false;
    for (auto& category_in_event: categories_in_event)  // getting category from vector
    {
        if (category == category_in_event) {result = true; break;}  // if category is in the vector then result is true and the loop is broken
    }
    return result;
}


// bool compare(std::pair<EventsCategories, double> const &first_pair, std::pair<EventsCategories, double> const &second_pair)
// {
//     return first_pair.second < second_pair.second;
// }


bool better_team(std::pair<Team, double> const &first_pair, std::pair<Team, double> const &second_pair)
{
    return first_pair.second > second_pair.second;
}

bool worse_team(std::pair<Team, double> const &first_pair, std::pair<Team, double> const &second_pair)
{
    return first_pair.second < second_pair.second;
}


double rd_to_n_places(double number, int n)
{
    return round(number*pow(10, n))/pow(10, n);
}


int count_non_zero_times(std::map<Team, double> &teams_and_best_times)
{
    int counter = 0;
    for (auto& [team, time]: teams_and_best_times)
    {
        if (time != 0) {counter++;}
    }
    return counter;
}


std::vector<std::pair<Team, double>> sort_teams_and_points(std::map<Team, double> &map_to_sort, bool descending)
{
    // converts a Team to points map into a sorted vector of [Team, points] pairs
    std::vector<std::pair<Team, double>> teams_and_points_vector;

    for (auto& [team, points]: map_to_sort)
    {
        teams_and_points_vector.push_back({const_cast<Team&>(team), points});
    }

    if (descending)
    {
        std::sort(teams_and_points_vector.begin(), teams_and_points_vector.end(), better_team);
    }
    else
    {
        std::sort(teams_and_points_vector.begin(), teams_and_points_vector.end(), worse_team);
    }

    return teams_and_points_vector;
}
