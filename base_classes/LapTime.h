#ifndef LAPTIME_H
#define LAPTIME_H

#include <iostream>

class LapTime  // LapTime is a special class that represents a lap time of a team in an event.
{
    private:
        // Atributes
        unsigned int m_minutes, m_seconds, m_miliseconds;

    public:
        // Constructors:
        LapTime();
        LapTime(unsigned int minutes, unsigned int seconds, unsigned int miliseconds);
        // Destructor:
        ~LapTime();

        // Getters:
        unsigned int get_minutes() const;
        unsigned int get_seconds() const;
        unsigned int get_miliseconds() const;

        // Method for calcuations:
        unsigned int get_total() const;

};


#endif
