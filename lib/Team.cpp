#include <iostream>
#include <stdexcept>

#include "Team.h"
#include "exceptions.h"


Team::Team(const std::string name) {
    set_name(name);
}


void Team::set_name(std::string name) {
    if (name.empty()) throw EmptyNameError("team");
    m_name = name;
}


void Team::set_category_result(EventCategory category, double result_to_set) {
    m_results[category] = result_to_set;
}


double Team::result_of_category(EventCategory category) const {
    return m_results.at(category);
}