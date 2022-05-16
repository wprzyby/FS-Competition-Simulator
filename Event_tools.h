#ifndef EVENT_TOOLS_H
#define EVENT_TOOLS_H
#include <map>
#include <vector>
#include <iostream>
#include "base_classes/Team.h"
#include "base_classes/LapTime.h"
#include "constants.h"


double find_max(const double number1, const double number2);
double find_min(const double number1, const double number2);  // Function finding lower value among two numbers provided
double find_max_points(std::map<Team, std::map<EventsCategories, double>> teams_and_results);
double sum_all_teams_results(std::map<EventsCategories, double> results);
unsigned int find_best_time_for_team(std::map<EventsCategories, double> team_and_times);  // finds the best time among team`s results
unsigned int find_best_time_overall(std::map<Team, double> &teams_and_times);  // finds the best time among team`s best times
bool check_if_category_in_vector(EventsCategories category, std::vector<EventsCategories> categories_in_event);  // FIXME: Decide wheter this and other functions should be called out by reference?


#endif
