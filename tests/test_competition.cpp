#include <map>
#include <memory>
#include <vector>

#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/Competition.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>
#include <events/AutocrossEvent.h>
#include <events/EngineeringDesignEvent.h>


TEST_CASE("Competition basic functionality - using Autocross and EngineeringDesign Events")
{


    std::unique_ptr<Event>  autocross_event = std::make_unique<AutocrossEvent>();
    std::unique_ptr<Event> design_event = std::make_unique<EngineeringDesignEvent>();


    Team team_a("a", "univA", 1);
    Team team_b("b", "univB", 2);
    Team team_c("c", "univC", 3);


    // competition.set_teams(teams);

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
    // scores 4.5 points
    team_c.set_category_result(first_aut_time, 150000);
    team_c.set_category_result(second_aut_time, 0);
    team_c.set_category_result(third_aut_time, 200000);
    team_c.set_category_result(fourth_aut_time, 0);

    team_a.set_category_result(overall_vehicle_concept, 0);
    team_a.set_category_result(vehicle_performance, 0);
    team_a.set_category_result(mechanical_structural_engineering, 0);
    team_a.set_category_result(tractive_system, 0);
    team_a.set_category_result(electronics, 0);
    team_a.set_category_result(driver_interface, 0);
    team_a.set_category_result(autonomous_functionality, 0);
    team_a.set_category_result(design_report, 0);

    team_b.set_category_result(overall_vehicle_concept, 5);
    team_b.set_category_result(vehicle_performance, 20);
    team_b.set_category_result(mechanical_structural_engineering, 5);
    team_b.set_category_result(tractive_system, 1);
    team_b.set_category_result(electronics, 15);
    team_b.set_category_result(driver_interface, 0);
    team_b.set_category_result(autonomous_functionality, 5);
    team_b.set_category_result(design_report, 10);

    team_c.set_category_result(overall_vehicle_concept, 30);
    team_c.set_category_result(vehicle_performance, 18);
    team_c.set_category_result(mechanical_structural_engineering, 2);
    team_c.set_category_result(tractive_system, 10);
    team_c.set_category_result(electronics, 5);
    team_c.set_category_result(driver_interface, 10);
    team_c.set_category_result(autonomous_functionality, 20);
    team_c.set_category_result(design_report, 10);

    std::vector<Team> teams = {team_a, team_b, team_c};

    autocross_event->set_teams(teams);
    design_event->set_teams(teams);
    std::map<Team, double> correct_results;

    correct_results.insert({team_a, 100});
    correct_results.insert({team_b, 107.9});
    correct_results.insert({team_c, 109.5});

    std::vector<std::unique_ptr<Event>> events;
    events.push_back(std::move(autocross_event));
    events.push_back(std::move(design_event));

    // competition.set_events(std::move(events));
    Competition competition(teams, std::move(events));
    competition.create_classification();

    SECTION("Checking validity of competition results")
    {
        std::vector<std::pair<Team, double>> classification = competition.get_final_classification();

        CHECK(classification.at(0).first == team_c);
        CHECK(classification.at(1).first == team_b);
        CHECK(classification.at(2).first == team_a);

        CHECK(classification.at(0).second == correct_results.at(team_c));
        CHECK(classification.at(1).second == correct_results.at(team_b));
        CHECK(classification.at(2).second == correct_results.at(team_a));
    }

    SECTION("Checking expected error throws")
    {
        Team duplicate_team("a", "univA", 5);
        teams.push_back(duplicate_team);
        REQUIRE_THROWS(competition.set_teams(teams));
    }

}
