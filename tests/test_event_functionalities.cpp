#include <iostream>
#include <vector>
#include <string>

#include "catch.hpp"
#include <Team.h>

#include <enums.h>
#include <event_tools.h>


TEST_CASE("General Event Functionalities Tests", "[Based on AccelerationEvent]")
{
    Team team_a("A"), team_b("B"), team_c("C"), team_d("D");
    std::vector<Team> teams{team_a, team_b, team_c, team_d};
    //

    std::map<Team, double> teams_and_best_times;
    teams_and_best_times.insert({team_a, 11000});
    teams_and_best_times.insert({team_b, 12000});
    teams_and_best_times.insert({team_c, 33000});
    teams_and_best_times.insert({team_d, 0});

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
        CHECK(result1 == 1.0);
        CHECK(result2 == 2.0);
        CHECK(result3 == 4.0);
    }

    // SECTION("Testing: find_best_time_for_team() function")
    // {
    //     unsigned int time1 = find_best_time_for_team(acc_team_a_results);
    //     unsigned int time2 = find_best_time_for_team(acc_team_b_results);
    //     unsigned int time3 = find_best_time_for_team(acc_team_c_results);
    //     unsigned int time4 = find_best_time_for_team(acc_team_d_results);
    //     CHECK(time1 == teams_and_best_times.at(team_a));
    //     CHECK(time2 == teams_and_best_times.at(team_b));
    //     CHECK(time3 == teams_and_best_times.at(team_c));
    //     CHECK(time4 == teams_and_best_times.at(team_d));
    // }

    SECTION("Testing: find_best_time_overall() function")
    {

        unsigned int time = find_best_time_overall(teams_and_best_times);
        CHECK(time == 11000);
    }

    // SECTION("Testing: compare() function")
    // {
    //     bool result1 = compare({first_acc_time, 1421412}, {first_acc_time, 1});
    //     bool result2 = compare({first_acc_time, 12}, {first_acc_time, 321321});
    //     CHECK(result1 == false);
    //     CHECK(result2 == true);
    // }

    SECTION("Testing: rd_to_n_places() function")
    {
        double number1 = rd_to_n_places(1.39, 1);
        double number2 = rd_to_n_places(24.581, 2);
        CHECK(number1 == 1.4);
        CHECK(number2 == 24.58);
    }

    SECTION("Testing count_non_zero_times() function")
    {
        std::map<Team, double> test_map;
        Team team1("asdas"), team2("asda2s"), team3("asd3as"), team4("asd4as"), team5("asdaadfs");
        test_map.insert({team1, 4});
        test_map.insert({team2, 4});
        test_map.insert({team3, 0});
        test_map.insert({team4, 4});
        test_map.insert({team5, 0});
        int non_zeros = count_non_zero_times(test_map);
        CHECK(non_zeros == 3);
    }

}