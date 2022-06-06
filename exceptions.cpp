#include "exceptions.h"
#include "constants.h"
#include "enums/enums.h"
#include <stdexcept>


EmptyNameError::EmptyNameError(std::string name_of_attribute):
    std::invalid_argument("Tried to create " + name_of_attribute + " with empty name") {}


NoSuchCategoryInTheEventError::NoSuchCategoryInTheEventError(const EventsCategories category):
    std::invalid_argument("Among categories in the Event, there is no such categoty as: " + static_cast<std::string>(events_str[category])) {}


UnmatchedNumberOfFinalistsError::UnmatchedNumberOfFinalistsError():
    std::invalid_argument("The amount of provided number of finalists is different to the number of results to set.") {}


NegativeAdditionalPointsError::NegativeAdditionalPointsError():
    std::invalid_argument("Additional points in the event cannot be negative.") {}


NegativeAmountOfFinalitsError::NegativeAmountOfFinalitsError():
    std::invalid_argument("Number of finalists in the event cannot be negative.") {}


DuplicateTeamError::DuplicateTeamError():
    std::invalid_argument("Found two teams with the same name/university/ID") {}


InvalidModeError::InvalidModeError():
    std::invalid_argument("Invalid operation mode was selected") {}
