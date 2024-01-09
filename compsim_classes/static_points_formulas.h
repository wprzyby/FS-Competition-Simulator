#pragma once

#include <map>
#include <string>

double businessplan_points(std::map<std::string, double> event_data, std::string team_name);
double cost_and_manufacturing_points(std::map<std::string, double> event_data, std::string team_name);
double engineering_design_points(std::map<std::string, double> event_data, std::string team_name);