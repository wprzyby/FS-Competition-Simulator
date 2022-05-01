#include <iostream>
#include <vector>
#include <map>
#include "Event.h"
#include "Team.h"


void Event::set_teams_results(std::map<Team,std::vector<double>> &results)  // This function needs map with Teams and vector of points they scored
{
    int i = 0;
    std::map<Team,std::vector<double>>::iterator team_results_itr = results.begin();  // Getting first row of provided results
    for (std::map<Team,std::map<std::string,double>>::iterator teams_itr = teams_and_results.begin(); teams_itr != teams_and_results.end(); ++teams_itr)  // Loop for teams
    {
        std::map<std::string,double> current_results_map = (*teams_itr).second;  // Geting current results from the Team
        std::vector<double> results_to_set = (*team_results_itr).second;  // Getting a vector of results that need to be set for the team
        int j = 0;
        for (std::map<std::string, double>::iterator results_itr = current_results_map.begin(); results_itr != current_results_map.end(); ++results_itr)  // Loop for results
        {
            (*results_itr).second = results_to_set[j];
            j++;
        }
        i++;
        team_results_itr++;  // Getting another row of provided map with results
    }
}