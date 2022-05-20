#include <iostream>
#include <vector>

#include "catch.hpp"
#include "../exceptions.h"
#include "../constants.h"
#include "tests_constants.h"


TEST_CASE("General Event Functionalities Tests", "[Based on AccelerationEvent]")
{
    SECTION("Testing: find_max() function")
    {
        double result = find_max(3, 5);
        CHECK(result == 5);
    }

    SECTION("Tesiting: find_min() function")
    {
        double result1 = find_min(7, 1);
        double result2 = find_min(0, 2);
        double result3 = find_min(4, 0);
        CHECK(result1 == 7);
        CHECK(result2 == 2);
        CHECK(result3 == 3);
    }

    SECTION("Testing: find_best_time_for_team() function")
    {
        unsigned int time1 = find_best_time_for_team(team_a_results);
        unsigned int time2 = find_best_time_for_team(team_d_results);
        CHECK(time1 == 11000);
        CHECK(time2 == 0);
    }

    SECTION("Testing: find_best_time_overall() function")
    {
        unsigned int time = find_best_time_overall(teams_and_results);
        CHECK(time == 11000);
    }

    SECTION("Testing: check_if_category_in_vector() function")
    {
        bool result1 = check_if_category_in_vector(first_acc_time, AccEveCat);
        bool result2 = check_if_category_in_vector(tractive_system, AccEveCat);
        CHECK(result1 == true);
        CHECK(result2 == false);
    }

    SECTION("Testing: compare() function")
    {
        bool result1 = compare({first_acc_time, 1421412}, {first_acc_time, 1});
        bool result2 = compare({first_acc_time, 12}, {first_acc_time, 321321});
        CHECK(result1 == false);
        CHECK(result2 == true);
    }

}


TEST_CASE("AccelerationEvent tests.", "[Testing all functionalities]")
{
    // Creating and simulating the Event
    AccelerationEvent acc_event(teams);
    acc_event.set_results(acc_teams_and_results);
    acc_event.make_event_classification();
    std::map<Team, double> results = acc.event.get_classification();
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


    SECTION("Testing: EVentType and filename getters")
    {
        CHECK(acc_event.get_event_type() == acceleration)
        CHECK(acc_event.get_file_info_name() == "AccelerationEventInfo.pdf")
    }
}


TEST_CASE("SkidpadEvent tests.", "[Testing all functionalities]")
{
    // Creating and simulating the Event
    SkidpadEvent skid_event(teams);
    skid_event.set_results(skid_teams_and_results);
    skid_event.make_event_classification();
    std::map<Team, double> skid_results = skid_event.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> skid_correct_results;
    skid_correct_results.insert({team_a, 10.5});
    skid_correct_results.insert({team_b, 50.0});
    skid_correct_results.insert({team_c, 3.5});
    skid_correct_results.insert({team_d, 23.2});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(skid_results[team_a] == skid_correct_results[team_a]);
        CHECK(skid_results[team_b] == skid_correct_results[team_b]);
        CHECK(skid_results[team_c] == skid_correct_results[team_c]);
        CHECK(skid_results[team_d] == skid_correct_results[team_d]);
    }


    SECTION("Testing: making event classification")
    {
        std::vector<double> skid__points_vector;

        // Copying sorted points from classification to the vector
        for (auto& [_, it]: skid_results)
        {
            skid_points_vector.push_back(it);
        }
        //

        // Checking whether points are truely sorted:
        CHECK(skid_points_vector[0] >= skid_points_vector[1]);
        CHECK(skid_points_vector[1] >= skid_points_vector[2]);
        CHECK(skid_points_vector[2] >= skid_points_vector[3]);
        //
    }


    SECTION("Testing: EVentType and filename getters")
    {
        CHECK(skid_event.get_event_type() == skidpad)
        CHECK(skid_event.get_file_info_name() == "SkidpadEventInfo.pdf")
    }
}