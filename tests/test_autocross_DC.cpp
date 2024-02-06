#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>



TEST_CASE("Autocross DC Event functionality")
{
    Team team_a("A"), team_b("B"), team_c("C"), team_d("D"), team_e("E");


    // fastest
    team_a.set_category_result(first_aut_time, 80000);
    team_a.set_category_result(second_aut_time, 80000);

    // scores additional points
    team_b.set_category_result(first_aut_time, 0);
    team_b.set_category_result(second_aut_time, 90000);

    // scores additional points
    team_c.set_category_result(first_aut_time, 150000);
    team_c.set_category_result(second_aut_time, 0);

    // max time exceeded
    team_d.set_category_result(first_aut_time, 0);
    team_d.set_category_result(second_aut_time, 300000);

    // no runs without DNF
    team_e.set_category_result(first_aut_time, 0);
    team_e.set_category_result(second_aut_time, 0);


    std::map<std::string, double> correct_results;

    correct_results.insert({"A", 100});
    correct_results.insert({"B", 51.25});
    correct_results.insert({"C", 47.5});
    correct_results.insert({"D", 10});
    correct_results.insert({"E", 0});

    std::vector<Team> teams{team_a, team_b, team_c, team_d, team_e};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    event_simulator->set_event_constants({{"dc_autocross_t_6ms", 200000}});
    EventResults results = event_simulator->simulate_event(autocross_DC, teams);

    SECTION("Results of DC simulation")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
        CHECK(results.at("D") == correct_results.at("D"));
        CHECK(results.at("E") == correct_results.at("E"));
    }
}
