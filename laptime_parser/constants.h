#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <compsim_enums/enums.h>
#include <map>

const std::map<EventType, std::string> DYNAMIC_EVENT_ENUN_TO_STR = {{acceleration, "acceleration"},
                                                                     {autocross, "autocross"},
                                                                     {endurance, "endurance"},
                                                                     {skidpad, "skidpad"}};


#endif