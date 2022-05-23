#ifndef TEAM_H
#define TEAM_H
#include <iostream>


class Team
{
    private:
    std::string m_name;
    std::string m_university;
    unsigned m_number;
    unsigned m_total_points;


    public:
    // constructor:
    Team(const std::string name, const std::string university, const unsigned number);

    // getters:
    std::string get_name() const {return m_name;}
    std::string get_univeristy() const {return m_university;}
    unsigned get_number() const {return m_number;}
    double get_total_points() const {return m_total_points;}

    // setters:
    // (boolean returns to communicate whether the setter succeeded or failed)
    bool set_name(std::string name);
    bool set_university(std::string university);
    bool set_number(unsigned number);
    bool set_total_points(unsigned points);

    bool operator>(const Team second_arg) const;
    bool operator==(const Team& second_argument) const;

};


#endif
