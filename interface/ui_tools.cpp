#include <algorithm>
#include <ios>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
#include <memory>
#include <stdexcept>

#include "ui_tools.h"
#include "constants.h"

#include <compsim_enums/enums.h>
#include <compsim_classes/Competition.h>
#include <compsim_classes/Event.h>
#include <compsim_classes/Team.h>
#include <laptime_parser/LapTimeParser.h>
#include <events/events.h>
#include <events/constants.h>


std::vector<Team> input_teams()
{
    std::vector<Team> teams = {};
    bool is_done = false;
    std::string name = "";
    std::string university = "";
    unsigned int number = 0;
    std::string choice = "";

    while(!is_done)
    {
        std::cout<< "Name: ";
        std::cin>> name;

        std::cout<< "University: ";
        std::cin>> university;

        std::cout<< "Number: ";
        std::cin>> number;

        Team team(name, university, number);
        teams.push_back(team);

        std::cout<< "Add another team? [y/n]: ";
        std::cin>> choice;

        if(choice != "y") {is_done = true;}
    }

    return teams;
}


std::vector<EventType> input_event_types()
{
    bool is_done = false;
    std::vector<EventType> chosen_events;

    while(!is_done)
    {
        int input_value = 0;
        std::string choice = "";
        std::cout<< "Choose event type to run:" << '\n';
        for (int i = 0; i < static_cast<int>(EventTypeTotalCount); i++)
        {
            auto find_result = std::find(std::begin(chosen_events), std::end(chosen_events), static_cast<EventType>(i));
            if (find_result == std::end(chosen_events))
            {
                std::cout<< i+1 << ". " << static_cast<EventType>(i) << '\n';
            }
        }
        while(true)
        {
            std::cout<< "Type number: ";
            std::cin >> input_value;
            input_value -= 1;
            if (input_value >= static_cast<int>(EventTypeTotalCount) or input_value < 0)
            {
                std::cout<< "Entered number out of scope, please select event type again\n";
            }
            else
            {
                chosen_events.push_back(static_cast<EventType>(input_value));
                break;
            }
        }
        std::cout<< "Choose another event type? [y/n]:";
        std::cin>> choice;
        if(choice != "y") {is_done = true;}
        std::cout<< std::endl;
    }
    return chosen_events;

}


std::map<Team, std::map<EventsCategories, double>> input_event_results(EventType type, std::vector<Team> &teams, std::string config_path)
{
    std::vector<EventsCategories> categories = CATEGORY_LISTS.at(type);
    LapTimeParser parser(config_path, ms);
    std::map<EventsCategories, double> single_team_results;
    std::map<Team, std::map<EventsCategories, double>> results;

    for(auto& team: teams)
    {
        single_team_results.clear();
        std::cout<< "\nEntering results for team " << team << '\n';
        std::cout<< "(For DNF, enter time of 0)" << std::endl;

        for(auto category: categories)
        {
            double input_value = 0;
            std::cout<< '\n' <<  category << ":";
            auto find_result = std::find(std::begin(TIMED_CATEGORIES), std::end(TIMED_CATEGORIES), category);
            if (find_result != std::end(TIMED_CATEGORIES))
            {
                unsigned minutes = 0;
                unsigned seconds = 0;
                unsigned miliseconds = 0;
                unsigned number_of_doo = 0;
                unsigned number_of_oc = 0;
                unsigned number_of_uss = 0;
                std::cout<< "\nMinutes: ";
                std::cin>> minutes;
                std::cout<< "Seconds: ";
                std::cin>> seconds;
                std::cout<< "Miliseconds: ";
                std::cin>> miliseconds;
                std::cout<< "Number of Down-Or-Over occurences (tripping cones): ";
                std::cin>> number_of_doo;
                std::cout<< "Number of Off-Course occurences: ";
                std::cin>> number_of_oc;
                std::cout<< "Number of Unsafe Stop occurences: ";
                std::cin>> number_of_uss;
                input_value = parser.parse_time(type, minutes, seconds, miliseconds, number_of_doo, number_of_oc, number_of_uss);
            }
            else
            {
                std::cin>> input_value;
            }

            single_team_results.insert({category, input_value});
        }

        results.insert({team, single_team_results});
    }

    return results;
}

std::unique_ptr<Event> create_event(EventType type, std::vector<Team> teams)
{
    std::unique_ptr<Event> ret_val;

    switch(type)
    {
        case acceleration:
            ret_val = std::make_unique<AccelerationEvent>(teams);
            break;
        case acceleration_DV:
            ret_val = std::make_unique<DVAccelerationEvent>(teams);
            break;
        case acceleration_DC:
            ret_val = std::make_unique<DCAccelerationEvent>(teams);
            break;
        case autocross:
            ret_val = std::make_unique<AutocrossEvent>(teams);
            break;
        case businessplan:
            ret_val = std::make_unique<BusinessPlanEvent>(teams);
            break;
        case cost_and_manufacturing:
            ret_val = std::make_unique<CostAndManufacturingEvent>(teams);
            break;
        case endurance:
            ret_val = std::make_unique<EnduranceEvent>(teams, true);
            break;
        case engineering_design:
            ret_val = std::make_unique<EngineeringDesignEvent>(teams);
            break;
        case engineering_design_DC:
            ret_val = std::make_unique<DCEngineeringDesignEvent>(teams);
            break;
        case skidpad:
            ret_val = std::make_unique<SkidpadEvent>(teams);
            break;
        case skidpad_DV:
            ret_val = std::make_unique<DVSkidpadEvent>(teams);
            break;
        case skidpad_DC:
            ret_val = std::make_unique<DCSkidpadEvent>(teams);
            break;
        case trackdrive:
            ret_val = std::make_unique<TrackdriveEvent>(teams);
        default:
            throw std::invalid_argument("Invalid event type selected");
    }

    return ret_val;
}

