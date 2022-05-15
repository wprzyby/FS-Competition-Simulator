#include <iostream>
#include <map>
#include <vector>
#include "BuisnessPlanEvent.h"
#include "../base_classes/Team.h"
#include "../Event_tools.h"
#include "../constants.h"
#include "../exceptions.h"


BuisnessPlanEvent::BuisnessPlanEvent(std::vector<Team> &teams)
{
    teams_participating = teams;
    event_categories = BuiPlaEveCat;
    m_event_type = businessplan;
}
BuisnessPlanEvent::BuisnessPlanEvent()
{
    event_categories = BuiPlaEveCat;
}
BuisnessPlanEvent::~BuisnessPlanEvent(){}


void BuisnessPlanEvent::calculate_teams_points(int finalists=0, std::map<Team, double> points_to_set={})
{

    // Finding best result among all teams:
    const double max_points = find_max_points(teams_and_results);
    //

    // Calculating teams points and adding them to the classification map:
    for (auto& [team, results]: teams_and_results)
    {
        const double team_total_result = sum_all_teams_results(results);  // summing all team`s point
        const double team_points = 70*(team_total_result/max_points);  // calculating team`s points based on the formula
        classification.insert({team, team_points});  // inserting team and their final result into classification
    }
    //

    // In case there are finals:
    if (finalists > 0)
    {
        if (points_to_set.size() != finalists)  // Checking if number of provided results matches with number of finalists
        {
            throw UnmatchedNumberOfFinalistsError();
        }

        make_event_classification();  // making clasification (sorting teams)

        int iterator = 1;
        for (auto& [team, points]: points_to_set)  // modyfing best teams` results
        {
            classification.at(team) = points;
            if (iterator == finalists) {break;}
            iterator++;  // FIXME: Do I really want to this that way?
        }
    }
    //
}


std::string BuisnessPlanEvent::get_file_info_name()
{
    std::string name = "BuisnessPlanEventInfo.pdf";
    return name;
}

// DONE | Wzorzec dla statycznych
