#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <compsim_enums/enums.h>
#include <map>

// ONLY FOR THE PURPOSE OF READING THE JSON PENALTY CONFIG FILE
const std::map<EventType, std::string> EVENT_ENUM_TO_STR_PENALTY_CONFIG = {{acceleration, "acceleration"},
                                                                     {autocross, "autocross"},
                                                                     {endurance, "endurance"},
                                                                     {skidpad, "skidpad"},
                                                                     {acceleration_DC, "acceleration"},
                                                                     {autocross_DC, "autocross"},
                                                                     {skidpad_DC, "skidpad"},
                                                                     {acceleration_DV, "acceleration"},
                                                                     {skidpad_DV, "skidpad"}};


#endif