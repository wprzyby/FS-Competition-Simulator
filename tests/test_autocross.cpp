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

    std::map<Team, std::map<EventsCategories, double>> results;

    std::map<EventsCategories, double> team_a_results;
    std::map<EventsCategories, double> team_b_results;
    std::map<EventsCategories, double> team_c_results;
    std::map<EventsCategories, double> team_d_results;
    std::map<EventsCategories, double> team_e_results;

    // fastest
    team_a_results.insert({first_aut_time, 80000});
    team_a_results.insert({second_aut_time, 80000});
    team_a_results.insert({third_aut_time, 90000});
    team_a_results.insert({fourth_aut_time, 0});
    // scores additional points
    team_b_results.insert({first_aut_time, 0});
    team_b_results.insert({second_aut_time, 90000});
    team_b_results.insert({third_aut_time, 150000.01});
    team_b_results.insert({fourth_aut_time, 0});
    // scores 4.5 points
    team_c_results.insert({first_aut_time, 150000});
    team_c_results.insert({second_aut_time, 0});
    team_c_results.insert({third_aut_time, 200000});
    team_c_results.insert({fourth_aut_time, 0});
    // negative times
    team_d_results.insert({first_aut_time, 0});
    team_d_results.insert({second_aut_time, 0});
    team_d_results.insert({third_aut_time, 0});
    team_d_results.insert({fourth_aut_time, 0});
    // no runs without DNF
    team_e_results.insert({first_aut_time, 0});
    team_e_results.insert({second_aut_time, 0});
    team_e_results.insert({third_aut_time, 0});
    team_e_results.insert({fourth_aut_time, 0});

    results.insert({team_a, team_a_results});
    results.insert({team_b, team_b_results});
    results.insert({team_c, team_c_results});
    results.insert({team_d, team_d_results});
    results.insert({team_e, team_e_results});

    std::map<Team, double> correct_results;

    correct_results.insert({team_a, 100});
    correct_results.insert({team_b, 46.9});
    correct_results.insert({team_c, 4.5});
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
        std::vector<Team> teams = {team_a, team_b, team_c, team_d};
        event.set_teams(teams);
        event.set_results(results);
        event.simulate();
        std::map<Team, double> classification = event.get_classification();

        CHECK(correct_results.at(team_a) == classification.at(team_a));
        CHECK(correct_results.at(team_b) == classification.at(team_b));
        CHECK(correct_results.at(team_c) == classification.at(team_c));
        CHECK(correct_results.at(team_d) == classification.at(team_d));
        CHECK(correct_results.at(team_e) == classification.at(team_e));

        // checking if sorted correctly
        std::vector<std::pair<Team, double>> points_vector = event.get_sorted_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector[0].second >= points_vector[1].second);
        CHECK(points_vector[1].second >= points_vector[2].second);
        CHECK(points_vector[2].second >= points_vector[3].second);
        CHECK(points_vector[3].second >= points_vector[4].second);
        //
    }

    SECTION("Wrong categories in results")
    {
        Team team_x("x", "univX", 10);
        std::map<EventsCategories, double> team_x_results;
        team_x_results.insert({first_aut_time, 100000});
        team_x_results.insert({pitch_video, 5});
        team_x_results.insert({first_acc_time, 100000});
        results.insert({team_x, team_x_results});

        REQUIRE_THROWS(event.set_results(results));
    }

    SECTION("Getters")
    {
        CHECK(event.get_event_type() == autocross);
        CHECK(event.get_info_file_name() == "AutocrossEventInfo.pdf");
    }


}



