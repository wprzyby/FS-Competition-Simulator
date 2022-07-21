#pragma once

#include <iostream>


class Team
{
    private:
    std::string m_name;
    std::string m_university;
    unsigned m_number;


    public:
    // constructor:
    Team(const std::string name, const std::string university, const unsigned number);

    // getters:
    std::string get_name() const {return m_name;}
    std::string get_university() const {return m_university;}
    unsigned get_number() const {return m_number;}

    // setters:
    void set_name(std::string name);
    void set_university(std::string university);
    void set_number(unsigned number);

    // Overloaded operators
    bool operator<(const Team &second_arg) const;
    bool operator==(const Team& second_argument) const;
    friend std::ostream& operator<<(std::ostream& os, const Team& team);
    //

};

std::ostream& operator<<(std::ostream& os, const Team& team);
