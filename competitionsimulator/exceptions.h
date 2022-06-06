#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <stdexcept>
#include "constants.h"
#include "enums/enums.h"


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


class NegativeAmountOfFinalitsError: public std::invalid_argument
{
    public:
        NegativeAmountOfFinalitsError();
};


class DuplicateTeamError: public std::invalid_argument
{
    public:
        DuplicateTeamError();
};


class InvalidModeError: public std::invalid_argument
{
    public:
        InvalidModeError();
};


#endif
