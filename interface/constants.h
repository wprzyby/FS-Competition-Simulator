#pragma once

#include <compsim_enums/enums.h>
#include <map>
#include <vector>

const std::map<EventType, std::string> INFO_EVENT_NAMES = {{acceleration, "Acceleration Event"},
                                                          {autocross, "Autocross Event"},
                                                          {businessplan, "Business Plan Event"},
                                                          {cost_and_manufacturing, "Cost And Manufacturing Event"},
                                                          {endurance, "Endurance Event"},
                                                          {engineering_design, "Engineering Design Event"},
                                                          {skidpad, "Skidpad Event"}};

const std::vector<EventCategory> TIMED_CATEGORIES = {first_skid_left_time, first_skid_right_time, second_skid_left_time, second_skid_right_time, first_acc_time,
                                                        second_acc_time, first_aut_time, second_aut_time, third_aut_time, fourth_aut_time,
                                                        end_corrected_time, end_uncorrected_time};