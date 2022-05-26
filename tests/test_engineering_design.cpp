#include "catch.hpp"
#include "../base_classes/Event.h"
#include "../base_classes/Team.h"
#include "../events/EngineeringDesignEvent.h"

#include <map>
#include <vector>

TEST_CASE("Engineering Design Event functionality")
{
    EngineeringDesignEvent event;

    Team team_a("a", "univA", 1);
    Team team_b("b", "univB", 2);
    Team team_c("c", "univC", 3);

    Team duplicate_name_team("a", "univD", 4);
    Team duplicate_univ_team("f", "univA", 5);
    Team duplicate_numb_team("g", "univE", 1);
    Team negative_points_team("d", "univF", 6);
    Team points_over_maximum_team("e", "univG", 7);

    std::map<Team, std::map<EventsCategories, double>> results;

    std::map<EventsCategories, double> team_a_results;
    std::map<EventsCategories, double> team_b_results;
    std::map<EventsCategories, double> team_c_results;
    std::map<EventsCategories, double> negative_points_team_results;
    std::map<EventsCategories, double> points_over_maximum_team_results;

    team_a_results.insert({overall_vehicle_concept, 5});
    team_a_results.insert({vehicle_performance, 20});
    team_a_results.insert({mechanical_structural_engineering, 5});
    team_a_results.insert({tractive_system, 1});
    team_a_results.insert({electronics, 15});
    team_a_results.insert({driver_interface, 0});
    team_a_results.insert({autonomous_functionality, 5});
    team_a_results.insert({design_report, 10});

    team_b_results.insert({overall_vehicle_concept, 30});
    team_b_results.insert({vehicle_performance, 18});
    team_b_results.insert({mechanical_structural_engineering, 2});
    team_b_results.insert({tractive_system, 10});
    team_b_results.insert({electronics, 5});
    team_b_results.insert({driver_interface, 10});
    team_b_results.insert({autonomous_functionality, 20});
    team_b_results.insert({design_report, 10});

    team_c_results.insert({overall_vehicle_concept, 0});
    team_c_results.insert({vehicle_performance, 0});
    team_c_results.insert({mechanical_structural_engineering, 0});
    team_c_results.insert({tractive_system, 0});
    team_c_results.insert({electronics, 0});
    team_c_results.insert({driver_interface, 0});
    team_c_results.insert({autonomous_functionality, 0});
    team_c_results.insert({design_report, 0});

    negative_points_team_results.insert({overall_vehicle_concept, 0});
    negative_points_team_results.insert({vehicle_performance, -1});
    negative_points_team_results.insert({mechanical_structural_engineering, -5});
    negative_points_team_results.insert({tractive_system, 3});
    negative_points_team_results.insert({electronics, 2});
    negative_points_team_results.insert({driver_interface, 0});
    negative_points_team_results.insert({autonomous_functionality, 1});
    negative_points_team_results.insert({design_report, 0});

    points_over_maximum_team_results.insert({overall_vehicle_concept, 40});
    points_over_maximum_team_results.insert({vehicle_performance, 0});
    points_over_maximum_team_results.insert({mechanical_structural_engineering, 20});
    points_over_maximum_team_results.insert({tractive_system, 5});
    points_over_maximum_team_results.insert({electronics, 5});
    points_over_maximum_team_results.insert({driver_interface, 0});
    points_over_maximum_team_results.insert({autonomous_functionality, 1});
    points_over_maximum_team_results.insert({design_report, 0});

    std::map<Team, double> correct_results;

    correct_results.insert({team_a, 61});
    correct_results.insert({team_b, 105});
    correct_results.insert({team_c, 0});

    SECTION("Setting duplicate teams")
    {
        std::vector<Team> teams = {team_a, team_b, team_c, duplicate_name_team};

        REQUIRE_THROWS(event.set_teams(teams));
        teams = {team_a, team_b, team_c, duplicate_numb_team};
        REQUIRE_THROWS(event.set_teams(teams));
        teams = {team_a, team_b, team_c, duplicate_univ_team};
        REQUIRE_THROWS(event.set_teams(teams));
    }

    SECTION("Wrong categories in results")
    {
        Team team_x("x", "univX", 10);
        std::map<EventsCategories, double> team_x_results;
        team_x_results.insert({driver_interface, 100000});
        team_x_results.insert({pitch_video, 5});
        team_x_results.insert({first_acc_time, 100000});
        results.insert({team_x, team_x_results});

        REQUIRE_THROWS(event.set_results(results));
    }

    SECTION("Simulation - correct results")
    {
        std::vector<Team> teams = {team_a, team_b, team_c};
        event.set_teams(teams);
        event.set_results(results);
        event.simulate();
        std::map<Team, double> classification = event.get_classification();

        CHECK(correct_results.at(team_a) == classification.at(team_a));
        CHECK(correct_results.at(team_b) == classification.at(team_b));
        CHECK(correct_results.at(team_c) == classification.at(team_c));

        // checking if sorted correctly
        std::vector<double> sorted_points;
        for(auto& [_, points]: classification)
        {
            sorted_points.push_back(points);
        }
        CHECK(sorted_points[0] >= sorted_points[1]);
        CHECK(sorted_points[1] >= sorted_points[2]);
    }

    SECTION("Setting invalid results - negative points")
    {
        results.insert({negative_points_team, negative_points_team_results});
        REQUIRE_THROWS(event.set_results(results));
    }

    SECTION("Setting invalid results - points over allowed max")
    {
        results.insert({points_over_maximum_team, points_over_maximum_team_results});
        REQUIRE_THROWS(event.set_results(results));
    }

    SECTION("Getters")
    {
        CHECK(event.get_event_type() == engineering_design);
        CHECK(event.get_info_file_name() == "EngineeringDesignEventInfo.pdf");
    }

}