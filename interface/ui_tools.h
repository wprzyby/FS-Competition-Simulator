#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include <compsim_classes/Event.h>
#include <compsim_classes/Team.h>
#include <compsim_enums/enums.h>
#include "constants.h"


std::vector<Team> input_teams();
std::vector<EventType> input_event_types();
std::map<Team, std::map<EventsCategories, double>> input_event_results(EventType type, std::vector<Team> &teams, std::string config_path);
std::unique_ptr<Event> create_event(EventType type, std::vector<Team> teams);
