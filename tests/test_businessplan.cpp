#include <iostream>
#include <vector>
#include <map>

#include "catch.hpp"
#include "../events/BusinessPlanEvent.h"
#include "../base_classes/Team.h"
#include "../exceptions.h"
#include "../constants.h"


TEST_CASE("BusinessPlanEvent tests.")
{
    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3), team_d("D", "UniveroD", 4);
    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    std::map<Team, std::map<EventsCategories, double>> bus_teams_and_results;
    std::map<EventsCategories, double> bus_team_a_results;
    std::map<EventsCategories, double> bus_team_b_results;
    std::map<EventsCategories, double> bus_team_c_results;

    bus_team_a_results.insert({pitch_video, 9});
    bus_team_a_results.insert({novelty, 8});
    bus_team_a_results.insert({content, 17});
    bus_team_a_results.insert({finances, 7});
    bus_team_a_results.insert({deep_dive_topic, 10});
    bus_team_a_results.insert({demontration_and_structure, 13});
    bus_team_a_results.insert({delivery, 10});
    bus_team_a_results.insert({questions, 10});
    bus_team_a_results.insert({general_impression, 5});

    bus_team_b_results.insert({pitch_video, 8});
    bus_team_b_results.insert({novelty, 9});
    bus_team_b_results.insert({content, 19});
    bus_team_b_results.insert({finances, 10});
    bus_team_b_results.insert({deep_dive_topic, 10});
    bus_team_b_results.insert({demontration_and_structure, 14});
    bus_team_b_results.insert({delivery, 8});
    bus_team_b_results.insert({questions, 8});
    bus_team_b_results.insert({general_impression, 4});

    bus_team_c_results.insert({pitch_video, 4});
    bus_team_c_results.insert({novelty, 3});
    bus_team_c_results.insert({content, 12});
    bus_team_c_results.insert({finances, 8});
    bus_team_c_results.insert({deep_dive_topic, 6});
    bus_team_c_results.insert({demontration_and_structure, 12});
    bus_team_c_results.insert({delivery, 7});
    bus_team_c_results.insert({questions, 7});
    bus_team_c_results.insert({general_impression, 3});

    bus_teams_and_results.insert({team_a, bus_team_a_results});
    bus_teams_and_results.insert({team_b, bus_team_b_results});
    bus_teams_and_results.insert({team_c, bus_team_c_results});

    // Creating and simulating the Event
    BusinessPlanEvent bus_event(teams);
    bus_event.set_results(bus_teams_and_results);
    bus_event.simulate();
    std::map<Team, double> bus_results = bus_event.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> bus_correct_results;
    bus_correct_results.insert({team_a, 69.2});
    bus_correct_results.insert({team_b, 70.0});
    bus_correct_results.insert({team_c, 48.2});
    //

    BusinessPlanEvent bus_event_finals(teams, 1, {{team_b, 72.0}});
    bus_event_finals.set_results(bus_teams_and_results);
    bus_event_finals.simulate();
    std::map<Team, double> bus_results_finals = bus_event_finals.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> bus_correct_results_finals;
    bus_correct_results_finals.insert({team_a, 70.0});
    bus_correct_results_finals.insert({team_b, 72.0});
    bus_correct_results_finals.insert({team_c, 48.8});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(bus_results[team_a] == bus_correct_results[team_a]);
        CHECK(bus_results[team_b] == bus_correct_results[team_b]);
        CHECK(bus_results[team_c] == bus_correct_results[team_c]);
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> points_vector = bus_event.get_sorted_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector[0].second >= points_vector[1].second);
        CHECK(points_vector[1].second >= points_vector[2].second);
        //
    }


    SECTION("Testing: EventType and filename getters")
    {
        CHECK(bus_event.get_event_type() == businessplan);
        CHECK(bus_event.get_info_file_name() == "BusinessPlanEventInfo.pdf");
    }

    SECTION("Testing: setting results and calculating points - finalists")
    {
        CHECK(bus_results_finals[team_a] == bus_correct_results_finals[team_a]);
        CHECK(bus_results_finals[team_b] == bus_correct_results_finals[team_b]);
        CHECK(bus_results_finals[team_c] == bus_correct_results_finals[team_c]);
    }

    SECTION("Testing: making event classification - finalists")
    {
        std::vector<std::pair<Team, double>> points_vector_finals = bus_event_finals.get_sorted_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector_finals[0].second >= points_vector_finals[1].second);
        CHECK(points_vector_finals[1].second >= points_vector_finals[2].second);
        //
    }
}
