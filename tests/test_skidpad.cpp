#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>


TEST_CASE("SkidpadEvent tests.", "[Non - driverless]")
{
    Team team_a("A"), team_b("B"), team_c("C"), team_d("D");


    team_a.set_category_result(first_skid_left_time, 0);
    team_a.set_category_result(first_skid_right_time, 0);
    team_a.set_category_result(second_skid_left_time, 5702);
    team_a.set_category_result(second_skid_right_time, 4981);


    team_b.set_category_result(first_skid_left_time, 4800);
    team_b.set_category_result(first_skid_right_time, 4800);
    team_b.set_category_result(second_skid_left_time, 4912);
    team_b.set_category_result(second_skid_right_time, 3987);


    team_c.set_category_result(first_skid_left_time, 0);
    team_c.set_category_result(first_skid_right_time, 0);
    team_c.set_category_result(second_skid_left_time, 7053);
    team_c.set_category_result(second_skid_right_time, 7124);


    team_d.set_category_result(first_skid_left_time, 6541);
    team_d.set_category_result(first_skid_right_time, 5432);
    team_d.set_category_result(second_skid_left_time, 4982);
    team_d.set_category_result(second_skid_right_time, 5014);

    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    // Creating and simulating the Event

    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results = event_simulator->simulate_event(skidpad, teams);
    //

    // Creating map of correct results
    std::map<std::string, double> correct_results;
    correct_results.insert({"A", 9.61});
    correct_results.insert({"B", 50.0});
    correct_results.insert({"C", 2.5});
    correct_results.insert({"D", 22.63});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
        CHECK(results.at("D") == correct_results.at("D"));
    }
}