#include <iostream>
#include <vector>

#include "catch.hpp"
#include "../exceptions.h"
#include "../constants.h"
#include "../base_classes/Team.h"
#include "../events/AccelerationEvent.h"

TEST_CASE("AccelerationEvent tests.", "[Testing all functionalities]")
{

    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3), team_d("D", "UniveroD", 4);
    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    std::map<Team, std::map<EventsCategories, double>> acc_teams_and_results;
    std::map<EventsCategories, double> acc_team_a_results;
    std::map<EventsCategories, double> acc_team_b_results;
    std::map<EventsCategories, double> acc_team_c_results;
    std::map<EventsCategories, double> acc_team_d_results;
    acc_team_a_results.insert({first_acc_time, 12000});
    acc_team_a_results.insert({second_acc_time, 11000});
    acc_team_b_results.insert({first_acc_time, 12000});
    acc_team_b_results.insert({second_acc_time, 13000});
    acc_team_c_results.insert({first_acc_time, 35000});
    acc_team_c_results.insert({second_acc_time, 33000});
    acc_team_d_results.insert({first_acc_time, 0});
    acc_team_d_results.insert({second_acc_time, 0});
    acc_teams_and_results.insert({team_a, acc_team_a_results});
    acc_teams_and_results.insert({team_b, acc_team_b_results});
    acc_teams_and_results.insert({team_c, acc_team_c_results});
    acc_teams_and_results.insert({team_d, acc_team_d_results});

    // Creating and simulating the Event
    AccelerationEvent acc_event(teams);
    acc_event.set_results(acc_teams_and_results);
    acc_event.simulate();
    std::map<Team, double> results = acc_event.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> acc_correct_results;
    acc_correct_results.insert({team_a, 50.0});
    acc_correct_results.insert({team_b, 38.4});
    acc_correct_results.insert({team_c, 3.5});
    acc_correct_results.insert({team_d, 0});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results[team_a] == acc_correct_results[team_a]);
        CHECK(results[team_b] == acc_correct_results[team_b]);
        CHECK(results[team_c] == acc_correct_results[team_c]);
        CHECK(results[team_d] == acc_correct_results[team_d]);
    }


    SECTION("Testing: making event classification")
    {
        std::vector<double> acc_points_vector;

        // Copying sorted points from classification to the vector
        for (auto& [_, it]: results)
        {
            acc_points_vector.push_back(it);
        }
        //

        // Checking whether points are truely sorted:
        CHECK(acc_points_vector[0] >= acc_points_vector[1]);
        CHECK(acc_points_vector[1] >= acc_points_vector[2]);
        CHECK(acc_points_vector[2] >= acc_points_vector[3]);
        //
    }


    SECTION("Testing: EventType and filename getters")
    {
        CHECK(acc_event.get_event_type() == acceleration);
        CHECK(acc_event.get_info_file_name() == "AccelerationEventInfo.pdf");
    }
}
