#pragma once

#include "PointsCalculatorInterface.h"

using EventData = std::map<std::string, double>;

class PointsCalculatorFSG: public PointsCalculatorInterface {
    public:
      PointsCalculatorFSG(): PointsCalculatorInterface() {}
      double get_points(EventType event_type, const EventData& event_data, std::string team_name) override;
    protected:
      double m_acceleration_points(const EventData& event_data, std::string team_name);
      double dc_acceleration_points(const EventData& event_data, std::string team_name);
      double dv_acceleration_points(const EventData& event_data, std::string team_name);

      double m_autocross_points(const EventData& event_data, std::string team_name);
      double dc_autocross_points(const EventData& event_data, std::string team_name);

      double endurance_points(const EventData& event_data, std::string team_name);
      double efficiency_points(const EventData& event_data, std::string team_name);

      double m_skidpad_points(const EventData& event_data, std::string team_name);
      double dc_skidpad_points(const EventData& event_data, std::string team_name);
      double dv_skidpad_points(const EventData& event_data, std::string team_name);

      double trackdrive_points(const EventData& event_data, std::string team_name);

      double businessplan_points(const EventData& event_data, std::string team_name);
      double cost_and_manufacturing_points(const EventData& event_data, std::string team_name);
      double engineering_design_points(const EventData& event_data, std::string team_name);
};