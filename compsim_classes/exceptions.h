#pragma once

#include <stdexcept>
#include "constants.h"
#include <compsim_enums/enums.h>


class EmptyNameError: public std::invalid_argument
{
    public:
        EmptyNameError(std::string name_of_attribute);
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
        NoSuchCategoryInTheEventError(const EventCategory category);
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


class NegativeDeltaError: public std::invalid_argument
{
    public:
        NegativeDeltaError();
};
