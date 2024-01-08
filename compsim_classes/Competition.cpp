#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>

#include "Competition.h"
#include "Team.h"

#include "event_tools.h"
#include "constants.h"
#include "exceptions.h"
#include <compsim_enums/enums.h>

const std::vector<EventCategory> Competition::BUSINESSPLAN_EVENT_CATEGORIES = {pitch_video, novelty, content, finances, deep_dive_topic, demonstration_and_structure, delivery, questions, general_impression};
const std::vector<EventCategory> Competition::COST_AND_MANUFACTURING_EVENT_CATEGORIES = {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case};
const std::vector<EventCategory> Competition::ENGINEERING_DESIGN_EVENT_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, driver_interface, autonomous_functionality, design_report};
const std::vector<EventCategory> Competition::DC_ENGINEERING_DESIGN_EVENT_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, autonomous_functionality};
const std::vector<EventCategory> Competition::SKIDPAD_EVENT_CATEGORIES = {first_skid_left_time, first_skid_right_time, second_skid_left_time, second_skid_right_time};
const std::vector<EventCategory> Competition::ACCELERATION_EVENT_CATEGORIES = {first_acc_time, second_acc_time};
const std::vector<EventCategory> Competition::AUTOCROSS_EVENT_CATEGORIES = {first_aut_time, second_aut_time, third_aut_time, fourth_aut_time};
const std::vector<EventCategory> Competition::DC_AUTOCROSS_EVENT_CATEGORIES = {first_aut_time, second_aut_time};
const std::vector<EventCategory> Competition::ENDURANCE_EVENT_CATEGORIES = {end_corrected_time, end_uncorrected_time, end_energy_used, end_energy_produced};
const std::vector<EventCategory> Competition::TRACKDRIVE_EVENT_CATEGORIES = {tra_time, tra_laps};


Competition::Competition(std::vector<Team> &teams, std::vector<EventType> &events)
{
    set_teams(teams);
    set_events(events);
}


void Competition::set_events(std::vector<EventType> &events)
{
    m_events = events;
}


void Competition::set_teams(std::vector<Team> &teams)
{
    m_teams = teams;
}


void Competition::simulate()
{
    m_events_and_teams_points.clear();
    m_events_and_classifications.clear();

    for(auto& event: m_events)
    {
        switch(event) {
            case acceleration:
                simulate_m_acceleration();
                break;
            case acceleration_DV:
                simulate_dv_acceleration();
                break;
            case acceleration_DC:
                simulate_dc_acceleration();
                break;
            case autocross:
                simulate_m_autocross();
                break;
            case autocross_DC:
                simulate_dc_autocross();
                break;
            case businessplan:
                simulate_businessplan();
                break;
            case cost_and_manufacturing:
                simulate_cost_and_manufacturing();
                break;
            case endurance:
                simulate_endurance();
                break;
            case efficiency:
                simulate_efficiency();
                break;
            case engineering_design:
                simulate_engineering_design();
                break;
            case engineering_design_DC:
                simulate_dc_engineering_design();
                break;
            case skidpad:
                simulate_m_skidpad();
                break;
            case skidpad_DV:
                simulate_dv_skidpad();
                break;
            case skidpad_DC:
                simulate_dc_skidpad();
                break;
            case trackdrive:
                simulate_trackdrive();
                break;
            default:
                throw std::invalid_argument("Invalid event type selected");
        }
    }
}


void Competition::create_classification()
{
    m_comp_classification.clear();
    m_teams_and_comp_points.clear();
    simulate();

    // summing points from each event for every team to obtain total competition points
    for(auto& [_, event_points]: m_events_and_teams_points)
        {
            for(auto& [team, points]: event_points)
            {
                m_teams_and_comp_points[team] += points;
            }
        }

    // assigning final points to teams, adding {team, total_points} pair to final classification
    for(auto& team: m_teams)
    {
        m_comp_classification.push_back({team.name(), m_teams_and_comp_points.at(team.name())});
    }

    // sorting the final classification by team's points in descending order
    std::sort(m_comp_classification.begin(), m_comp_classification.end(), better_team);

}


std::map<std::string, double> Competition::preprocessing_standard(std::vector<EventCategory> categories)
{
    std::map<std::string, double> event_data;
    double best_time_overall = std::numeric_limits<double>::infinity();
    for (auto& team: m_teams) {
        double best_time = find_best_time_for_team(team.name(), categories);
        event_data[team.name()] = best_time;
        if (best_time != 0 && best_time < best_time_overall) {
            best_time_overall = best_time;
        }
    }
    event_data["best_time_overall"] = best_time_overall;
    return event_data;
}

std::map<std::string, double> Competition::preprocessing_ranks_based(std::vector<EventCategory> categories)
{
    std::map<std::string, double> event_data;
    std::vector<std::pair<std::string, double>> teams_and_best_times = {};
    for (auto& team: m_teams) {
        double best_time = find_best_time_for_team(team.name(), categories);
        teams_and_best_times.push_back({team.name(), best_time});
    }
    sort_teams_and_best_times(teams_and_best_times);
    int current_place = 0;
    for (auto& [team_name, best_time]: teams_and_best_times) {
        if (best_time == 0) break;
        ++current_place;
        event_data[team_name] = current_place;
    }
    event_data["non_zero_times"] = current_place;
    return event_data;
}

