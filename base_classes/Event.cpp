#include <iostream>
#include <vector>
#include <map>
#include "Event.h"
#include "Team.h"
#include "../exceptions.h"
#include "../Event_tools.h"


Event::Event(){}
Event::Event(std::vector<Team> teams_participating)
{
    m_teams_participating = teams_participating;
}
Event::~Event(){};


void Event::set_results(std::map<Team, std::map<EventsCategories, double>> &results, std::vector<EventsCategories> &categories_in_event)
{
    std::map<EventsCategories, double> inner_results_map = results.begin()->second;
    for (auto& [category, _]: inner_results_map)
    {
        bool check = check_if_category_in_vector(category, categories_in_event);
        if (check != true)
        {
            throw NoSuchCategoryInTheEventError(category);
        }
    }
    m_teams_and_results = results;
}


void Event::make_event_classification()
{
    //TODO: Implement this method.
}


void Event::simulate()
{
    calculate_teams_points();
    make_event_classification();
}


std::map<Team, double> Event::get_classification() const
{
    return m_classification;
}
