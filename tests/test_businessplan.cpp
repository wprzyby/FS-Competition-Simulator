#include <iostream>
#include <vector>
#include <map>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/BusinessPlanEvent.h>


TEST_CASE("BusinessPlanEvent tests.")
{
    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3);

    team_a.set_category_result(pitch_video, 9);
    team_a.set_category_result(novelty, 8);
    team_a.set_category_result(content, 17);
    team_a.set_category_result(finances, 7);
    team_a.set_category_result(deep_dive_topic, 10);
    team_a.set_category_result(demonstration_and_structure, 13);
    team_a.set_category_result(delivery, 10);
    team_a.set_category_result(questions, 10);
    team_a.set_category_result(general_impression, 5);

    team_b.set_category_result(pitch_video, 8);
    team_b.set_category_result(novelty, 9);
    team_b.set_category_result(content, 19);
    team_b.set_category_result(finances, 10);
    team_b.set_category_result(deep_dive_topic, 10);
    team_b.set_category_result(demonstration_and_structure, 14);
    team_b.set_category_result(delivery, 8);
    team_b.set_category_result(questions, 8);
    team_b.set_category_result(general_impression, 4);

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
    BusinessPlanEvent bus_event(teams);
    bus_event.simulate();
    std::map<Team, double> bus_results = bus_event.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> bus_correct_results;
    bus_correct_results.insert({team_a, 69.2});
    bus_correct_results.insert({team_b, 70.0});
    bus_correct_results.insert({team_c, 48.2});
    //

    BusinessPlanEvent bus_event_finals(teams, 1, {{team_b, 72.0}});
    bus_event_finals.simulate();
    std::map<Team, double> bus_results_finals = bus_event_finals.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> bus_correct_results_finals;
    bus_correct_results_finals.insert({team_a, 70.0});
    bus_correct_results_finals.insert({team_b, 72.0});
    bus_correct_results_finals.insert({team_c, 48.8});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(bus_results.at(team_a) == bus_correct_results.at(team_a));
        CHECK(bus_results.at(team_b) == bus_correct_results.at(team_b));
        CHECK(bus_results.at(team_c) == bus_correct_results.at(team_c));
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> points_vector = bus_event.get_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector.at(0).second >= points_vector.at(1).second);
        CHECK(points_vector.at(1).second >= points_vector.at(2).second);
        //
    }


    SECTION("Testing: setting results and calculating points - finalists")
    {
        CHECK(bus_results_finals.at(team_a) == bus_correct_results_finals.at(team_a));
        CHECK(bus_results_finals.at(team_b) == bus_correct_results_finals.at(team_b));
        CHECK(bus_results_finals.at(team_c) == bus_correct_results_finals.at(team_c));
    }

    SECTION("Testing: making event classification - finalists")
    {
        std::vector<std::pair<Team, double>> points_vector_finals = bus_event_finals.get_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector_finals.at(0).second >= points_vector_finals.at(1).second);
        CHECK(points_vector_finals.at(1).second >= points_vector_finals.at(2).second);
        //
    }
}
