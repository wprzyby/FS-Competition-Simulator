#include <map>
#include <vector>


#include "catch.hpp"
#include <compsim_classes/Team.h>
#include <compsim_classes/exceptions.h>
#include <compsim_enums/enums.h>

#include <events/EnduranceEvent.h>



TEST_CASE("Endurance Event functionality")
{
    EnduranceEvent event;

    Team team_a("a", "univA", 1);
    Team team_b("b", "univB", 2);
    Team team_c("c", "univC", 3);
    Team team_d("d", "univD", 4);
    Team team_e("e", "univE", 5);

    Team duplicate_name_team("a", "univF", 6);
    Team duplicate_univ_team("f", "univA", 7);
    Team duplicate_numb_team("g", "univG", 1);

    std::map<Team, std::map<EventsCategories, double>> results;

    std::map<EventsCategories, double> team_a_results;
    std::map<EventsCategories, double> team_b_results;
    std::map<EventsCategories, double> team_c_results;
    std::map<EventsCategories, double> team_d_results;
    std::map<EventsCategories, double> team_e_results;

    // fastest
    team_a_results.insert({end_corrected_time, 1000000});
    team_a_results.insert({end_uncorrected_time, 1500000});
    team_a_results.insert({energy_used, 100000});
    team_a_results.insert({energy_produced, 20000});
    // scores additional points in endurance and efficiency
    team_b_results.insert({end_corrected_time, 1200000});
    team_b_results.insert({end_uncorrected_time, 1500000});
    team_b_results.insert({energy_used, 100000});
    team_b_results.insert({energy_produced, 30000});
    // scores 25 points endurance, scores in efficiency
    team_c_results.insert({end_corrected_time, 1333001});
    team_c_results.insert({end_uncorrected_time, 1600000});
    team_c_results.insert({energy_used, 120000});
    team_c_results.insert({energy_produced, 15000});
    // scores points in endurance, no points in efficiency
    team_d_results.insert({end_corrected_time, 1300000});
    team_d_results.insert({end_uncorrected_time, 2000000});
    team_d_results.insert({energy_used, 90000});
    team_d_results.insert({energy_produced, 40000});
    // DNF in endurance
    team_e_results.insert({end_corrected_time, 0});
    team_e_results.insert({end_uncorrected_time, 0});
    team_e_results.insert({energy_used, 0});
    team_e_results.insert({energy_produced, 0});

    results.insert({team_a, team_a_results});
    results.insert({team_b, team_b_results});
    results.insert({team_c, team_c_results});
    results.insert({team_d, team_d_results});
    results.insert({team_e, team_e_results});

    std::map<Team, double> correct_results_endurance;

    correct_results_endurance.insert({team_a, 325});
    correct_results_endurance.insert({team_b, 124.8});
    correct_results_endurance.insert({team_c, 25});
    correct_results_endurance.insert({team_d, 47.9});
    correct_results_endurance.insert({team_e, 0});

    std::map<Team, double> correct_results_efficiency;

    correct_results_efficiency.insert({team_a, 65.8});
    correct_results_efficiency.insert({team_b, 75});
    correct_results_efficiency.insert({team_c, 25.5});
    correct_results_efficiency.insert({team_d, 0});
    correct_results_efficiency.insert({team_e, 0});

    SECTION("Wrong categories in results")
    {
        Team team_x("x", "univX", 10);
        std::map<EventsCategories, double> team_x_results;
        team_x_results.insert({end_corrected_time, 100000});
        team_x_results.insert({pitch_video, 5});
        team_x_results.insert({first_acc_time, 100000});
        results.insert({team_x, team_x_results});

        REQUIRE_THROWS(event.set_results(results));
    }

    SECTION("Simulation - endurance only")
    {
        std::vector<Team> teams = {team_a, team_b, team_c, team_d, team_e};
        event.set_teams(teams);
        event.set_results(results);
        event.simulate();
        std::map<Team, double> classification = event.get_classification();

        CHECK(correct_results_endurance.at(team_a) == classification.at(team_a));
        CHECK(correct_results_endurance.at(team_b) == classification.at(team_b));
        CHECK(correct_results_endurance.at(team_c) == classification.at(team_c));
        CHECK(correct_results_endurance.at(team_d) == classification.at(team_d));
        CHECK(correct_results_endurance.at(team_e) == classification.at(team_e));

        // checking if sorted correctly
        std::vector<std::pair<Team,double>> sorted_points = event.get_sorted_classification();

        CHECK(sorted_points[0].second >= sorted_points[1].second);
        CHECK(sorted_points[1].second >= sorted_points[2].second);
        CHECK(sorted_points[2].second >= sorted_points[3].second);
        CHECK(sorted_points[3].second >= sorted_points[4].second);
    }

    SECTION("Simulation - endurance and efficiency")
    {
        EnduranceEvent event_with_eff(true);

        std::vector<Team> teams = {team_a, team_b, team_c, team_d, team_e};
        event_with_eff.set_teams(teams);
        event_with_eff.set_results(results);
        event_with_eff.simulate();
        std::map<Team, double> classification = event_with_eff.get_classification();

        CHECK(correct_results_endurance.at(team_a) + correct_results_efficiency.at(team_a) == classification.at(team_a));
        CHECK(correct_results_endurance.at(team_b) + correct_results_efficiency.at(team_b) == classification.at(team_b));
        CHECK(correct_results_endurance.at(team_c) + correct_results_efficiency.at(team_c) == classification.at(team_c));
        CHECK(correct_results_endurance.at(team_d) + correct_results_efficiency.at(team_d) == classification.at(team_d));
        CHECK(correct_results_endurance.at(team_e) + correct_results_efficiency.at(team_e) == classification.at(team_e));

        // checking if sorted correctly
        std::vector<std::pair<Team,double>> sorted_points = event_with_eff.get_sorted_classification();

        CHECK(sorted_points[0].second >= sorted_points[1].second);
        CHECK(sorted_points[1].second >= sorted_points[2].second);
        CHECK(sorted_points[2].second >= sorted_points[3].second);
        CHECK(sorted_points[3].second >= sorted_points[4].second);
    }

    SECTION("Getters")
    {
        CHECK(event.get_event_type() == endurance);
        CHECK(event.get_info_file_name() == "EnduranceEventInfo.pdf");
    }

}
