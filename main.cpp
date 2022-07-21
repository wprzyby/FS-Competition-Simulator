#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include <compsim_classes/Competition.h>
#include <compsim_classes/Event.h>
#include <compsim_classes/Team.h>
#include <interface/FileSaver.h>
#include <interface/ui_tools.h>
#include <laptime_parser/LapTimeParser.h>
#include <compsim_enums/enums.h>

#include "constants.h"

int main() {

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
    std::string config_path = DEF_PENALTY_CONFIG_FILE_PATH;

    for (auto& event_type: event_types)
    {
        std::cout<< "--------------------------------------------" << std::endl;
        std::cout<< "Setting results for " << event_type << " event:" << std::endl;

        std::map<Team, std::map<EventsCategories, double>> results = input_event_results(event_type, teams, config_path);
        std::unique_ptr<Event> event = create_event(event_type, teams);
        event->set_results(results);
        events.push_back(std::move(event));
    }

    Competition competition(teams, std::move(events));
    competition.create_classification();
    std::vector<std::pair<Team, double>> final_classification = competition.get_final_classification();

    std::cout<<"--------------------------------------------\n";
    std::cout<<"FINAL CLASSIFICATION\n";

    int idx = 1;
    for(auto& [team, points]: final_classification)
    {
        std::cout<< idx << ". " << team << " -> " << points << "pts" << '\n';
        ++idx;
    }

    std::cout<< "Save classification to file? [y/n]:";
    std::string save_choice;
    std::cin>> save_choice;
    if(save_choice != "y") {return 0;}
    FileSaver saver(std::move(competition), DEFAULT_SAVE_FILE_PATH);
    saver.save_info();

    return 0;
}