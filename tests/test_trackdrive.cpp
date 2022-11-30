#include <iostream>
#include <vector>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/TrackdriveEvent.h>


TEST_CASE("Trackdrive Event tests.")
{
    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3), team_d("D", "UniveroD", 4), team_e("E", "UniveroE", 5);

    // second best time
    team_a.set_category_result(tra_time, 1200000);
    team_a.set_category_result(tra_laps, 10);
    // best time
    team_b.set_category_result(tra_time, 900000);
    team_b.set_category_result(tra_laps, 10);
    // finished all laps but slower than Tmax
    team_c.set_category_result(tra_time, 1800001);
    team_c.set_category_result(tra_laps, 10);
    // finished all laps but DNF/DQ
    team_d.set_category_result(tra_time, 0);
    team_d.set_category_result(tra_laps, 10);
    // didn't finish all laps
    team_e.set_category_result(tra_time, 0);
    team_e.set_category_result(tra_laps, 4);


    std::vector<Team> teams{team_a, team_b, team_c, team_d, team_e};

    TrackdriveEvent event(teams);
    event.simulate();
    std::map<Team, double> results = event.get_teams_and_points();

    std::map<Team, double> correct_results;
    correct_results.insert({team_a, 125.0});
    correct_results.insert({team_b, 200.0});
    correct_results.insert({team_c, 50.0});
    correct_results.insert({team_d, 50.0});
    correct_results.insert({team_e, 20.0});

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(results.at(team_a) == correct_results.at(team_a));
        CHECK(results.at(team_b) == correct_results.at(team_b));
        CHECK(results.at(team_c) == correct_results.at(team_c));
        CHECK(results.at(team_d) == correct_results.at(team_d));
        CHECK(results.at(team_e) == correct_results.at(team_e));
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> points_vector = event.get_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector.at(0).second >= points_vector.at(1).second);
        CHECK(points_vector.at(1).second >= points_vector.at(2).second);
        CHECK(points_vector.at(2).second >= points_vector.at(3).second);
        CHECK(points_vector.at(3).second >= points_vector.at(4).second);
        //
    }
}