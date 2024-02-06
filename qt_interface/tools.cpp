#include "tools.h"
#include "qt_interface/constants.h"


std::vector<Team> get_teams_from_items(std::list<TeamListItem *> team_list_items) {
    std::vector<Team> teams;
    for (auto& team_item: team_list_items) {
        teams.push_back(team_item->team);
    }
    return teams;
}