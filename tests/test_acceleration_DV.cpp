#include <iostream>
#include <vector>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/AccelerationEvent.h>


TEST_CASE("AccelerationEvent DV tests.", "[Driverless]")
{

    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 3), team_c("C", "UniveroC", 2), team_d("D", "UniveroD", 4), team_e("E", "UniveroE", 5);


    team_a.set_category_result(first_acc_time, 12000);
    team_a.set_category_result(second_acc_time, 11000);

    team_b.set_category_result(first_acc_time, 12000);
    team_b.set_category_result(second_acc_time, 13000);

    team_c.set_category_result(first_acc_time, 35000);
    team_c.set_category_result(second_acc_time, 33000);

    team_d.set_category_result(first_acc_time, 0);
    team_d.set_category_result(second_acc_time, 0);

    team_e.set_category_result(first_acc_time, 30000);
    team_e.set_category_result(second_acc_time, 26000);

    std::vector<Team> teams{team_a, team_b, team_c, team_d};
    
    // Creating and simulating the Event
    DVAccelerationEvent acc_event(teams);
    acc_event.simulate();
    std::map<Team, double> results = acc_event.get_teams_and_points();
    //

    // Creating map of correct results
    std::map<Team, double> acc_correct_results;
    acc_correct_results.insert({team_a, 75});
    acc_correct_results.insert({team_b, 50});
    acc_correct_results.insert({team_c, 25});
    acc_correct_results.insert({team_d, 0});
    acc_correct_results.insert({team_e, 0});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at(team_a) == acc_correct_results.at(team_a));
        CHECK(results.at(team_b) == acc_correct_results.at(team_b));
        CHECK(results.at(team_c) == acc_correct_results.at(team_c));
        CHECK(results.at(team_d) == acc_correct_results.at(team_d));
        CHECK(results.at(team_e) == acc_correct_results.at(team_e));
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> acc_points_vector = acc_event.get_classification();

        // Checking whether points are truly sorted:
        CHECK(acc_points_vector.at(0).second >= acc_points_vector.at(1).second);
        CHECK(acc_points_vector.at(1).second >= acc_points_vector.at(2).second);
        CHECK(acc_points_vector.at(2).second >= acc_points_vector.at(3).second);
        CHECK(acc_points_vector.at(3).second >= acc_points_vector.at(4).second);
        //
    }
}
