#include <iostream>
#include <vector>

#include "../base_classes/Team.h"
#include "../events/SkidpadEvent.h"

#include "catch.hpp"
#include "../exceptions.h"
#include "../constants.h"
#include "../enums/enums.h"


TEST_CASE("SkidpadEvent tests.", "[Testing all functionalities]")
{
    Team team_a("A", "UniveroA", 1), team_b("B", "UniveroB", 2), team_c("C", "UniveroC", 3), team_d("D", "UniveroD", 4);
    std::vector<Team> teams{team_a, team_b, team_c, team_d};

    std::map<Team, std::map<EventsCategories, double>> skid_teams_and_results;
    std::map<EventsCategories, double> skid_team_a_results;
    std::map<EventsCategories, double> skid_team_b_results;
    std::map<EventsCategories, double> skid_team_c_results;
    std::map<EventsCategories, double> skid_team_d_results;

    skid_team_a_results.insert({first_left_time, 0});
    skid_team_a_results.insert({first_right_time, 0});
    skid_team_a_results.insert({second_left_time, 5702});
    skid_team_a_results.insert({second_right_time, 4981});


    skid_team_b_results.insert({first_left_time, 4800});
    skid_team_b_results.insert({first_right_time, 4800});
    skid_team_b_results.insert({second_left_time, 4912});
    skid_team_b_results.insert({second_right_time, 3987});


    skid_team_c_results.insert({first_left_time, 0});
    skid_team_c_results.insert({first_right_time, 0});
    skid_team_c_results.insert({second_left_time, 7053});
    skid_team_c_results.insert({second_right_time, 7124});


    skid_team_d_results.insert({first_left_time, 6541});
    skid_team_d_results.insert({first_right_time, 5432});
    skid_team_d_results.insert({second_left_time, 4982});
    skid_team_d_results.insert({second_right_time, 5014});


    skid_teams_and_results.insert({team_a, skid_team_a_results});
    skid_teams_and_results.insert({team_b, skid_team_b_results});
    skid_teams_and_results.insert({team_c, skid_team_c_results});
    skid_teams_and_results.insert({team_d, skid_team_d_results});

    // Creating and simulating the Event
    SkidpadEvent skid_event(teams);
    skid_event.set_results(skid_teams_and_results);
    skid_event.simulate();
    std::map<Team, double> skid_results = skid_event.get_classification();
    //

    // Creating map of correct results
    std::map<Team, double> skid_correct_results;
    skid_correct_results.insert({team_a, 10.5});
    skid_correct_results.insert({team_b, 50.0});
    skid_correct_results.insert({team_c, 3.5});
    skid_correct_results.insert({team_d, 23.2});
    //

    SECTION("Testing: setting results and calculating points")
    {
        CHECK(skid_results[team_a] == skid_correct_results[team_a]);
        CHECK(skid_results[team_b] == skid_correct_results[team_b]);
        CHECK(skid_results[team_c] == skid_correct_results[team_c]);
        CHECK(skid_results[team_d] == skid_correct_results[team_d]);
    }


    SECTION("Testing: making event classification")
    {
        std::vector<std::pair<Team, double>> points_vector = skid_event.get_sorted_classification();

        // Checking whether points are truely sorted:
        CHECK(points_vector[0].second >= points_vector[1].second);
        CHECK(points_vector[1].second >= points_vector[2].second);
        //
    }


    SECTION("Testing: EventType and filename getters")
    {
        CHECK(skid_event.get_event_type() == skidpad);
        CHECK(skid_event.get_info_file_name() == "SkidpadEventInfo.pdf");
    }
}
