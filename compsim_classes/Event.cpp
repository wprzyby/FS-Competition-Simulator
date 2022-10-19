#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Event.h"
#include "Team.h"

#include "constants.h"
#include "exceptions.h"
#include <compsim_enums/enums.h>
#include "event_tools.h"


void Event::set_results(std::map<Team, std::map<EventsCategories, double>> &results)
{
    for(auto& [_, categories_and_points]: results)
    {
        for (auto& [category, _]: categories_and_points)
        {
            bool check = check_if_category_in_vector(category, m_event_categories);
            if (check == false)
            {
                throw NoSuchCategoryInTheEventError(category);
            }
        }
    }
    m_teams_and_results = results;
}

void Event::set_teams(std::vector<Team> &teams)
{
    m_teams_participating = teams;
}


void Event::make_event_classification()
{
    // creates classification in the form of a vector of [Team, points] pairs sorted according to points
    m_sorted_classification = sort_teams_and_points(m_classification, true);
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

std::string Event::get_info_file_name() const
{
    return INFO_FILE_NAMES.at(m_event_type);
}
