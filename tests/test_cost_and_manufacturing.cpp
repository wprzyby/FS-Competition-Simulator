#include <iostream>
#include <vector>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/CostAndManufacturingEvent.h>



TEST_CASE("CostAndManufacturingEvent tests.", "[Testing all functionalities in case of no finals]")
{
    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 3), team_c("C", "UniveroC", 39), team_d("D", "UniveroD", 4);

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
    CostAndManufacturingEvent cos_event(teams);
    cos_event.simulate();
    std::map<Team, double> cos_results = cos_event.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> cos_correct_results;
    cos_correct_results.insert({team_a, 100.0});
    cos_correct_results.insert({team_b, 98.0});
    cos_correct_results.insert({team_c, 80.0});
    cos_correct_results.insert({team_d, 78.0});
    //

    // Creating and simulating the event in case of finals
    CostAndManufacturingEvent cos_event_finals(teams, 2, {{team_a, 100.0}, {team_b, 97.0}});
    cos_event_finals.simulate();
    std::map<Team, double> cos_results_finals = cos_event_finals.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> cos_correct_results_finals;
    cos_correct_results_finals.insert({team_a, 100.0});
    cos_correct_results_finals.insert({team_b, 97.0});
    cos_correct_results_finals.insert({team_c, 95.0});
    cos_correct_results_finals.insert({team_d, 92.6});

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(cos_results.at(team_a) == cos_correct_results.at(team_a));
        CHECK(cos_results.at(team_b) == cos_correct_results.at(team_b));
        CHECK(cos_results.at(team_c) == cos_correct_results.at(team_c));
        CHECK(cos_results.at(team_d) == cos_correct_results.at(team_d));
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> points_vector = cos_event.get_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector.at(0).second >= points_vector.at(1).second);
        CHECK(points_vector.at(1).second >= points_vector.at(2).second);
        CHECK(points_vector.at(2).second >= points_vector.at(3).second);
        //
    }


    SECTION("Testing: setting results and calculating points - finals")
    {
        CHECK(cos_results_finals.at(team_a) == cos_correct_results_finals.at(team_a));
        CHECK(cos_results_finals.at(team_b) == cos_correct_results_finals.at(team_b));
        CHECK(cos_results_finals.at(team_c) == cos_correct_results_finals.at(team_c));
        CHECK(cos_results_finals.at(team_d) == cos_correct_results_finals.at(team_d));
    }


    SECTION("Testing: making event classification - finals")
    {
        std::vector<double> cos_points_vector_finals;

        std::vector<std::pair<Team, double>> points_vector_finals = cos_event_finals.get_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector_finals.at(0).second >= points_vector_finals.at(1).second);
        CHECK(points_vector_finals.at(1).second >= points_vector_finals.at(2).second);
        CHECK(points_vector_finals.at(2).second >= points_vector_finals.at(3).second);
        //
    }
}