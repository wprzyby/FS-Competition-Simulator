#include "PointsCalculatorFSG.h"

double PointsCalculatorFSG::businessplan_points(const EventData& event_data, std::string team_name) {
    double p_team = event_data.at(team_name);
    double p_team_finals = event_data.at("finals_" + team_name);
    double p_max = event_data.at("best_result_non_finalist");

    if (p_team_finals != 0) return p_team_finals;
    return 70 * (p_team / p_max);
}


double PointsCalculatorFSG::cost_and_manufacturing_points(const EventData& event_data, std::string team_name) {
    double p_team = event_data.at(team_name);
    double p_team_finals = event_data.at("finals_" + team_name);
    double p_max = event_data.at("best_result_non_finalist");
    double best_result_finalist = event_data.at("best_result_finalist");

    if (p_team_finals != 0) return p_team_finals;
    if (best_result_finalist != 0) return 95 * (p_team / p_max);
    return p_team;
}


double PointsCalculatorFSG::engineering_design_points(const EventData& event_data, std::string team_name) {
    return event_data.at(team_name);
}