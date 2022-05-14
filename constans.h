#ifndef CONSTANS_H
#define CONSTANS_H

//TODO: Add to this ennum all categories and create vectors.
enum EventsCategories {pitch_video, novelty, content, finances, deep_dive_topic, demontration_and_structure, delivery, questions, general_impression, format_and_accuracy_of_documents,
knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case, overall_vehicle_concept, vehicle_performance, mechanical_structural_engeeniering, tracktive_system,
electronics, driver_interface, autonomous_functionality, design_report, first_left_time, first_right_time, second_left_time, second_right_time, first_ski_penalties, second_ski_penalties,
firs_acc_time, second_acc_time, first_acc_penalties, second_acc_penalties, first_aut_time, second_aut_time, third_aut_time, fourth_aut_time, first_aut_penalties, second_aut_penalties, third_aut_penalties,
fourth_aut_penalties, end_time, end_penalties, energy_used, energy_produced,

};

// Categories for BuisnessPlanEvent
std::vector<EventsCategories> BusPlaEveCat = {pitch_video, novelty, content, finances, deep_dive_topic, demontration_and_structure, delivery, questions, general_impression};

// Categories for CostAndManufacturingEvent
std::vector<EventsCategories> CosAndManEveCat = {format_and_accuracy_of_documents, knowledge_of_documents_and_vehicle, BOM_discussion, cost_understanding, real_case};

// Categories for EngeeneringDesignEvent
std::vector<EventsCategories> EngDesEveCat = {overall_vehicle_concept, vehicle_performance, mechanical_structural_engeeniering, tracktive_system, electronics, driver_interface, autonomous_functionality, design_report};

// Categories for SkidpadEvent
std::vector<EventsCategories> SkiEveCat = {first_left_time, first_right_time, second_left_time, second_right_time, first_ski_penalties, second_ski_penalties};  // penalties are summed points of all infrigements (IDK, Should it be a function?)  TODO: Decide what a penalty is!

// Categories for AccelerationEvent
std::vector<EventsCategories> AccEveCat = {firs_acc_time, second_acc_time, first_acc_penalties, second_acc_penalties};

// Categories for AutocrossEvent
std::vector<EventsCategories> AutEveCat = {first_aut_time, second_aut_time, third_aut_time, fourth_aut_time, first_aut_penalties, second_aut_penalties, third_aut_penalties, fourth_aut_penalties};

// Categories for EnduranceEvent
std::vector<EventsCategories> EndEveCat = {end_time, end_penalties, energy_used, energy_produced};

#endif
