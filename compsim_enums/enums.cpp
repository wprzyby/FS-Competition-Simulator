#include <iostream>
#include "enums.h"

// Implementation of stream operators for enum to string conversion
// using a conversion table indexed by enum's number value declared in header

std::ostream& operator<<(std::ostream& os, enum EventType e)
{
    if(e >= EventTypeTotalCount || e < 0) return os<<"unknown";
    return os<<events_str[e];
}

std::ostream& operator<<(std::ostream& os, enum EventCategory e)
{
    if(e >= CategoriesTotalCount || e < 0) return os<<"unknown";
    return os<<categories_str[e];
}

std::ostream& operator<<(std::ostream& os, enum LapTimeMode e)
{
    if(e >= LapTimeModeTotalCount || e < 0) return os<<"unknown";
    return os<<LapTimeMode_str[e];
}