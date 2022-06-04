#include "catch.hpp"
#include "../base_classes/Event.h"
#include "../base_classes/Team.h"
#include "../base_classes/Competition.h"
#include "../events/AutocrossEvent.h"
#include "../events/EngineeringDesignEvent.h"

#include <map>
#include <memory>
#include <vector>

TEST_CASE("Competition basic functionality - using Autocross and EngineeringDesign Events")
{
    Competition competition;

    std::unique_ptr<Event>  autocross_event = std::make_unique<AutocrossEvent>();
    std::unique_ptr<Event> design_event = std::make_unique<EngineeringDesignEvent>();


    Team team_a("a", "univA", 1);
    Team team_b("b", "univB", 2);
    Team team_c("c", "univC", 3);
    std::vector<Team> teams = {team_a, team_b, team_c};

    competition.set_teams(teams);
    autocross_event->set_teams(teams);
    design_event->set_teams(teams);

    std::map<Team, std::map<EventsCategories, double>> aut_results;
    std::map<EventsCategories, double> team_a_aut_results;
    std::map<EventsCategories, double> team_b_aut_results;
    std::map<EventsCategories, double> team_c_aut_results;

    // fastest
    team_a_aut_results.insert({first_aut_time, 80000});
    team_a_aut_results.insert({second_aut_time, 80000});
    team_a_aut_results.insert({third_aut_time, 90000});
    team_a_aut_results.insert({fourth_aut_time, 0});
    // scores additional points
    team_b_aut_results.insert({first_aut_time, 0});
    team_b_aut_results.insert({second_aut_time, 90000});
    team_b_aut_results.insert({third_aut_time, 150000.01});
    team_b_aut_results.insert({fourth_aut_time, 0});
    // scores 4.5 points
    team_c_aut_results.insert({first_aut_time, 150000});
    team_c_aut_results.insert({second_aut_time, 0});
    team_c_aut_results.insert({third_aut_time, 200000});
    team_c_aut_results.insert({fourth_aut_time, 0});

    std::map<Team, std::map<EventsCategories, double>> des_results;
    std::map<EventsCategories, double> team_a_des_results;
    std::map<EventsCategories, double> team_b_des_results;
    std::map<EventsCategories, double> team_c_des_results;

    team_a_des_results.insert({overall_vehicle_concept, 0});
    team_a_des_results.insert({vehicle_performance, 0});
    team_a_des_results.insert({mechanical_structural_engineering, 0});
    team_a_des_results.insert({tractive_system, 0});
    team_a_des_results.insert({electronics, 0});
    team_a_des_results.insert({driver_interface, 0});
    team_a_des_results.insert({autonomous_functionality, 0});
    team_a_des_results.insert({design_report, 0});

    team_b_des_results.insert({overall_vehicle_concept, 5});
    team_b_des_results.insert({vehicle_performance, 20});
    team_b_des_results.insert({mechanical_structural_engineering, 5});
    team_b_des_results.insert({tractive_system, 1});
    team_b_des_results.insert({electronics, 15});
    team_b_des_results.insert({driver_interface, 0});
    team_b_des_results.insert({autonomous_functionality, 5});
    team_b_des_results.insert({design_report, 10});

    team_c_des_results.insert({overall_vehicle_concept, 30});
    team_c_des_results.insert({vehicle_performance, 18});
    team_c_des_results.insert({mechanical_structural_engineering, 2});
    team_c_des_results.insert({tractive_system, 10});
    team_c_des_results.insert({electronics, 5});
    team_c_des_results.insert({driver_interface, 10});
    team_c_des_results.insert({autonomous_functionality, 20});
    team_c_des_results.insert({design_report, 10});

    std::map<Team, double> correct_results;

    correct_results.insert({team_a, 100});
    correct_results.insert({team_b, 107.9});
    correct_results.insert({team_c, 109.5});
    // TODO: set results

    // std::vector<std::unique_ptr<Event>> events = {std::move(autocross_event), std::move(design_event)};
    // competition.set_events(events);
    // competition.create_classification();

    // SECTION("Checking validity of competition results")
    // {
    //     std::vector<std::pair<Team, double>> classification = competition.get_final_classification();

    //     CHECK(classification.at(0).first == team_c);
    //     CHECK(classification.at(1).first == team_b);
    //     CHECK(classification.at(2).first == team_a);

    //     CHECK(classification.at(0).second == correct_results.at(team_c));
    //     CHECK(classification.at(1).second == correct_results.at(team_b));
    //     CHECK(classification.at(2).second == correct_results.at(team_a));

    //     CHECK(team_a.get_total_points() == correct_results.at(team_a));
    //     CHECK(team_b.get_total_points() == correct_results.at(team_b));
    //     CHECK(team_c.get_total_points() == correct_results.at(team_c));
    // }

}
// TODO: Naprawić testy!