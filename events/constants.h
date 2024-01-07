#pragma once

#include <compsim_enums/enums.h>
#include <map>
#include <vector>

// Categories for BusinessPlanEvent
const std::vector<EventCategory> BUSINESSPLAN_EVENT_CATEGORIES = {pitch_video, novelty, content, finances, deep_dive_topic, demonstration_and_structure, delivery, questions, general_impression};

// Categories for CostAndManufacturingEvent
const std::vector<EventCategory> COST_AND_MANUFACTURING_EVENT_CATEGORIES = {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case};

// Categories for EngineeringDesignEvent
const std::vector<EventCategory> ENGINEERING_DESIGN_EVENT_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, driver_interface, autonomous_functionality, design_report};

// Categories for Driverless EngineeringDesignEvent
const std::vector<EventCategory> DC_ENGINEERING_DESIGN_EVENT_CATEGORIES = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, autonomous_functionality};


// Categories for SkidpadEvent
const std::vector<EventCategory> SKIDPAD_EVENT_CATEGORIES = {first_skid_left_time, first_skid_right_time, second_skid_left_time, second_skid_right_time};

// Categories for AccelerationEvent
const std::vector<EventCategory> ACCELERATION_EVENT_CATEGORIES = {first_acc_time, second_acc_time};

// Categories for AutocrossEvent
const std::vector<EventCategory> AUTOCROSS_EVENT_CATEGORIES = {first_aut_time, second_aut_time, third_aut_time, fourth_aut_time};
const std::vector<EventCategory> DC_AUTOCROSS_EVENT_CATEGORIES = {first_aut_time, second_aut_time};

// Categories for EnduranceEvent
const std::vector<EventCategory> ENDURANCE_EVENT_CATEGORIES = {end_corrected_time, end_uncorrected_time, end_energy_used, end_energy_produced};

// Categories for EnduranceEvent
const std::vector<EventCategory> TRACKDRIVE_EVENT_CATEGORIES = {tra_time, tra_laps};


const std::map<EventType, std::vector<EventCategory>> CATEGORY_LISTS = {{acceleration, ACCELERATION_EVENT_CATEGORIES},
                                                                            {autocross, AUTOCROSS_EVENT_CATEGORIES},
                                                                            {autocross_DC, DC_AUTOCROSS_EVENT_CATEGORIES},
                                                                            {businessplan, BUSINESSPLAN_EVENT_CATEGORIES},
                                                                            {cost_and_manufacturing, COST_AND_MANUFACTURING_EVENT_CATEGORIES},
                                                                            {endurance, ENDURANCE_EVENT_CATEGORIES},
                                                                            {engineering_design, ENGINEERING_DESIGN_EVENT_CATEGORIES},
                                                                            {skidpad, SKIDPAD_EVENT_CATEGORIES},
                                                                            {engineering_design_DC, DC_ENGINEERING_DESIGN_EVENT_CATEGORIES},
                                                                            {skidpad_DV, SKIDPAD_EVENT_CATEGORIES},
                                                                            {skidpad_DC, SKIDPAD_EVENT_CATEGORIES},
                                                                            {acceleration_DV, ACCELERATION_EVENT_CATEGORIES},
                                                                            {acceleration_DC, ACCELERATION_EVENT_CATEGORIES},
                                                                            {trackdrive, TRACKDRIVE_EVENT_CATEGORIES}};

const std::map<EventType, double> BASE_COMPLETION_POINTS = {{acceleration, 3.5},
                                                            {acceleration_DC, 3.5},
                                                            {acceleration_DV, 0},
                                                            {autocross, 4.5},
                                                            {autocross_DC, 10},
                                                            {endurance, 25},
                                                            {skidpad, 3.5},
                                                            {skidpad_DC, 3.5},
                                                            {skidpad_DV, 0}};