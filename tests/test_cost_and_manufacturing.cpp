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
    std::vector<Team> teams{team_a, team_b, team_c, team_d};
    std::map<Team, std::map<EventsCategories, double>> cos_teams_and_results;
    std::map<EventsCategories, double> cos_team_a_results;
    std::map<EventsCategories, double> cos_team_b_results;
    std::map<EventsCategories, double> cos_team_c_results;
    std::map<EventsCategories, double> cos_team_d_results;

    cos_team_a_results.insert({format_and_accuracy_of_documents, 5});
    cos_team_a_results.insert({knowledge_of_documents_and_vehicle, 5});
    cos_team_a_results.insert({BOM_discussion, 35});
    cos_team_a_results.insert({cost_understanding, 35});
    cos_team_a_results.insert({real_case, 20});

    cos_team_b_results.insert({format_and_accuracy_of_documents, 4});
    cos_team_b_results.insert({knowledge_of_documents_and_vehicle, 5});
    cos_team_b_results.insert({BOM_discussion, 34});
    cos_team_b_results.insert({cost_understanding, 35});
    cos_team_b_results.insert({real_case, 20});

    cos_team_c_results.insert({format_and_accuracy_of_documents, 3});
    cos_team_c_results.insert({knowledge_of_documents_and_vehicle, 2});
    cos_team_c_results.insert({BOM_discussion, 30});
    cos_team_c_results.insert({cost_understanding, 28});
    cos_team_c_results.insert({real_case, 17});

    cos_team_d_results.insert({format_and_accuracy_of_documents, 4});
    cos_team_d_results.insert({knowledge_of_documents_and_vehicle, 3});
    cos_team_d_results.insert({BOM_discussion, 27});
    cos_team_d_results.insert({cost_understanding, 29});
    cos_team_d_results.insert({real_case, 15});

    cos_teams_and_results.insert({team_a, cos_team_a_results});
    cos_teams_and_results.insert({team_b, cos_team_b_results});
    cos_teams_and_results.insert({team_c, cos_team_c_results});
    cos_teams_and_results.insert({team_d, cos_team_d_results});

    // Creating and simulating the Event
    CostAndManufacturingEvent cos_event(teams);
    cos_event.set_results(cos_teams_and_results);
    cos_event.simulate();
    std::map<Team, double> cos_results = cos_event.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> cos_correct_results;
    cos_correct_results.insert({team_a, 95.0});
    cos_correct_results.insert({team_b, 93.1});
    cos_correct_results.insert({team_c, 76.0});
    cos_correct_results.insert({team_d, 74.1});
    //

    // Creating and simulating the event in case of finals
    CostAndManufacturingEvent cos_event_finals(teams, 2, {{team_a, 100.0}, {team_b, 97.0}});
    cos_event_finals.set_results(cos_teams_and_results);
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