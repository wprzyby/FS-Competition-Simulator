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
    // Function to sort the map according to value in a (key-value) pairs

    // Declare vector of pairs
    std::vector<std::pair<Team, double>> classification_as_vector;

    // Copy Team-points pair from classification to vector of pairs
    for (auto& [team, points]: m_classification)
    {
        classification_as_vector.push_back({const_cast<Team&>(team), points});
    }

    // Sort using comparator function
    std::sort(classification_as_vector.begin(), classification_as_vector.end(), compare_teams);

    // Assigning sorted vector into the attribute
    m_sorted_classification = classification_as_vector;
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
