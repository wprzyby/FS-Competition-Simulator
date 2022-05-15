#include <iostream>

#include "Team.h"
// FIXME: relative imports again
#include "../exceptions.h"

Team::Team(const std::string name, const std::string university, const unsigned number) :
m_university(university), m_number(number)
{
    if (name.empty())
    {
        throw EmptyTeamNameError();
    }
    m_name = name;
    m_total_points = 0;
}

bool Team::set_name(std::string name)
{
    // check for empty string
    if (name.empty()) {return false;}

    m_name = name;
    return true;
}

bool Team::set_university(std::string university)
{
    // check for empty string
    if (university.empty()) {return false;}

    m_university = university;
    return true;
}

bool Team::set_number(unsigned int number)
{
    // currently doesn't have any number validity check, any number works
    m_number = number;
    return true;
}

bool Team::set_total_points(unsigned int points)
{
    m_total_points = points;
    return true;
}