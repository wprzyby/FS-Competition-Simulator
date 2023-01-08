#pragma once
#include <string>
#include <vector>
#include <compsim_enums/enums.h>

const constexpr unsigned int MainMenuIndexNumber            = 0;
const constexpr unsigned int SetupScreenIndexNumber         = 1;
const constexpr unsigned int ResultSettingScreenIndexNumber = 2;
const std::string PenaltyConfigFilePath = "../dynamic_events_penalties.json";

const std::vector<EventCategory> ENDURANCE_INPUT_CATEGORIES = {end_uncorrected_time, end_energy_used, end_energy_produced};