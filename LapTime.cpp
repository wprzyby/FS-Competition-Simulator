#include <iostream>
#include "LapTime.h"


LapTime::LapTime(){};
LapTime::~LapTime(){};
LapTime::LapTime(unsigned int p_minutes, unsigned int p_seconds, unsigned int p_miliseconds)
{
    minutes = p_minutes;
    seconds = p_seconds;
    miliseconds = p_miliseconds;
}


unsigned int LapTime::get_minutes() const
{
    return minutes;
}


unsigned int LapTime::get_seconds() const
{
    return seconds;
}


unsigned int LapTime::get_miliseconds() const
{
    return miliseconds;
}


unsigned int LapTime::get_total() const  // This method will be used by interface, Event classes will be given concrete time
{
    unsigned int minutes_as_milliseconds = 60*1000*minutes;
    unsigned int seconds_as_milliseconds = 1000*seconds;
    return miliseconds + minutes_as_milliseconds + seconds_as_milliseconds;
}
