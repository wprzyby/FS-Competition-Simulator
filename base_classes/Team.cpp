#include <iostream>


#include "Team.h"
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


bool Team::operator>(const Team &second_arg) const
{
    return m_total_points > second_arg.get_total_points();
}

bool Team::operator<(const Team &second_arg) const
{
    return m_total_points < second_arg.get_total_points();
}


bool Team::operator==(const Team& second_argument) const
{
    if ((m_name == second_argument.get_name()) and (m_number == second_argument.get_number()) and (m_university = second_argument.get_university())) {return true;}
    else {return false;}
}
