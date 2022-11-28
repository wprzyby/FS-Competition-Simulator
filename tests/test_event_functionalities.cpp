#include <iostream>
#include <vector>
#include <map>

#include "catch.hpp"
#include <compsim_classes/event_base.h>
#include <events/AccelerationEvent.h>
#include <events/constants.h>
#include <compsim_enums/enums.h>

// TODO: to trzeba wszystko popoprawiać bo teraz po zmianach jest trochę bez sensu

TEST_CASE("General Event Functionalities Tests", "[Based on AccelerationEvent]")
{

    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3), team_d("D", "UniveroD", 4);
    std::vector<Team> teams{team_a, team_b, team_c, team_d};
    AccelerationEvent event(teams);
    //


    // Creating map of results for AccelerationEvent
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

    SECTION("Testing: check_if_category_in_vector() function")
    {
        bool result1 = is_category_in_vector(first_acc_time, ACCELERATION_EVENT_CATEGORIES);
        bool result2 = is_category_in_vector(tractive_system, ACCELERATION_EVENT_CATEGORIES);
        CHECK(result1 == true);
        CHECK(result2 == false);
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
        Team team1("asdas","asdsa", 1), team2("asda2s","asds2a", 2), team3("asd3as","as3dsa", 3), team4("asd4as","4asdsa", 4), team5("asdaadfs","a4sdsa", 5);
        test_map.insert({team1, 4});
        test_map.insert({team2, 4});
        test_map.insert({team3, 0});
        test_map.insert({team4, 4});
        test_map.insert({team5, 0});
        int non_zeros = count_non_zero_times(test_map);
        CHECK(non_zeros == 3);
    }

}