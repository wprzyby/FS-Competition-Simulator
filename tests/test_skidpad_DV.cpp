#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>


TEST_CASE("SkidpadEvent tests DV.", "[Driverless DV]")
{
    Team team_a("A"), team_b("B"), team_c("C"), team_d("D"), team_e("E");

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

    // DQ due to exceeded 25s threshold
    team_e.set_category_result(first_skid_left_time, 25000);
    team_e.set_category_result(first_skid_right_time, 26000);
    team_e.set_category_result(second_skid_left_time, 30000);
    team_e.set_category_result(second_skid_right_time, 30000);

    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results = event_simulator->simulate_event(skidpad_DV, teams);


    // Creating map of correct results
    std::map<std::string, double> correct_results;
    correct_results.insert({"A", 37.5});
    correct_results.insert({"B", 75});
    correct_results.insert({"C", 18.8});
    correct_results.insert({"D", 56.3});
    correct_results.insert({"E", 0});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
        CHECK(results.at("D") == correct_results.at("D"));
        CHECK(results.at("E") == correct_results.at("E"));
    }
}
