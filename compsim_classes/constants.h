#pragma once

#include <compsim_enums/enums.h>
#include <map>
#include <vector>

const std::map<EventType, std::string> INFO_FILE_NAMES = {{acceleration, "AccelerationEventInfo.pdf"},
                                                          {autocross, "AutocrossEventInfo.pdf"},
                                                          {businessplan, "BusinessPlanEventInfo.pdf"},
                                                          {cost_and_manufacturing, "CostAndManufacturingEventInfo.pdf"},
                                                          {endurance, "EnduranceEventInfo.pdf"},
                                                          {engineering_design, "EngineeringDesignEventInfo.pdf"},
                                                          {skidpad, "SkidpadEventInfo.pdf"}};