#include <iostream>
#include <map>
#include <vector>
#include "BuisnessPlanEvent.h"

virtual void create_teams_and_results_map();  // Function to create teams_and_results map.
virtual void set_teams_results();  // Function to set results in the event for every team participating.
virtual void calculate_teams_points(const unsigned int best_result);  // Function that calculates points for teams (based on the map: teams_and_results).
virtual void make_final_classification();  // Function that sorts teams by their total score.
virtual void open_info_file();  // Opens the file with information about the Event.
