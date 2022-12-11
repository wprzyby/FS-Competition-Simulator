#pragma once

#include "compsim_enums/enums.h"
#include <iostream>
#include <map>


class Team
{
    private:
      std::string m_name;
      std::string m_university;
      unsigned m_number;
      std::map<EventsCategories, double> m_results;

    public:
    // constructor:
    Team(const std::string name="", const std::string university="", const unsigned number=0);

    // getters:
    std::string name() const {return m_name;}
    std::string university() const {return m_university;}
    unsigned number() const {return m_number;}
    double result_of_category(EventsCategories category) const {return m_results.at(category);}

    // setters:
    void set_name(std::string name);
    void set_university(std::string university);
    void set_number(unsigned number) {m_number = number;}
    void set_category_result(EventsCategories category, double result_to_set) {m_results[category] = result_to_set;}

    // Overloaded operators
    bool operator<(const Team &second_arg) const;
    bool operator==(const Team& second_argument) const;
    friend std::ostream& operator<<(std::ostream& os, const Team& team);
    //

};

std::ostream& operator<<(std::ostream& os, const Team& team);
