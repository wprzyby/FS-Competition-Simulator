#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/AutocrossEvent.h>

#include <map>
#include <vector>


TEST_CASE("Autocross Event functionality")
{
    AutocrossEvent event;

    Team team_a("a", "univA", 1);
    Team team_b("b", "univB", 3);
    Team team_c("c", "univC", 2);
    Team team_d("d", "univD", 4);
    Team team_e("e", "univE", 5);

    Team duplicate_name_team("a", "univF", 6);
    Team duplicate_univ_team("f", "univA", 7);
    Team duplicate_numb_team("g", "univG", 1);

    // fastest
    team_a.set_category_result(first_aut_time, 80000);
    team_a.set_category_result(second_aut_time, 80000);
    team_a.set_category_result(third_aut_time, 90000);
    team_a.set_category_result(fourth_aut_time, 0);
    // scores additional points
    team_b.set_category_result(first_aut_time, 0);
    team_b.set_category_result(second_aut_time, 90000);
    team_b.set_category_result(third_aut_time, 150000.01);
    team_b.set_category_result(fourth_aut_time, 0);
    // scores base points
    team_c.set_category_result(first_aut_time, 150000);
    team_c.set_category_result(second_aut_time, 0);
    team_c.set_category_result(third_aut_time, 200000);
    team_c.set_category_result(fourth_aut_time, 0);
    // negative times
    team_d.set_category_result(first_aut_time, 0);
    team_d.set_category_result(second_aut_time, 0);
    team_d.set_category_result(third_aut_time, 0);
    team_d.set_category_result(fourth_aut_time, 0);
    // no runs without DNF
    team_e.set_category_result(first_aut_time, 0);
    team_e.set_category_result(second_aut_time, 0);
    team_e.set_category_result(third_aut_time, 0);
    team_e.set_category_result(fourth_aut_time, 0);

    std::map<Team, double> correct_results;

    correct_results.insert({team_a, 100});
    correct_results.insert({team_b, 47.2});
    correct_results.insert({team_c, 5.0});
    correct_results.insert({team_d, 0});
    correct_results.insert({team_e, 0});

    // SECTION("Setting duplicate teams")
    // {
    //     std::vector<Team> teams = {team_a, team_b, team_c, team_d, duplicate_name_team};

    //     REQUIRE_THROWS(event.set_teams(teams));
    //     teams = {team_a, team_b, team_c, team_d, duplicate_numb_team};
    //     REQUIRE_THROWS(event.set_teams(teams));
    //     teams = {team_a, team_b, team_c, team_d, duplicate_univ_team};
    //     REQUIRE_THROWS(event.set_teams(teams));
    // }

    SECTION("Results of simulation")
    {
        std::vector<Team> teams = {team_a, team_b, team_c, team_d, team_e};
        event.set_teams(teams);
        event.simulate();
        std::map<Team, double> classification = event.get_teams_and_points();

        CHECK(correct_results.at(team_a) == classification.at(team_a));
        CHECK(correct_results.at(team_b) == classification.at(team_b));
        CHECK(correct_results.at(team_c) == classification.at(team_c));
        CHECK(correct_results.at(team_d) == classification.at(team_d));
        CHECK(correct_results.at(team_e) == classification.at(team_e));

        // checking if sorted correctly
        std::vector<std::pair<Team, double>> points_vector = event.get_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector.at(0).second >= points_vector.at(1).second);
        CHECK(points_vector.at(1).second >= points_vector.at(2).second);
        CHECK(points_vector.at(2).second >= points_vector.at(3).second);
        CHECK(points_vector.at(3).second >= points_vector.at(4).second);
        //
    }
}



