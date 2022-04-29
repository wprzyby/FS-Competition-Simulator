#include <iostream>
#include <vector>
#include <map>
#include "Event.h"


Event::void set_teams_results(std::vector<double> &results)
{
    int i = 0;
    for (itr = teams_and_results.begin(); itr != teams_and_results.end(); ++itr)
    {
        itr->second = results[i];
        i++;
    }
}