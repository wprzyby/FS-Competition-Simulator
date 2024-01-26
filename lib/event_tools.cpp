#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Team.h"
#include "event_tools.h"
#include "enums.h"


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



double sum_results(const Team &team, std::vector<EventCategory> categories, std::vector<EventCategory> category_exclusions) {
    for (auto& exclusion: category_exclusions) {
        auto it = std::remove(categories.begin(), categories.end(), exclusion);
        categories.erase(it, categories.end());
    }

    double sum = 0;
    for (auto& category: categories) {
        sum += team.result_of_category(category);
    }
    return sum;
}


void sort_teams_and_best_times(std::vector<std::pair<std::string, double>> &teams_and_best_times) {

    // lambda function for sorting times which takes into account that time=0 is DNF/DQ, so the worst possible time
    auto is_time_better = [](std::pair<std::string, double> pair1, std::pair<std::string, double> pair2)
    {
        if (pair1.second == 0) return false;
        if (pair2.second == 0) return true;
        return pair1.second < pair2.second;
    };

    std::sort(teams_and_best_times.begin(), teams_and_best_times.end(), is_time_better);
}


double find_best_time_for_team(const Team& team, const std::vector<EventCategory>& timed_categories)
{
    double best_time = team.result_of_category(timed_categories.at(0));
    for (auto& category: timed_categories) {
        best_time = find_min(team.result_of_category(category), best_time);
    }
    return best_time;
}


double find_best_time_for_team_skidpad(const Team& team)
{
    double first_time = round(0.5*(team.result_of_category(first_skid_left_time) + team.result_of_category(first_skid_right_time)));
    double second_time = round(0.5*(team.result_of_category(second_skid_left_time) + team.result_of_category(second_skid_right_time)));
    return find_min(first_time, second_time);
}


double find_best_time_for_team_dc_autocross(const Team& team, const double t_6ms)
{
    double first_time = team.result_of_category(first_aut_time);
    double second_time = team.result_of_category(second_aut_time);

    // DNFs in both runs result in not scoring base points
    // hence best time set to 0 as demonstration of DNF of whole event
    if (first_time == 0 && second_time == 0) {
        return 0;
    }

    // if DNF/DQ or time exceeded time for driving the lap with 6m/s,
    // the time for the run is set to time for driving the lap with 6m/s
    if (first_time == 0 || first_time>t_6ms) {first_time = t_6ms;}
    if (second_time == 0 || second_time>t_6ms) {second_time = t_6ms;}

    double avg_time = (first_time + second_time) / 2;
    return std::min(first_time, avg_time);
}
