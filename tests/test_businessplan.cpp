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
    // FIXME
    BusinessPlanEvent bus_event(teams, 1, {team_b, 72.0});
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

    BusinessPlanEvent bus_event_finals(teams);
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
        std::vector<double> bus_points_vector;

        // Copying sorted points from classification to the vector
        for (auto& [_, it]: bus_results)
        {
            bus_points_vector.push_back(it);
        }
        //

        // Checking whether points are truely sorted:
        CHECK(bus_points_vector[0] >= bus_points_vector[1]);
        CHECK(bus_points_vector[1] >= bus_points_vector[2]);
        CHECK(bus_points_vector[2] >= bus_points_vector[3]);
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
        std::vector<double> bus_points_vector_finals;

        // Copying sorted points from classification to the vector
        for (auto& [_, it]: bus_results_finals)
        {
            bus_points_vector_finals.push_back(it);
        }
        //

        // Checking whether points are truely sorted:
        CHECK(bus_points_vector_finals[0] >= bus_points_vector_finals[1]);
        CHECK(bus_points_vector_finals[1] >= bus_points_vector_finals[2]);
        //
    }
}


// jakby mnie pojebało:

// TEST_CASE("BusinessPlanEvent tests.", "[Testing all functionalities in case of finals]")
// {
//     // Creating and simulating the Event
//     BusinessPlanEvent bus_event_finals(teams);
//     bus_event_finals.set_results(bus_teams_and_results);
//     bus_event_finals.calculate_teams_points(1, {team_b, 72.0});
//     bus_event_finals.make_event_classification();
//     std::map<Team, double> bus_results_finals = bus_event_finals.get_classification();
//     //

//     // Creating map of correct results
//     std::map<Team, double> bus_correct_results_finals;
//     bus_correct_results_finals.insert({team_a, 70.0});
//     bus_correct_results_finals.insert({team_b, 72.0});
//     bus_correct_results_finals.insert({team_c, 48.8});
//     //

//     SECTION("Testing: setting results and calculating points")
//     {
//         CHECK(bus_results_finals[team_a] == bus_correct_results_finals[team_a]);
//         CHECK(bus_results_finals[team_b] == bus_correct_results_finals[team_b]);
//         CHECK(bus_results_finals[team_c] == bus_correct_results_finals[team_c]);
//     }


//     SECTION("Testing: making event classification")
//     {
//         std::vector<double> bus_points_vector_finals;

//         // Copying sorted points from classification to the vector
//         for (auto& [_, it]: bus_results_finals)
//         {
//             bus_points_vector_finals.push_back(it);
//         }
//         //

//         // Checking whether points are truely sorted:
//         CHECK(bus_points_vector_finals[0] >= bus_points_vector_finals[1]);
//         CHECK(bus_points_vector_finals[1] >= bus_points_vector_finals[2]);
//         //
//     }
// }