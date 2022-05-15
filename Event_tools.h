#ifndef EVENT_TOOLS_H
#define EVENT_TOOLS_H
#include <map>
#include <vector>
#include <iostream>
#include "Team.h"
#include "LapTime.h"
#include "constants.h"


double find_max(const double number1, const double number2);
double find_max_points(std::map<Team, std::map<EventsCategories, double>> teams_and_results);
double sum_all_teams_results(std::map<EventsCategories, double> results);
unsigned int find_best_time_for_team(std::map<EventsCategories, double> results);  // Here only times with included penalties should be given! Best time will be returned andd added to the call-out map
unsigned int find_best_time_overall(std::map<Team, double> &teams_and_times);  // It recieves only map with teams and their best times and looks for the best one!


#endif
