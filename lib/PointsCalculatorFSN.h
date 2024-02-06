#include "PointsCalculatorFSG.h"

class PointsCalculatorFSN: public PointsCalculatorFSG {
    double m_acceleration_points(const EventData& event_data, std::string team_name) override;
    double m_skidpad_points(const EventData& event_data, std::string team_name) override;
    double endurance_points(const EventData& event_data, std::string team_name) override;
};