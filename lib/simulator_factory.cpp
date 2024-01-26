#include "simulator_factory.h"
#include "EventSimulatorStandard.h"
#include "PointsCalculatorFSG.h"

EventSimulatorPtr create_event_simulator(const CompetitionType competition_type) {
    switch (competition_type) {
        case FSG: return std::make_shared<EventSimulatorStandard>(std::make_shared<PointsCalculatorFSG>());
        default: return std::make_shared<EventSimulatorStandard>(std::make_shared<PointsCalculatorFSG>());
    }
}