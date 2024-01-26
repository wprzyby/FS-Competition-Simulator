#pragma once

#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>

#include "Team.h"
#include "EventSimulatorInterface.h"
#include "enum_string_maps.h"


using EventResults = std::map<std::string, double>;
using Teams = std::vector<Team>;
using EventCategories = std::vector<EventCategory>;
using EventData = std::map<std::string, double>;


class EventSimulatorStandard: public EventSimulatorInterface
{
    public:
      const static EventCategories STD_BUSINESSPLAN_CATEGORIES;
      const static EventCategories STD_COST_AND_MANUFACTURING_CATEGORIES;
      const static EventCategories STD_ENGINEERING_DESIGN_CATEGORIES;
      const static EventCategories STD_DC_ENGINEERING_DESIGN_CATEGORIES;
      const static EventCategories STD_SKIDPAD_CATEGORIES;
      const static EventCategories STD_ACCELERATION_CATEGORIES;
      const static EventCategories STD_AUTOCROSS_CATEGORIES;
      const static EventCategories STD_DC_AUTOCROSS_CATEGORIES;
      const static EventCategories STD_ENDURANCE_CATEGORIES;
      const static EventCategories STD_EFFICIENCY_CATEGORIES;
      const static EventCategories STD_TRACKDRIVE_CATEGORIES;
      const static std::map<EventType, EventCategories> std_events_categories;

    public:
      EventSimulatorStandard(PointsCalculatorPtr points_calculator): EventSimulatorInterface(points_calculator) {}
      EventSimulatorStandard(PointsCalculatorPtr points_calculator, std::map<std::string, double> events_constants):
                            EventSimulatorInterface(points_calculator, events_constants) {}
      EventResults simulate_event(EventType event_type, const Teams& teams) override;
      EventCategories get_event_categories(EventType event_type) override;

    private:
      EventData preprocessing_standard(const Teams& teams, EventCategories categories);
      EventData preprocessing_ranks_based(const Teams& teams, EventCategories categories);
      EventData preprocessing_dc_autocross(const Teams& teams);
      EventData preprocessing_efficiency(const Teams& teams);
      EventData preprocessing_skidpad(const Teams& teams);
      EventData preprocessing_skidpad_ranks_based(const Teams& teams);
      EventData preprocessing_static_finals(const Teams& teams, EventCategories categories, EventCategory finals_category);
      EventData preprocessing_static_no_finals(const Teams& teams, EventCategories categories);
      EventData preprocessing_trackdrive(const Teams& teams);

      EventResults simulate_m_acceleration(const Teams& teams);
      EventResults simulate_dv_acceleration(const Teams& teams);
      EventResults simulate_dc_acceleration(const Teams& teams);
      EventResults simulate_m_autocross(const Teams& teams);
      EventResults simulate_dc_autocross(const Teams& teams);
      EventResults simulate_endurance(const Teams& teams);
      EventResults simulate_efficiency(const Teams& teams);
      EventResults simulate_m_skidpad(const Teams& teams);
      EventResults simulate_dv_skidpad(const Teams& teams);
      EventResults simulate_dc_skidpad(const Teams& teams);
      EventResults simulate_trackdrive(const Teams& teams);

      EventResults simulate_engineering_design(const Teams& teams);
      EventResults simulate_dc_engineering_design(const Teams& teams);
      EventResults simulate_businessplan(const Teams& teams);
      EventResults simulate_cost_and_manufacturing(const Teams& teams);
};

class missing_constant_error: public std::logic_error
{
    public:
        missing_constant_error(std::string name_of_constant, EventType event_type):
            std::logic_error("Constant " + name_of_constant + " is required by"
            + EVENT_TYPE_TO_STRING.at(event_type) + "but was not set before simulation"
            )
            {}
};