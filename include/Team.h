#pragma once

#include "enums.h"
#include <iostream>
#include <map>


class Team
{
    private:
      std::string m_name;
      std::map<EventCategory, double> m_results;

    public:
    // constructor:
    Team(const std::string name);

    // getters:
    std::string name() const {return m_name;}
    double result_of_category(EventCategory category) const;

    // setters:
    void set_name(std::string name);
    void set_category_result(EventCategory category, double result_to_set);

};

std::ostream& operator<<(std::ostream& os, const Team& team);
