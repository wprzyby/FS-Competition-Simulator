#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>


TEST_CASE("Trackdrive Event tests.")
{
    Team team_a("A"), team_b("B"), team_c("C"), team_d("D"), team_e("E");

    // second best time
    team_a.set_category_result(tra_time, 1200000);
    team_a.set_category_result(tra_laps, 10);
    // best time
    team_b.set_category_result(tra_time, 900000);
    team_b.set_category_result(tra_laps, 10);
    // finished all laps but slower than Tmax
    team_c.set_category_result(tra_time, 1800001);
    team_c.set_category_result(tra_laps, 10);
    // finished all laps but DNF/DQ
    team_d.set_category_result(tra_time, 0);
    team_d.set_category_result(tra_laps, 10);
    // didn't finish all laps
    team_e.set_category_result(tra_time, 0);
    team_e.set_category_result(tra_laps, 4);


    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results = event_simulator->simulate_event(trackdrive, teams);

    std::map<std::string, double> correct_results;
    correct_results.insert({"A", 125.0});
    correct_results.insert({"B", 200.0});
    correct_results.insert({"C", 50.0});
    correct_results.insert({"D", 50.0});
    correct_results.insert({"E", 20.0});

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
        CHECK(results.at("D") == correct_results.at("D"));
        CHECK(results.at("E") == correct_results.at("E"));
    }
}