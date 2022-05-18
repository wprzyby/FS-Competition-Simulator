#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <stdexcept>
#include "constants.h"


class EmptyTeamNameError: public std::invalid_argument
{
    public:
        EmptyTeamNameError();
};


class UnmatchedNumberOfFinalistsError: public std::invalid_argument
{
    public:
        UnmatchedNumberOfFinalistsError();
};


class NegativeAdditionalPointsError: public std::invalid_argument
{
    public:
        NegativeAdditionalPointsError();
};


class NoSuchCategoryInTheEventError: public std::invalid_argument
{
    public:
        NoSuchCategoryInTheEventError(const EventsCategories category);
};


#endif
