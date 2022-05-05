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
    // constructor:
    Team(const std::string p_name, const std::string p_university, const unsigned int p_number);

    // getters:
    std::string get_name() const;
    std::string get_univeristy() const;
    unsigned int get_number() const;

    // setters:
    // (boolean returns to communicate whether the setter succeeded or failed)
    bool set_name(std::string p_name);
    bool set_university(std::string p_university);
    bool set_number(unsigned int p_number);

};


#endif
