#ifndef UI_TOOLS_H
#define UI_TOOLS_H

#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include "../base_classes/Event.h"
#include "../base_classes/Team.h"
#include "../enums/enums.h"
#include "../constants.h"


std::vector<Team> input_teams();
std::vector<EventType> input_event_types();
std::map<Team, std::map<EventsCategories, double>> input_event_results(EventType type, std::vector<Team> &teams);
std::unique_ptr<Event> create_event(EventType type, std::vector<Team> teams);



#endif