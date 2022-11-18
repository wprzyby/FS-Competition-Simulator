#include <iostream>
#include <vector>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/AccelerationEvent.h>


TEST_CASE("AccelerationEvent DV tests.", "[Driverless]")
{

    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 3), team_c("C", "UniveroC", 2), team_d("D", "UniveroD", 4);
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
    DVAccelerationEvent acc_event(teams);
    acc_event.set_results(acc_teams_and_results);
    acc_event.simulate();
    std::map<Team, double> results = acc_event.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> acc_correct_results;
    acc_correct_results.insert({team_a, 75});
    acc_correct_results.insert({team_b, 50});
    acc_correct_results.insert({team_c, 25});
    acc_correct_results.insert({team_d, 0});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at(team_a) == acc_correct_results.at(team_a));
        CHECK(results.at(team_b) == acc_correct_results.at(team_b));
        CHECK(results.at(team_c) == acc_correct_results.at(team_c));
        CHECK(results.at(team_d) == acc_correct_results.at(team_d));
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> acc_points_vector = acc_event.get_classification();

        // Checking whether points are truely sorted:
        CHECK(acc_points_vector.at(0).second >= acc_points_vector.at(1).second);
        CHECK(acc_points_vector.at(1).second >= acc_points_vector.at(2).second);
        CHECK(acc_points_vector.at(2).second >= acc_points_vector.at(3).second);
        //
    }
}
