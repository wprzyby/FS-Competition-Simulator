#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>



TEST_CASE("Endurance Event functionality")
{
    Team team_a("A"), team_b("B"), team_c("C"), team_d("D"), team_e("E");

    // fastest
    team_a.set_category_result(end_corrected_time, 1000000);
    team_a.set_category_result(end_uncorrected_time, 1500000);
    team_a.set_category_result(end_energy_used, 100000);
    team_a.set_category_result(end_energy_produced, 20000);
    // scores additional points in endurance and efficiency
    team_b.set_category_result(end_corrected_time, 1200000);
    team_b.set_category_result(end_uncorrected_time, 1500000);
    team_b.set_category_result(end_energy_used, 100000);
    team_b.set_category_result(end_energy_produced, 30000);
    // scores 25 points endurance, scores negative in efficiency??
    team_c.set_category_result(end_corrected_time, 1333001);
    team_c.set_category_result(end_uncorrected_time, 1600000);
    team_c.set_category_result(end_energy_used, 120000);
    team_c.set_category_result(end_energy_produced, 15000);
    // scores points in endurance, no points in efficiency
    team_d.set_category_result(end_corrected_time, 1300000);
    team_d.set_category_result(end_uncorrected_time, 2000000);
    team_d.set_category_result(end_energy_used, 90000);
    team_d.set_category_result(end_energy_produced, 40000);
    // DNF in endurance
    team_e.set_category_result(end_corrected_time, 0);
    team_e.set_category_result(end_uncorrected_time, 0);
    team_e.set_category_result(end_energy_used, 120000);
    team_e.set_category_result(end_energy_produced, 15000);

    std::map<std::string, double> correct_results_endurance;

    correct_results_endurance.insert({"A", 250});
    correct_results_endurance.insert({"B", 99.89});
    correct_results_endurance.insert({"C", 25});
    correct_results_endurance.insert({"D", 42.15});
    correct_results_endurance.insert({"E", 0});

    std::map<std::string, double> correct_results_efficiency;

    correct_results_efficiency.insert({"A", 56.51});
    correct_results_efficiency.insert({"B", 75});
    correct_results_efficiency.insert({"C", 0});
    correct_results_efficiency.insert({"D", 0});
    correct_results_efficiency.insert({"E", 0});

    std::vector<Team> teams{team_a, team_b, team_c, team_d, team_e};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results_endurance = event_simulator->simulate_event(endurance, teams);
    EventResults results_efficiency = event_simulator->simulate_event(efficiency, teams);


    SECTION("Simulation - endurance only")
    {
        CHECK(results_endurance.at("A") == correct_results_endurance.at("A"));
        CHECK(results_endurance.at("B") == correct_results_endurance.at("B"));
        CHECK(results_endurance.at("C") == correct_results_endurance.at("C"));
        CHECK(results_endurance.at("D") == correct_results_endurance.at("D"));
        CHECK(results_endurance.at("E") == correct_results_endurance.at("E"));
    }

    SECTION("Simulation - endurance and efficiency")
    {
        CHECK(results_efficiency.at("A") == correct_results_efficiency.at("A"));
        CHECK(results_efficiency.at("B") == correct_results_efficiency.at("B"));
        CHECK(results_efficiency.at("C") == correct_results_efficiency.at("C"));
        CHECK(results_efficiency.at("D") == correct_results_efficiency.at("D"));
        CHECK(results_efficiency.at("E") == correct_results_efficiency.at("E"));
    }
}
