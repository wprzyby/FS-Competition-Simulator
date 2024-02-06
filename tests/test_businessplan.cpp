#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>
#include <exceptions.h>
#include <enums.h>

#include <EventSimulatorInterface.h>
#include <simulator_factory.h>



TEST_CASE("BusinessPlanEvent tests.")
{
    Team team_a("A"), team_b("B"), team_c("C");

    // 89
    team_a.set_category_result(pitch_video, 9);
    team_a.set_category_result(novelty, 8);
    team_a.set_category_result(content, 17);
    team_a.set_category_result(finances, 7);
    team_a.set_category_result(deep_dive_topic, 10);
    team_a.set_category_result(demonstration_and_structure, 13);
    team_a.set_category_result(delivery, 10);
    team_a.set_category_result(questions, 10);
    team_a.set_category_result(general_impression, 5);

    // 90
    team_b.set_category_result(pitch_video, 8);
    team_b.set_category_result(novelty, 9);
    team_b.set_category_result(content, 19);
    team_b.set_category_result(finances, 10);
    team_b.set_category_result(deep_dive_topic, 10);
    team_b.set_category_result(demonstration_and_structure, 14);
    team_b.set_category_result(delivery, 8);
    team_b.set_category_result(questions, 8);
    team_b.set_category_result(general_impression, 4);

    // 62
    team_c.set_category_result(pitch_video, 4);
    team_c.set_category_result(novelty, 3);
    team_c.set_category_result(content, 12);
    team_c.set_category_result(finances, 8);
    team_c.set_category_result(deep_dive_topic, 6);
    team_c.set_category_result(demonstration_and_structure, 12);
    team_c.set_category_result(delivery, 7);
    team_c.set_category_result(questions, 7);
    team_c.set_category_result(general_impression, 3);

    std::vector<Team> teams{team_a, team_b, team_c};

    // Creating and simulating the Event
    EventSimulatorPtr event_simulator = create_event_simulator(FSG);
    EventResults results = event_simulator->simulate_event(businessplan, teams);
    //

    // Creating map of correct results
    std::map<std::string, double> correct_results;
    correct_results.insert({"A", 69.22});
    correct_results.insert({"B", 70.0});
    correct_results.insert({"C", 48.22});
    //

    team_b.set_category_result(businessplan_finals_score, 72);
    teams = {team_a, team_b, team_c};
    std::map<std::string, double> results_finals = event_simulator->simulate_event(businessplan, teams);
    //

    // Creating map of correct results
    std::map<std::string, double> correct_results_finals;
    correct_results_finals.insert({"A", 70.0});
    correct_results_finals.insert({"B", 72.0});
    correct_results_finals.insert({"C", 48.76});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at("A") == correct_results.at("A"));
        CHECK(results.at("B") == correct_results.at("B"));
        CHECK(results.at("C") == correct_results.at("C"));
    }


    SECTION("Testing: setting results and calculating points - finalists")
    {
        CHECK(results_finals.at("A") == correct_results_finals.at("A"));
        CHECK(results_finals.at("B") == correct_results_finals.at("B"));
        CHECK(results_finals.at("C") == correct_results_finals.at("C"));
    }


}
