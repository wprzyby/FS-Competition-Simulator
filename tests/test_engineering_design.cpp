#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>

TEST_CASE("Engineering Design Event functionality")
{
    Team team_a("A"), team_b("B"), team_c("C");

    team_a.set_category_result(overall_vehicle_concept, 5);
    team_a.set_category_result(vehicle_performance, 20);
    team_a.set_category_result(mechanical_structural_engineering, 5);
    team_a.set_category_result(tractive_system, 1);
    team_a.set_category_result(electronics, 15);
    team_a.set_category_result(driver_interface, 0);
    team_a.set_category_result(autonomous_functionality, 5);
    team_a.set_category_result(design_report, 10);

    team_b.set_category_result(overall_vehicle_concept, 30);
    team_b.set_category_result(vehicle_performance, 18);
    team_b.set_category_result(mechanical_structural_engineering, 2);
    team_b.set_category_result(tractive_system, 10);
    team_b.set_category_result(electronics, 5);
    team_b.set_category_result(driver_interface, 10);
    team_b.set_category_result(autonomous_functionality, 20);
    team_b.set_category_result(design_report, 10);

    team_c.set_category_result(overall_vehicle_concept, 0);
    team_c.set_category_result(vehicle_performance, 0);
    team_c.set_category_result(mechanical_structural_engineering, 0);
    team_c.set_category_result(tractive_system, 0);
    team_c.set_category_result(electronics, 0);
    team_c.set_category_result(driver_interface, 0);
    team_c.set_category_result(autonomous_functionality, 0);
    team_c.set_category_result(design_report, 0);

    std::map<std::string, double> correct_results;

    correct_results.insert({"A", 61});
    correct_results.insert({"B", 105});
    correct_results.insert({"C", 0.0});

    std::vector<Team> teams{team_a, team_b, team_c};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results = event_simulator->simulate_event(engineering_design, teams);


    SECTION("Simulation - correct results")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
    }
}
