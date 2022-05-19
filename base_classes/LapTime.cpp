#include <iostream>
#include "LapTime.h"


LapTime::LapTime(){};
LapTime::~LapTime(){};
LapTime::LapTime(unsigned int minutes, unsigned int seconds, unsigned int miliseconds)
{
    minutes = minutes;
    seconds = seconds;
    miliseconds = miliseconds;
}


unsigned int LapTime::get_minutes() const
{
    return m_minutes;
}


unsigned int LapTime::get_seconds() const
{
    return m_seconds;
}


unsigned int LapTime::get_miliseconds() const
{
    return m_miliseconds;
}


unsigned int LapTime::get_total() const  // This method will be used by interface, Event classes will be given concrete time
{
    unsigned int minutes_as_milliseconds = 60*1000*m_minutes;
    unsigned int seconds_as_milliseconds = 1000*m_seconds;
    return m_miliseconds + minutes_as_milliseconds + seconds_as_milliseconds;
}
