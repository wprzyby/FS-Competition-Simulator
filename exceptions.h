#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class EmptyTeamNameError: public std::invalid_argument
{
    public:
        EmptyTeamNameError();
};




#endif