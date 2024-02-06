#pragma once

#include "PointsCalculatorInterface.h"

using EventData = std::map<std::string, double>;

class PointsCalculatorFSG: public PointsCalculatorInterface {
    public:
      PointsCalculatorFSG(): PointsCalculatorInterface() {}
      double get_points(EventType event_type, const EventData& event_data, std::string team_name) override;
    protected:
      virtual double m_acceleration_points(const EventData& event_data, std::string team_name);
      virtual double dc_acceleration_points(const EventData& event_data, std::string team_name);
      virtual double dv_acceleration_points(const EventData& event_data, std::string team_name);

      virtual double m_autocross_points(const EventData& event_data, std::string team_name);
      virtual double dc_autocross_points(const EventData& event_data, std::string team_name);

      virtual double endurance_points(const EventData& event_data, std::string team_name);
      virtual double efficiency_points(const EventData& event_data, std::string team_name);

      virtual double m_skidpad_points(const EventData& event_data, std::string team_name);
      virtual double dc_skidpad_points(const EventData& event_data, std::string team_name);
      virtual double dv_skidpad_points(const EventData& event_data, std::string team_name);

      virtual double trackdrive_points(const EventData& event_data, std::string team_name);

      virtual double businessplan_points(const EventData& event_data, std::string team_name);
      virtual double cost_and_manufacturing_points(const EventData& event_data, std::string team_name);
      virtual double engineering_design_points(const EventData& event_data, std::string team_name);
};