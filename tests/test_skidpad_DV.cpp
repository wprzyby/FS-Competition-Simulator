#include <iostream>
#include <vector>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/SkidpadEvent.h>


TEST_CASE("SkidpadEvent tests DV.", "[Driverless DV]")
{
    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3), team_d("D", "UniveroD", 4);

    team_a.set_category_result(first_left_time, 0);
    team_a.set_category_result(first_right_time, 0);
    team_a.set_category_result(second_left_time, 5702);
    team_a.set_category_result(second_right_time, 4981);


    team_b.set_category_result(first_left_time, 4800);
    team_b.set_category_result(first_right_time, 4800);
    team_b.set_category_result(second_left_time, 4912);
    team_b.set_category_result(second_right_time, 3987);


    team_c.set_category_result(first_left_time, 0);
    team_c.set_category_result(first_right_time, 0);
    team_c.set_category_result(second_left_time, 7053);
    team_c.set_category_result(second_right_time, 7124);


    team_d.set_category_result(first_left_time, 6541);
    team_d.set_category_result(first_right_time, 5432);
    team_d.set_category_result(second_left_time, 4982);
    team_d.set_category_result(second_right_time, 5014);

    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    // Creating and simulating the Event
    DVSkidpadEvent skid_event(teams);
    skid_event.simulate();
    std::map<Team, double> skid_results = skid_event.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> skid_correct_results;
    skid_correct_results.insert({team_a, 37.5});
    skid_correct_results.insert({team_b, 75});
    skid_correct_results.insert({team_c, 18.8});
    skid_correct_results.insert({team_d, 56.3});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(skid_results.at(team_a) == skid_correct_results.at(team_a));
        CHECK(skid_results.at(team_b) == skid_correct_results.at(team_b));
        CHECK(skid_results.at(team_c) == skid_correct_results.at(team_c));
        CHECK(skid_results.at(team_d) == skid_correct_results.at(team_d));
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> points_vector = skid_event.get_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector[0].second >= points_vector[1].second);
        CHECK(points_vector[1].second >= points_vector[2].second);
        //
    }
}
