#include <iostream>

#include "Team.h"

Team::Team(const std::string p_name, const std::string p_university, const unsigned int p_number)
{
    name = p_name;
    university = p_university;
    number = p_number;
}

std::string Team::get_name() const
{
    return name;
}

std::string Team::get_univeristy() const
{
    return university;
}

unsigned int Team::get_number() const
{
    return number;
}

bool Team::set_name(std::string p_name)
{
    // check for empty string
    if (p_name.empty()) {return false;}

    name = p_name;
    return true;
}

bool Team::set_university(std::string p_university)
{
    // check for empty string
    if (p_university.empty()) {return false;}

    university = p_university;
    return true;
}

bool Team::set_number(unsigned int p_number)
{
    // currently doesn't have any number validity check, any number works
    number = p_number;
    return true;
}