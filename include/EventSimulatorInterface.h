#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "Team.h"
#include "PointsCalculatorInterface.h"

using EventResults = std::map<std::string, double>;
using Teams = std::vector<Team>;
using EventCategories = std::vector<EventCategory>;
using EventData = std::map<std::string, double>;
using PointsCalculatorPtr = std::shared_ptr<PointsCalculatorInterface>;

class EventSimulatorInterface
{
    protected:
      PointsCalculatorPtr points_calculator_;
      std::map<std::string, double> events_constants_;
    public:
      EventSimulatorInterface(PointsCalculatorPtr points_calculator) : points_calculator_(points_calculator) {}
      EventSimulatorInterface(PointsCalculatorPtr points_calculator, std::map<std::string, double> constants)
                              : points_calculator_(points_calculator)
                              {set_event_constants(constants);}
      virtual ~EventSimulatorInterface() {}
      virtual EventResults simulate_event(EventType event_type, const Teams& teams)=0;
      void set_event_constants(std::map<std::string, double> events_constants) {events_constants_ = events_constants;}
      virtual EventCategories get_event_categories(EventType event_type)=0;
      virtual std::map<EventType, EventCategories> get_all_events_categories()=0;
};