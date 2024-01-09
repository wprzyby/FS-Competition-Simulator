#pragma once

#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "constants.h"
#include <compsim_enums/enums.h>


double find_max(const double number1, const double number2);
double find_min(const double number1, const double number2);  // Function finding lower value among two numbers provided
double find_max_points(const std::vector<Team>& teams, const std::vector<EventCategory>& categories_to_count);
double sum_team_results(const Team& team, const std::vector<EventCategory>& categories_to_count);
double find_best_time_for_team(const Team& team, const std::vector<EventCategory>& timed_categories);
double find_best_time_overall(std::map<Team, double> &teams_and_times);  // finds the best time among team`s best times
bool is_category_in_vector(EventCategory const &category, std::vector<EventCategory> const &categories_in_event);
// bool compare(std::pair<EventsCategories, double> const &first_pair, std::pair<EventsCategories, double> const &second_pair);  // Returns true if variable of the type double is greater in the second vector
bool better_team(std::pair<Team, double> const &first_pair, std::pair<Team, double> const &second_pair);
bool worse_team(std::pair<Team, double> const &first_pair, std::pair<Team, double> const &second_pair);
double rd_to_n_places(double number, int n);  // rounds given number to n decimal places.
int count_non_zero_times(std::map<Team, double> &teams_and_best_times);  // Finding how many teams acheived non zero times
std::vector<std::pair<Team, double>> sort_teams_and_points(std::map<Team, double> &map_to_sort, bool descending=true);
double sum_results(const Team &team, std::vector<EventCategory> categories, std::vector<EventCategory> category_exclusions={});
void sort_teams_and_best_times(std::vector<std::pair<std::string, double>> &teams_and_best_times);
double find_best_time_for_team_skidpad(const Team& team);
double find_best_time_for_team_dc_autocross(const Team& team, const double t_6ms);
