#pragma once

#include <compsim_enums/enums.h>
#include <map>
#include <vector>

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