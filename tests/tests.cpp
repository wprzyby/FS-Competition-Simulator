#include <iostream>
#include <vector>

#include "catch.hpp"
#include "../Event_tools.h"
#include "../exceptions.h"
#include "../events/AccelerationEvent.h"
#include "../events/BusinessPlanEvent.h"
#include "../events/CostAndManufacturingEvent.h"
#include "../events/EngineeringDesignEvent.h"
#include "../events/SkidpadEvent.h"
#include "../base_classes/Event.h"
#include "../base_classes/Team.h"
#include "../base_classes/LapTimeParser.h"
#include "../constants.h"


// Creating the event and teams
Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3), team_d("D", "UniveroD", 4);
std::vector<Team> teams{team_a, team_b, team_c, team_d};
AccelerationEvent event(teams);
//


// Creating map of results
std::map<Team, std::map<EventsCategories, double>> teams_and_results;
std::map<EventsCategories, double> team_a_results;
std::map<EventsCategories, double> team_b_results;
team_a_results.insert({first_acc_time, 12000});
team_a_results.insert({second_acc_time, 11000});
team_b_results.insert({first_acc_time, 12000});
team_b_results.insert({second_acc_time, 13000});
team_c_results.insert({first_acc_time, 35000});
team_c_results.insert({second_acc_time, 33000});
team_d_results.insert({first_acc_time, 0});
team_d_results.insert({second_acc_time, 0});
teams_and_results.insert({team_a, team_a_results});
teams_and_results.insert({team_b, team_b_results});
teams_and_results.insert({team_c, team_c_results});
teams_and_results.insert({team_d, team_d_results});
//



TEST_CASE("General_Event_Functionalities_Tests", "[Based_on_AccelerationEvent]")
{
    SECTION("Testing: find_max() function")
    {
        double result = find_max(3, 5);
        CHECK(result == 5);
    }

    SECTION("Tesiting: find_min() function")
    {
        double result1 = find_min(7, 1);
        double result2 = find_min(0, 2);
        double result3 = find_min(4, 0);
        CHECK(result1 == 7);
        CHECK(result2 == 2);
        CHECK(result3 == 3);
    }

    SECTION("Testing: find_best_time_for_team() function")
    {
        unsigned int time1 = find_best_time_for_team(team_a_results);
        unsigned int time2 = find_best_time_for_team(team_d_results);
        CHECK(time1 == 11000);
        CHECK(time2 == 0);
    }

    SECTION("Testing: find_best_time_overall() function")
    {
        unsigned int time = find_best_time_overall(teams_and_results);
        CHECK(time == 11000);
    }

    SECTION("Testing: check_if_category_in_vector() function")
    {
        bool result1 = check_if_category_in_vector(first_acc_time, AccEveCat);
        bool result2 = check_if_category_in_vector(tractive_system, AccEveCat);
        CHECK(result1 == true);
        CHECK(result2 == false);
    }

    SECTION("Testing: compare() function")
    {
        bool result1 = compare({first_acc_time, 1421412}, {first_acc_time, 1});
        bool result2 = compare({first_acc_time, 12}, {first_acc_time, 321321});
        CHECK(result1 == false);
        CHECK(result2 == true);
    }

}
