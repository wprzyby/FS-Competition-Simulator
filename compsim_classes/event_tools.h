#pragma once

#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "constants.h"
#include <compsim_enums/enums.h>


double find_max(const double number1, const double number2);
double find_min(const double number1, const double number2);  // Function finding lower value among two numbers provided
double find_max_points(std::map<Team, std::map<EventsCategories, double>> teams_and_results);
double sum_all_teams_results(std::map<EventsCategories, double> results);
double find_best_time_for_team(std::map<EventsCategories, double> team_and_times);  // finds the best time among team`s results
double find_best_time_overall(std::map<Team, double> &teams_and_times);  // finds the best time among team`s best times
bool check_if_category_in_vector(EventsCategories const &category, std::vector<EventsCategories> const &categories_in_event);
bool compare(std::pair<EventsCategories, double> const &first_pair, std::pair<EventsCategories, double> const &second_pair);  // Returns true if variable of the type double is greater in the second vector
bool compare_teams(std::pair<Team, double> const &first_pair, std::pair<Team, double> const &second_pair);
double rd_to_n_places(double number, int n);  // rounds given number to n decimal places.
int count_non_zero_times(std::map<Team, double> &teams_and_best_times);  // Finding how many teams acheived non zero times
