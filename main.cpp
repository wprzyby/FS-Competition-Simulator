#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "base_classes/Competition.h"
#include "base_classes/Event.h"
#include "base_classes/LapTimeParser.h"
#include "base_classes/Team.h"

#include "ui_tools.h"
#include "enums/enums.h"
#include "constants.h"

int main() {
    // 1. Witaj, podaj drużyny
    std::vector<Team> teams = {};
    std::vector<EventType> event_types = {};
    std::vector<std::unique_ptr<Event>> events;

    std::cout<< "FORMULA STUDENT COMPETITION SIMULATOR (2022)" << '\n';
    std::cout<< "--------------------------------------------" << '\n';
    std::cout<< "ENTERING TEAMS:" << std::endl;
    teams = input_teams();

    std::cout<< "--------------------------------------------" << '\n';
    std::cout<< "EVENT TYPES:" << std::endl;

    event_types = input_event_types();

    for (auto& event_type: event_types)
    {
        std::cout<< "--------------------------------------------" << std::endl;
        std::cout<< "Setting results for " << event_type << " event:" << std::endl;
        std::map<Team, std::map<EventsCategories, double>> results = input_event_results(event_type, teams);
        std::unique_ptr<Event> event = create_event(event_type, teams);
        event->set_results(results);
        events.push_back(std::move(event));
    }

    Competition competition(teams, std::move(events));
    competition.create_classification();
    std::vector<std::pair<Team, double>> final_classification = competition.get_final_classification();

    int idx = 1;
    for(auto& [team, points]: final_classification)
    {
        std::cout<< idx << ". " << team << " -> " << points << "pts" << '\n';
        ++idx;
    }

    return 0;
}