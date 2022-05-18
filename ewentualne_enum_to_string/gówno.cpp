#include <iostream>

enum events {
    #define X(a) a,
    #include "events.def"
    #undef X
    EventsCount
};

char const* const events_str[] {
    #define X(a) #a,
    #include "events.def"
    #undef X
    0
};

std::ostream& operator<<(std::ostream& os, enum events e)
{
    if(e >= EventsCount || e < 0) return os<<"???";
    return os<<events_str[e];
}

enum EventsCategories{
    #define X(a) a,
    #include "events_categories.def"
    #undef X
    CategoriesCount
};

char const* const categories_str[] {
    #define X(a) #a,
    #include "events_categories.def"
    #undef X
    0
};

std::ostream& operator<<(std::ostream& os, enum EventsCategories e)
{
    if(e >= CategoriesCount || e < 0) return os<<"???";
    return os<<categories_str[e];
}


// wzięte stąd: https://stackoverflow.com/questions/201593/is-there-a-simple-way-to-convert-c-enum-to-string?page=1&tab=scoredesc#tab-top
// nie wiem jak tego używać w praktyce generalnie 