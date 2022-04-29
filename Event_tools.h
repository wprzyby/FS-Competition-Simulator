#ifndef EVENT_TOOLS_H
#define EVENT_TOOLS_H
#include <map>
#include <vector>
#include <iostream>
#include "Team.h"


double find_max_points(std::map<Team, std::map<std::string, double>> &teams_and_results);
double sum_all_teams_results(std::map<std::string, double> results);


#endif
