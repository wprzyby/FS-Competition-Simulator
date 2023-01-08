#include <map>
#include <vector>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/EngineeringDesignEvent.h>


TEST_CASE("Engineering Design Event DV functionality")
{
    DCEngineeringDesignEvent event;

    Team team_a("a", "univA", 1);
    Team team_b("b", "univB", 2);
    Team team_c("c", "univC", 3);

    Team duplicate_name_team("a", "univD", 4);
    Team duplicate_univ_team("f", "univA", 5);
    Team duplicate_numb_team("g", "univE", 1);
    Team negative_points_team("d", "univF", 6);
    Team points_over_maximum_team("e", "univG", 7);

    std::map<Team, std::map<EventCategory, double>> results;

    team_a.set_category_result(overall_vehicle_concept, 5);
    team_a.set_category_result(vehicle_performance, 20);
    team_a.set_category_result(mechanical_structural_engineering, 5);
    team_a.set_category_result(tractive_system, 1);
    team_a.set_category_result(electronics, 15);
    team_a.set_category_result(autonomous_functionality, 5);

    team_b.set_category_result(overall_vehicle_concept, 30);
    team_b.set_category_result(vehicle_performance, 18);
    team_b.set_category_result(mechanical_structural_engineering, 2);
    team_b.set_category_result(tractive_system, 10);
    team_b.set_category_result(electronics, 5);
    team_b.set_category_result(autonomous_functionality, 20);

    team_c.set_category_result(overall_vehicle_concept, 0);
    team_c.set_category_result(vehicle_performance, 0);
    team_c.set_category_result(mechanical_structural_engineering, 0);
    team_c.set_category_result(tractive_system, 0);
    team_c.set_category_result(electronics, 0);
    team_c.set_category_result(autonomous_functionality, 0);

    negative_points_team.set_category_result(overall_vehicle_concept, 0);
    negative_points_team.set_category_result(vehicle_performance, -1);
    negative_points_team.set_category_result(mechanical_structural_engineering, -5);
    negative_points_team.set_category_result(tractive_system, 3);
    negative_points_team.set_category_result(electronics, 2);
    negative_points_team.set_category_result(autonomous_functionality, 1);

    points_over_maximum_team.set_category_result(overall_vehicle_concept, 40);
    points_over_maximum_team.set_category_result(vehicle_performance, 0);
    points_over_maximum_team.set_category_result(mechanical_structural_engineering, 20);
    points_over_maximum_team.set_category_result(tractive_system, 5);
    points_over_maximum_team.set_category_result(electronics, 5);
    points_over_maximum_team.set_category_result(autonomous_functionality, 1);

    std::map<Team, double> correct_results;

    correct_results.insert({team_a, 51});
    correct_results.insert({team_b, 85});
    correct_results.insert({team_c, 0.0});

    // SECTION("Setting duplicate teams")
    // {
    //     std::vector<Team> teams = {team_a, team_b, team_c, duplicate_name_team};  // FIXME

    //     REQUIRE_THROWS(event.set_teams(teams));
    //     teams = {team_a, team_b, team_c, duplicate_numb_team};
    //     REQUIRE_THROWS(event.set_teams(teams));
    //     teams = {team_a, team_b, team_c, duplicate_univ_team};
    //     REQUIRE_THROWS(event.set_teams(teams));
    // }

    // TODO: ten sam problem co w innych, nie będzie działać
    // SECTION("Wrong categories in results")
    // {
    //     Team team_x("x", "univX", 10);
    //     std::map<EventsCategories, double> team_x_results;
    //     team_x_results.insert({vehicle_performance, 100000});
    //     team_x_results.insert({pitch_video, 5});
    //     team_x_results.insert({first_acc_time, 100000});
    //     results.insert({team_x, team_x_results});

    //     REQUIRE_THROWS(event.set_results(results));
    // }

    SECTION("Simulation - correct results")
    {
        std::vector<Team> teams = {team_a, team_b, team_c};
        event.set_teams(teams);
        event.simulate();
        std::map<Team, double> classification = event.get_teams_and_points();

        CHECK(correct_results.at(team_a) == classification.at(team_a));
        CHECK(correct_results.at(team_b) == classification.at(team_b));
        CHECK(correct_results.at(team_c) == classification.at(team_c));

        // checking if sorted correctly
        std::vector<std::pair<Team, double>> points_vector = event.get_classification();

        // Checking whether points are truly sorted:
        CHECK(points_vector.at(0).second >= points_vector.at(1).second);
        CHECK(points_vector.at(1).second >= points_vector.at(2).second);
        //
    }
}