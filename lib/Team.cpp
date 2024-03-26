#include <iostream>
#include <stdexcept>

#include "Team.h"
#include "exceptions.h"


Team::Team(const std::string name) {
    set_name(name);
}


void Team::set_name(std::string name) {
    m_name = name;
}


void Team::set_category_result(EventCategory category, double result_to_set) {
    m_results[category] = result_to_set;
}


double Team::result_of_category(EventCategory category) const {
    return m_results.at(category);
}

bool Team::is_category_result_set(EventCategory category) const {
    if (this->m_results.count(category)) {
        return true;
    }
    return false;
}