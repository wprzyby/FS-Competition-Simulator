#pragma once

#include <iostream>

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
// Using macros to define lists of enums from file and at the same time                   //
// declare their conversion to strings.                                                   //
// To convert to string, a table is created from the same file as the enum                //
// and it is indexed by the enum's number value, so by addressing events_str[enum],       //
// the number of the enum is used as the index and it fetches the coresponding string.    //
// Changing values of enums in their respective .def files is enough, no need             //
// to modify this file (unless a new enum is added).                                      //
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//


enum EventType
{
    #define X(a) a,
    #include "EventType.def"
    #undef X
    EventTypeTotalCount
};

enum EventsCategories
{
    #define X(a) a,
    #include "EventsCategories.def"
    #undef X
    CategoriesTotalCount
};

enum LapTimeMode
{
    #define X(a) a,
    #include "LapTimeMode.def"
    #undef X
    LapTimeModeTotalCount
};

char const* const events_str[]
{
    #define X(a) #a,
    #include "EventType.def"
    #undef X
    0
};

char const* const categories_str[]
{
    #define X(a) #a,
    #include "EventsCategories.def"
    #undef X
    0
};

char const* const LapTimeMode_str[]
{
    #define X(a) #a,
    #include "LapTimeMode.def"
    #undef X
    0
};


std::ostream& operator<<(std::ostream& os, enum EventType e);
std::ostream& operator<<(std::ostream& os, enum EventsCategories e);
std::ostream& operator<<(std::ostream& os, enum LapTimeMode e);
