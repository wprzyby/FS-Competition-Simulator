#pragma once

#include <string>
#include <map>
#include "enums.h"

using EventData = std::map<std::string, double>;

class PointsCalculatorInterface
{
    public:
      PointsCalculatorInterface() {}
      virtual double get_points(EventType event_type, const EventData& event_data, std::string team_name)=0;

};