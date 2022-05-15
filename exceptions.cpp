#include "exceptions.h"
#include <stdexcept>

EmptyTeamNameError::EmptyTeamNameError():
    std::invalid_argument("Tried to create team with empty name") {}
