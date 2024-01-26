#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>

TEST_CASE("Autocross Event functionality")
{

    Team team_a("A"), team_b("B"), team_c("C"), team_d("D"), team_e("E");

    // fastest
    team_a.set_category_result(first_aut_time, 80000);
    team_a.set_category_result(second_aut_time, 80000);
    team_a.set_category_result(third_aut_time, 90000);
    team_a.set_category_result(fourth_aut_time, 0);
    // scores additional points
    team_b.set_category_result(first_aut_time, 0);
    team_b.set_category_result(second_aut_time, 90000);
    team_b.set_category_result(third_aut_time, 150000.01);
    team_b.set_category_result(fourth_aut_time, 0);
    // scores base points
    team_c.set_category_result(first_aut_time, 150000);
    team_c.set_category_result(second_aut_time, 0);
    team_c.set_category_result(third_aut_time, 200000);
    team_c.set_category_result(fourth_aut_time, 0);
    // negative times
    team_d.set_category_result(first_aut_time, 0);
    team_d.set_category_result(second_aut_time, 0);
    team_d.set_category_result(third_aut_time, 0);
    team_d.set_category_result(fourth_aut_time, 0);
    // no runs without DNF
    team_e.set_category_result(first_aut_time, 0);
    team_e.set_category_result(second_aut_time, 0);
    team_e.set_category_result(third_aut_time, 0);
    team_e.set_category_result(fourth_aut_time, 0);

    std::vector<Team> teams{team_a, team_b, team_c, team_d, team_e};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results = event_simulator->simulate_event(autocross, teams);

    std::map<std::string, double> correct_results;

    correct_results.insert({"A", 100});
    correct_results.insert({"B", 47.2});
    correct_results.insert({"C", 5.0});
    correct_results.insert({"D", 0});
    correct_results.insert({"E", 0});


    SECTION("Results of simulation")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
        CHECK(results.at("D") == correct_results.at("D"));
        CHECK(results.at("E") == correct_results.at("E"));
    }
}



