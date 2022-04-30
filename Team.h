#ifndef TEAM_H
#define TEAM_H
#include <iostream>


class Team
{
    private:
    std::string name;
    std::string university;
    unsigned int number;


    public:
    Team(const std::string p_name, const std::string p_university, const unsigned int p_number);
    std::string get_name();
    std::string get_univeristy();
    unsigned int get_number();
};


#endif
