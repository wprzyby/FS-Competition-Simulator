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
                                                          {skidpad, "SkidpadEventInfo.pdf"},
                                                          {engineering_design_DC, "EngineeringDesignEventInfo.pdf"},
                                                          {skidpad_DV, "SkidpadEventInfo.pdf"},
                                                          {skidpad_DC, "SkidpadEventInfo.pdf"},
                                                          {acceleration_DV, "AccelerationEventInfo.pdf"},
                                                          {acceleration_DC, "AccelerationEventInfo.pdf"},
                                                          {trackdrive, "TrackEventInfo.pdf"}};