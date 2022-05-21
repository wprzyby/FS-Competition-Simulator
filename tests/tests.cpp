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
    acc_event.calculate_teams_points();
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


    SECTION("Testing: EventType and filename getters")
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
    skid_event.calculate_teams_points();
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
        std::vector<double> skid_points_vector;

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


    SECTION("Testing: EventType and filename getters")
    {
        CHECK(skid_event.get_event_type() == skidpad)
        CHECK(skid_event.get_file_info_name() == "SkidpadEventInfo.pdf")
    }
}




TEST_CASE("BusinessPlanEvent tests.", "[Testing all functionalities in case of no finals]")
{
    // Creating and simulating the Event
    BusinessPlanEvent bus_event(teams);
    bus_event.set_results(bus_teams_and_results);
    bus_event.calculate_teams_points();
    bus_event.make_event_classification();
    std::map<Team, double> bus_results = bus_event.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> bus_correct_results;
    bus_correct_results.insert({team_a, 69.2});
    bus_correct_results.insert({team_b, 70.0});
    bus_correct_results.insert({team_c, 48.2});
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
        CHECK(bus_event.get_event_type() == businessplan)
        CHECK(bus_event.get_file_info_name() == "BusinessPlanEventInfo.pdf")
    }
}




TEST_CASE("BusinessPlanEvent tests.", "[Testing all functionalities in case of finals]")
{
    // Creating and simulating the Event
    BusinessPlanEvent bus_event_finals(teams);
    bus_event_finals.set_results(bus_teams_and_results);
    bus_event_finals.calculate_teams_points(1, {team_b, 72.0});
    bus_event_finals.make_event_classification();
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
        CHECK(bus_results_finals[team_a] == bus_correct_results_finals[team_a]);
        CHECK(bus_results_finals[team_b] == bus_correct_results_finals[team_b]);
        CHECK(bus_results_finals[team_c] == bus_correct_results_finals[team_c]);
    }


    SECTION("Testing: making event classification")
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




TEST_CASE("CostAndManufacturingEvent tests.", "[Testing all functionalities in case of no finals]")
{
    // Creating and simulating the Event
    CostAndManufacturingEvent cos_event(teams);
    cos_event.set_results(cos_teams_and_results);
    cos_event.calculate_teams_points();
    cos_event.make_event_classification();
    std::map<Team, double> cos_results = cos_event.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> cos_correct_results;
    cos_correct_results.insert({team_a, 95.0});
    cos_correct_results.insert({team_b, 93.1});
    cos_correct_results.insert({team_c, 76.0});
    cos_correct_results.insert({team_d, 74.1});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(cos_results[team_a] == cos_correct_results[team_a]);
        CHECK(cos_results[team_b] == cos_correct_results[team_b]);
        CHECK(cos_results[team_c] == cos_correct_results[team_c]);
        CHECK(cos_results[team_d] == cos_correct_results[team_d]);
    }


    SECTION("Testing: making event classification")
    {
        std::vector<double> cos_points_vector;

        // Copying sorted points from classification to the vector
        for (auto& [_, it]: cos_results)
        {
            cos_points_vector.push_back(it);
        }
        //

        // Checking whether points are truely sorted:
        CHECK(cos_points_vector[0] >= cos_points_vector[1]);
        CHECK(cos_points_vector[1] >= cos_points_vector[2]);
        CHECK(cos_points_vector[2] >= cos_points_vector[3]);
        //
    }


    SECTION("Testing: EventType and filename getters")
    {
        CHECK(cos_event.get_event_type() == cost_and_manufacturing)
        CHECK(cos_event.get_file_info_name() == "CostAndManufacturingEventInfo.pdf")
    }
}




TEST_CASE("CostAndManufacturingEventInfo tests.", "[Testing all functionalities in case of finals]")
{
    // Creating and simulating the Event
    CostAndManufacturingEvent cos_event_finals(teams);
    cos_event_finals.set_results(cos_teams_and_results);
    cos_event_finals.calculate_teams_points(2, {(team_a, 100.0), (team_b, 97.0)});
    cos_event_finals.make_event_classification();
    std::map<Team, double> cos_results_finals = cos_event_finals.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> cos_correct_results_finals;
    cos_correct_results_finals.insert({team_a, 100.0});
    cos_correct_results_finals.insert({team_b, 97.0});
    cos_correct_results_finals.insert({team_c, 95.0});
    cos_correct_results_finals.insert({team_c, 92.6});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(cos_results_finals[team_a] == cos_correct_results_finals[team_a]);
        CHECK(cos_results_finals[team_b] == cos_correct_results_finals[team_b]);
        CHECK(cos_results_finals[team_c] == cos_correct_results_finals[team_c]);
        CHECK(cos_results_finals[team_d] == cos_correct_results_finals[team_d]);
    }


    SECTION("Testing: making event classification")
    {
        std::vector<double> cos_points_vector_finals;

        // Copying sorted points from classification to the vector
        for (auto& [_, it]: cos_results_finals)
        {
            cos_points_vector_finals.push_back(it);
        }
        //

        // Checking whether points are truely sorted:
        CHECK(cos_points_vector_finals[0] >= cos_points_vector_finals[1]);
        CHECK(cos_points_vector_finals[1] >= cos_points_vector_finals[2]);
        CHECK(cos_points_vector_finals[2] >= cos_points_vector_finals[3]);
        //
    }
}

//TODO: Endurance, EngineeringDesign, Autocross tests