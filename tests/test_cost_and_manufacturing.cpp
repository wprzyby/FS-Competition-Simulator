#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>



TEST_CASE("CostAndManufacturingEvent tests.", "[Testing all functionalities in case of no finals]")
{
    Team team_a("A"), team_b("B"), team_c("C"), team_d("D");

    team_a.set_category_result(format_and_accuracy_of_documents, 5);
    team_a.set_category_result(knowledge_of_documents_and_vehicle, 5);
    team_a.set_category_result(BOM_discussion, 35);
    team_a.set_category_result(cost_understanding, 35);
    team_a.set_category_result(real_case, 20);

    team_b.set_category_result(format_and_accuracy_of_documents, 4);
    team_b.set_category_result(knowledge_of_documents_and_vehicle, 5);
    team_b.set_category_result(BOM_discussion, 34);
    team_b.set_category_result(cost_understanding, 35);
    team_b.set_category_result(real_case, 20);

    team_c.set_category_result(format_and_accuracy_of_documents, 3);
    team_c.set_category_result(knowledge_of_documents_and_vehicle, 2);
    team_c.set_category_result(BOM_discussion, 30);
    team_c.set_category_result(cost_understanding, 28);
    team_c.set_category_result(real_case, 17);

    team_d.set_category_result(format_and_accuracy_of_documents, 4);
    team_d.set_category_result(knowledge_of_documents_and_vehicle, 3);
    team_d.set_category_result(BOM_discussion, 27);
    team_d.set_category_result(cost_understanding, 29);
    team_d.set_category_result(real_case, 15);

    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results = event_simulator->simulate_event(cost_and_manufacturing, teams);
    //

    // Creating map of correct results
    std::map<std::string, double> correct_results;
    correct_results.insert({"A", 100.0});
    correct_results.insert({"B", 98.0});
    correct_results.insert({"C", 80.0});
    correct_results.insert({"D", 78.0});
    //

    // Creating and simulating the event in case of finals
    team_a.set_category_result(cost_and_manufacturing_finals_score, 100);
    team_b.set_category_result(cost_and_manufacturing_finals_score, 97);
    teams = {team_a, team_b, team_c, team_d};
    EventResults results_finals = event_simulator->simulate_event(cost_and_manufacturing, teams);

    //

    // Creating map of correct results
    std::map<std::string, double> correct_results_finals;
    correct_results_finals.insert({"A", 100.0});
    correct_results_finals.insert({"B", 97.0});
    correct_results_finals.insert({"C", 95.0});
    correct_results_finals.insert({"D", 92.63});

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
        CHECK(results.at("D") == correct_results.at("D"));
    }


    SECTION("Testing: setting results and calculating points - finals")
    {
        CHECK(results_finals.at("A") == correct_results_finals.at("A"));
        CHECK(results_finals.at("B") == correct_results_finals.at("B"));
        CHECK(results_finals.at("C") == correct_results_finals.at("C"));
        CHECK(results_finals.at("D") == correct_results_finals.at("D"));
    }
}