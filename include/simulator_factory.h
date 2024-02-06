#pragma once

#include <memory>
#include "EventSimulatorInterface.h"
#include "PointsCalculatorInterface.h"
#include "enums.h"

using EventSimulatorPtr = std::shared_ptr<EventSimulatorInterface>;

EventSimulatorPtr create_event_simulator(const CompetitionType competition_type);