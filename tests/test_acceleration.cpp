#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>


TEST_CASE("AccelerationEvent tests.", "[Non - driverless]")
{

    Team team_a("A"), team_b("B"), team_c("C"), team_d("D");

    team_a.set_category_result(first_acc_time, 12000);
    team_a.set_category_result(second_acc_time, 11000);

    team_b.set_category_result(first_acc_time, 12000);
    team_b.set_category_result(second_acc_time, 13000);

    team_c.set_category_result(first_acc_time, 35000);
    team_c.set_category_result(second_acc_time, 17000);

    team_d.set_category_result(first_acc_time, 0);
    team_d.set_category_result(second_acc_time, 0);

    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    // Creating and simulating the Event
        EventSimulatorPtr event_simulator = create_event_simulator(FSG);
        EventResults results = event_simulator->simulate_event(acceleration, teams);
    //

    // Creating map of correct results
    std::map<std::string, double> correct_results;
    correct_results.insert({"A", 50.0});
    correct_results.insert({"B", 38.13});
    correct_results.insert({"C", 2.5});
    correct_results.insert({"D", 0});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
        CHECK(results.at("D") == correct_results.at("D"));
    }
}
