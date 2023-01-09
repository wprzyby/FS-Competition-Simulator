#pragma once
#include <string>
#include <vector>
#include <map>
#include <compsim_enums/enums.h>

const constexpr unsigned int MainMenuIndexNumber            = 0;
const constexpr unsigned int SetupScreenIndexNumber         = 1;
const constexpr unsigned int ResultSettingScreenIndexNumber = 2;
const constexpr unsigned int EventResultsScreenIndexNumber  = 3;

const std::string PenaltyConfigFilePath = "../dynamic_events_penalties.json";

// constants handling the special behaviour of Endurance Event - it does not behave in the same way as other dynamic events regarding what is being input by user
// not every Endurance category has possible penalties and not every category result is input by user
const std::vector<EventCategory> ENDURANCE_INPUT_CATEGORIES = {end_uncorrected_time, end_energy_used, end_energy_produced};
const std::map<EventCategory, bool> IS_ENDURANCE_CATEGORY_TIMED = {{end_uncorrected_time, true},
                                                                   {end_energy_used, false},
                                                                   {end_energy_produced, false}};

const std::map<EventType, bool> IS_EVENT_DYNAMIC = {{acceleration, true},
                                                    {autocross, true},
                                                    {businessplan, false},
                                                    {cost_and_manufacturing, false},
                                                    {endurance, true},
                                                    {engineering_design, false},
                                                    {skidpad, true},
                                                    {trackdrive, true},
                                                    {acceleration_DC, true},
                                                    {acceleration_DV, true},
                                                    {autocross_DC, true},
                                                    {engineering_design_DC, false},
                                                    {skidpad_DC, true},
                                                    {skidpad_DV, true}};