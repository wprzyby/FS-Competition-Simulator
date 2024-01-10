#include "EventSimulatorStandard.h"
#include "event_tools.h"

#include <limits>
#include <cmath>


const EventCategories EventSimulatorStandard::STD_BUSINESSPLAN_CATEGORIES = {pitch_video, novelty, content, finances, deep_dive_topic, demonstration_and_structure, delivery, questions, general_impression};
const EventCategories EventSimulatorStandard::STD_COST_AND_MANUFACTURING_CATEGORIES = {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case};
const EventCategories EventSimulatorStandard::STD_ENGINEERING_DESIGN_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, driver_interface, autonomous_functionality, design_report};
const EventCategories EventSimulatorStandard::STD_DC_ENGINEERING_DESIGN_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, autonomous_functionality};
const EventCategories EventSimulatorStandard::STD_SKIDPAD_CATEGORIES = {first_skid_left_time, first_skid_right_time, second_skid_left_time, second_skid_right_time};
const EventCategories EventSimulatorStandard::STD_ACCELERATION_CATEGORIES = {first_acc_time, second_acc_time};
const EventCategories EventSimulatorStandard::STD_AUTOCROSS_CATEGORIES = {first_aut_time, second_aut_time, third_aut_time, fourth_aut_time};
const EventCategories EventSimulatorStandard::STD_DC_AUTOCROSS_CATEGORIES = {first_aut_time, second_aut_time};
const EventCategories EventSimulatorStandard::STD_ENDURANCE_CATEGORIES = {end_corrected_time, end_uncorrected_time};
const EventCategories EventSimulatorStandard::STD_EFFICIENCY_CATEGORIES = {end_energy_used, end_energy_produced};
const EventCategories EventSimulatorStandard::STD_TRACKDRIVE_CATEGORIES = {tra_time, tra_laps};
const std::map<EventType, EventCategories> EventSimulatorStandard::events_categories = {
    {businessplan, STD_BUSINESSPLAN_CATEGORIES},
    {cost_and_manufacturing, STD_COST_AND_MANUFACTURING_CATEGORIES},
    {engineering_design, STD_ENGINEERING_DESIGN_CATEGORIES},
    {engineering_design_DC, STD_DC_ENGINEERING_DESIGN_CATEGORIES},
    {skidpad, STD_SKIDPAD_CATEGORIES},
    {skidpad_DC, STD_SKIDPAD_CATEGORIES},
    {skidpad_DV, STD_SKIDPAD_CATEGORIES},
    {acceleration, STD_ACCELERATION_CATEGORIES},
    {acceleration_DC, STD_ACCELERATION_CATEGORIES},
    {acceleration_DV, STD_ACCELERATION_CATEGORIES},
    {autocross, STD_AUTOCROSS_CATEGORIES},
    {autocross_DC, STD_DC_AUTOCROSS_CATEGORIES},
    {endurance, STD_ENDURANCE_CATEGORIES},
    {efficiency, STD_EFFICIENCY_CATEGORIES},
    {trackdrive, STD_TRACKDRIVE_CATEGORIES}
};


EventResults EventSimulatorStandard::simulate_event(EventType event_type, const Teams& teams) {
    EventResults results;
    switch (event_type) {
        case acceleration:
            results = simulate_m_acceleration(teams);
            break;
        case acceleration_DV:
            results = simulate_dv_acceleration(teams);
            break;
        case acceleration_DC:
            results = simulate_dc_acceleration(teams);
            break;
        case autocross:
            results = simulate_m_autocross(teams);
            break;
        case autocross_DC:
            results = simulate_dc_autocross(teams);
            break;
        case endurance:
            results = simulate_endurance(teams);
            break;
        case efficiency:
            results = simulate_efficiency(teams);
            break;
        case skidpad:
            results = simulate_m_skidpad(teams);
            break;
        case skidpad_DV:
            results = simulate_dv_skidpad(teams);
            break;
        case skidpad_DC:
            results = simulate_dc_skidpad(teams);
            break;
        case trackdrive:
            results = simulate_trackdrive(teams);
            break;
        case engineering_design:
            results = simulate_engineering_design(teams);
            break;
        case engineering_design_DC:
            results = simulate_dc_engineering_design(teams);
            break;
        case businessplan:
            results = simulate_businessplan(teams);
            break;
        case cost_and_manufacturing:
            results = simulate_cost_and_manufacturing(teams);
            break;
        default:
            throw std::invalid_argument("Invalid event type chosen to simulate");
    }
    
    return results;
}

