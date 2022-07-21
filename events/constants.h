#pragma once

#include <compsim_enums/enums.h>
#include <map>
#include <vector>

// Categories for BusinessPlanEvent
const std::vector<EventsCategories> BuiPlaEveCat = {pitch_video, novelty, content, finances, deep_dive_topic, demonstration_and_structure, delivery, questions, general_impression};

// Categories for CostAndManufacturingEvent
const std::vector<EventsCategories> CosAndManEveCat = {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case};

// Categories for EngineeringDesignEvent
const std::vector<EventsCategories> EngDesEveCat = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, driver_interface, autonomous_functionality, design_report};

// Categories for SkidpadEvent
const std::vector<EventsCategories> SkidEveCat = {first_left_time, first_right_time, second_left_time, second_right_time};

// Categories for AccelerationEvent
const std::vector<EventsCategories> AccEveCat = {first_acc_time, second_acc_time};

// Categories for AutocrossEvent
const std::vector<EventsCategories> AutEveCat = {first_aut_time, second_aut_time, third_aut_time, fourth_aut_time};

// Categories for EnduranceEvent
const std::vector<EventsCategories> EndEveCat = {end_corrected_time, end_uncorrected_time, energy_used, energy_produced};

const std::map<EventType, std::vector<EventsCategories>> CATEGORY_LISTS = {{acceleration, AccEveCat},
                                                                            {autocross, AutEveCat},
                                                                            {businessplan, BuiPlaEveCat},
                                                                            {cost_and_manufacturing, CosAndManEveCat},
                                                                            {endurance, EndEveCat},
                                                                            {engineering_design, EngDesEveCat},
                                                                            {skidpad, SkidEveCat}};

const std::map<EventType, double> BASE_COMPLETION_POINTS = {{acceleration, 3.5},
                                                            {autocross, 4.5},
                                                            {endurance, 25},
                                                            {skidpad, 3.5}};

