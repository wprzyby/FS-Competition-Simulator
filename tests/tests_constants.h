#ifndef TESTS_CONSTANTS_H
#define TESTS_CONSTANTS_H


#include <iostream>
#include <vector>
#include <map>

#include "../Event_tools.h"
#include "../events/AccelerationEvent.h"
#include "../events/BusinessPlanEvent.h"
#include "../events/CostAndManufacturingEvent.h"
#include "../events/EngineeringDesignEvent.h"
#include "../events/SkidpadEvent.h"
#include "../base_classes/Event.h"
#include "../base_classes/Team.h"
#include "../base_classes/LapTimeParser.h"
#include "../constants.h"


// Creating the event and teams
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
//


// Creating map of results for SkidpadEvent
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
//


// Creating map of results for BusinessPlanEvent
std::map<Team, std::map<EventsCategories, double>> bus_teams_and_results;
std::map<EventsCategories, double> bus_team_a_results;
std::map<EventsCategories, double> bus_team_b_results;
std::map<EventsCategories, double> bus_team_c_results;

bus_team_a_results.insert({pitch_video, 9});
bus_team_a_results.insert({novelty, 8});
bus_team_a_results.insert({content, 17});
bus_team_a_results.insert({finances, 7});
bus_team_a_results.insert({deep_dive_topic, 10});
bus_team_a_results.insert({demontration_and_structure, 13});
bus_team_a_results.insert({delivery, 10});
bus_team_a_results.insert({questions, 10});
bus_team_a_results.insert({general_impression, 5});

bus_team_b_results.insert({pitch_video, 8});
bus_team_b_results.insert({novelty, 9});
bus_team_b_results.insert({content, 19});
bus_team_b_results.insert({finances, 10});
bus_team_b_results.insert({deep_dive_topic, 10});
bus_team_b_results.insert({demontration_and_structure, 14});
bus_team_b_results.insert({delivery, 8});
bus_team_b_results.insert({questions, 8});
bus_team_b_results.insert({general_impression, 4});

bus_team_d_results.insert({pitch_video, 4});
bus_team_d_results.insert({novelty, 3});
bus_team_d_results.insert({content, 12});
bus_team_d_results.insert({finances, 8});
bus_team_d_results.insert({deep_dive_topic, 6});
bus_team_d_results.insert({demontration_and_structure, 12});
bus_team_d_results.insert({delivery, 7});
bus_team_d_results.insert({questions, 7});
bus_team_d_results.insert({general_impression, 3});

bus_teams_and_results.insert({team_a, bus_team_a_results});
bus_teams_and_results.insert({team_b, bus_team_b_results});
bus_teams_and_results.insert({team_c, bus_team_c_results});
//


// Creating map of results for CostAndManufacturingEvent
std::map<Team, std::map<EventsCategories, double>> cos_teams_and_results;
std::map<EventsCategories, double> cos_team_a_results;
std::map<EventsCategories, double> cos_team_b_results;
std::map<EventsCategories, double> cos_team_c_results;

cos_team_a_results.insert({format_and_accuracy_of_documents, 5});
cos_team_a_results.insert({knowledge_of_documents_and_vehicle, 5});
cos_team_a_results.insert({BOM_discussion, 35});
cos_team_a_results.insert({cost_understanding, 35});
cos_team_a_results.insert({real_case, 20});

cos_team_b_results.insert({format_and_accuracy_of_documents, 4});
cos_team_b_results.insert({knowledge_of_documents_and_vehicle, 5});
cos_team_b_results.insert({BOM_discussion, 34});
cos_team_b_results.insert({cost_understanding, 35});
cos_team_b_results.insert({real_case, 20});

cos_team_c_results.insert({format_and_accuracy_of_documents, 3});
cos_team_c_results.insert({knowledge_of_documents_and_vehicle, 2});
cos_team_c_results.insert({BOM_discussion, 30});
cos_team_c_results.insert({cost_understanding, 28});
cos_team_c_results.insert({real_case, 17});

cos_team_d_results.insert({format_and_accuracy_of_documents, 4});
cos_team_d_results.insert({knowledge_of_documents_and_vehicle, 3});
cos_team_d_results.insert({BOM_discussion, 27});
cos_team_d_results.insert({cost_understanding, 29});
cos_team_d_results.insert({real_case, 15});

cos_teams_and_results.insert({team_a, bus_team_a_results});
cos_teams_and_results.insert({team_b, bus_team_b_results});
cos_teams_and_results.insert({team_c, bus_team_c_results});
//


#endif
