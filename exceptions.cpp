#include "exceptions.h"
#include "constants.h"
#include <stdexcept>


EmptyTeamNameError::EmptyTeamNameError():
    std::invalid_argument("Tried to create team with empty name") {}


NoSuchCategoryInTheEventError::NoSuchCategoryInTheEventError(const EventsCategories category):
    std::invalid_argument("Among categories in the Event, there is no such categoty: ") {std::cout << category << std::endl;}


UnmatchedNumberOfFinalistsError::UnmatchedNumberOfFinalistsError():
    std::invalid_argument("The amount of provided number of finalists is different to the number of results to set.") {}
