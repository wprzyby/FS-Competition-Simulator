#include <iostream>
#include <stdexcept>

#include "Team.h"
#include "exceptions.h"


Team::Team(const std::string name, const std::string university, const unsigned number) : m_number(number) {
    set_name(name);
    set_university(university);
}


void Team::set_name(std::string name) {
    // check for empty string
    // if (name.empty()) {throw EmptyNameError("team");}

    m_name = name;
}


void Team::set_university(std::string university) {
    // if (university.empty()) {throw EmptyNameError("university");}

    m_university = university;
}

// operator implemented for interacting with std::map
bool Team::operator<(const Team &second_arg) const
{
    return m_number < second_arg.m_number;
}

bool Team::operator==(const Team& second_argument) const
{
    // Here are or in ifs because EVERY team`s atributte has to be unique. Operator is used for assertion that there are no duplicate teams.
    if ((m_name == second_argument.m_name) && (m_number == second_argument.m_number) && (m_university == second_argument.m_university)) {return true;}
    else {return false;}
}

std::ostream& operator<<(std::ostream& os, const Team& team)
{
    os << team.m_name << " (" << team.m_number << ", " << team.m_university<< ")";
    return os;
}