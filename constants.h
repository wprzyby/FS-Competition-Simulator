#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "enums/enums.h"

#include <iostream>
#include <vector>
#include <map>


const std::map<EventType, std::string> DYNAMIC_EVENT_ENUN_TO_STR = {{acceleration, "acceleration"},
                                                                     {autocross, "autocross"},
                                                                     {endurance, "endurance"},
                                                                     {skidpad, "skidpad"}};


const std::string DEF_PENALTY_DATA_FILE_PATH = "dynamic_events_penalties.json";

const std::map<EventType, std::string> INFO_FILE_NAMES = {{acceleration, "AccelerationEventInfo.pdf"},
                                                          {autocross, "AutocrossEventInfo.pdf"},
                                                          {businessplan, "BusinessPlanEventInfo.pdf"},
                                                          {cost_and_manufacturing, "CostAndManufacturingEventInfo.pdf"},
                                                          {endurance, "EnduranceEventInfo.pdf"},
                                                          {engineering_design, "EngineeringDesignEventInfo.pdf"},
                                                          {skidpad, "SkidpadEventInfo.pdf"}};

// Categories for BusinessPlanEvent
const std::vector<EventsCategories> BuiPlaEveCat = {pitch_video, novelty, content, finances, deep_dive_topic, demonstration_and_structure, delivery, questions, general_impression};

// Categories for CostAndManufacturingEvent
const std::vector<EventsCategories> CosAndManEveCat = {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case};

// Categories for EngineeringDesignEvent
const std::vector<EventsCategories> EngDesEveCat = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engineering, tractive_system, electronics, driver_interface, autonomous_functionality, design_report};

// Categories for SkidpadEvent
const std::vector<EventsCategories> SkidEveCat = {first_left_time, first_right_time, second_left_time, second_right_time, skid_first_time, skid_second_time};

// Categories for AccelerationEvent
const std::vector<EventsCategories> AccEveCat = {first_acc_time, second_acc_time};

// Categories for AutocrossEvent
const std::vector<EventsCategories> AutEveCat = {first_aut_time, second_aut_time, third_aut_time, fourth_aut_time};

// Categories for EnduranceEvent
const std::vector<EventsCategories> EndEveCat = {end_corrected_time, end_uncorrected_time, energy_used, energy_produced};

const std::map<EventType, std::vector<EventsCategories>> category_lists = {{acceleration, AccEveCat},
                                                                            {autocross, AutEveCat},
                                                                            {businessplan, BuiPlaEveCat},
                                                                            {cost_and_manufacturing, CosAndManEveCat},
                                                                            {endurance, EndEveCat},
                                                                            {engineering_design, EngDesEveCat},
                                                                            {skidpad, SkidEveCat}};

#endif