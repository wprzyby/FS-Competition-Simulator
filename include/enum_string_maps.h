#pragma once

#include "enums.h"
#include <map>
#include <vector>
#include <string>


const std::map<EventType, std::string> EVENT_TYPE_TO_STRING = {{acceleration, "Acceleration Event"},
                                                               {autocross, "Autocross Event"},
                                                               {businessplan, "Businessplan Event"},
                                                               {cost_and_manufacturing, "Cost and Manufacturing Event"},
                                                               {endurance, "Endurance Event"},
                                                               {engineering_design, "Engineering Design Event"},
                                                               {skidpad, "Skidpad Event"},
                                                               {trackdrive, "Trackdrive Event"},
                                                               {acceleration_DC, "Acceleration Event (DC)"},
                                                               {acceleration_DV, "Acceleration Event (DV)"},
                                                               {autocross_DC, "Autocross Event (DC)"},
                                                               {engineering_design_DC, "Engineering Design (DC)"},
                                                               {skidpad_DC, "Skidpad Event (DC)"},
                                                               {skidpad_DV, "Skidpad Event (DV)"}};


const std::map<EventCategory, std::string> EVENT_CATEGORY_TO_STRING = {{pitch_video, "Pitch video"},
                                                                          {novelty, "Novelty"},
                                                                          {content, "Content"},
                                                                          {finances, "Finances"},
                                                                          {deep_dive_topic, "Deep-dive topic"},
                                                                          {demonstration_and_structure, "Demonstration and structure"},
                                                                          {delivery, "Delivery"},
                                                                          {questions, "Questions"},
                                                                          {general_impression, "General impression"},
                                                                          {format_and_accuracy_of_documents, "Format and accuracy of documents"},
                                                                          {knowledge_of_documents_and_vehicle, "Knowledge of documents and vehicle"},
                                                                          {BOM_discussion, "BOM discussion"},
                                                                          {cost_understanding, "Cost understanding"},
                                                                          {real_case, "Real case"},
                                                                          {overall_vehicle_concept, "Overall vehicle concept"},
                                                                          {vehicle_performance, "Vehicle performance"},
                                                                          {mechanical_structural_engineering, "Mechanical structural engineering"},
                                                                          {tractive_system, "Tractive system"},
                                                                          {electronics, "Electronics"},
                                                                          {driver_interface, "Driver interface"},
                                                                          {autonomous_functionality, "Autonomous functionality"},
                                                                          {design_report, "Design report"},
                                                                          {first_skid_left_time, "First run left time"},
                                                                          {first_skid_right_time, "First run right time"},
                                                                          {second_skid_left_time, "Second run left time"},
                                                                          {second_skid_right_time, "Second run right time"},
                                                                          {first_acc_time, "First run time"},
                                                                          {second_acc_time, "Second run time"},
                                                                          {first_aut_time, "First run time"},
                                                                          {second_aut_time, "Second run time"},
                                                                          {third_aut_time, "Third run time"},
                                                                          {fourth_aut_time, "Fourth run time"},
                                                                          {end_corrected_time, "Corrected time"},
                                                                          {end_uncorrected_time, "Uncorrected time"},
                                                                          {end_energy_used, "Energy used"},
                                                                          {end_energy_produced, "Energy produced"},
                                                                          {tra_time, "Time"},
                                                                          {tra_laps, "Number of laps"},
                                                                          {businessplan_finals_score, "FINALS SCORE (zero or empty means non-finalist"},
                                                                          {cost_and_manufacturing_finals_score, "FINALS SCORE (zero or empty means non-finalist"}};