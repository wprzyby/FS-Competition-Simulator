#include <list>
#include <enums.h>
#include <Team.h>
#include "TeamListItem.h"

std::vector<EventCategory> get_event_queries(EventType event_type);
std::vector<Team> get_teams_from_items(std::list<TeamListItem *> team_list_items);