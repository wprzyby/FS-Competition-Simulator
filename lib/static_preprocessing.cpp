#include "EventSimulatorStandard.h"

#include "event_tools.h"
#include <cmath>

EventData EventSimulatorStandard::preprocessing_static_finals(const Teams& teams, std::vector<EventCategory> categories, EventCategory finals_category)
{
    EventData event_data;
    double best_result_non_finalist = 0;
    double best_result_finalist = 0;
    for (auto& team: teams) {
        double finals_result = team.result_of_category(finals_category);
        event_data["finals_" + team.name()] = finals_result;
        if (finals_result > best_result_finalist) {
            best_result_finalist = finals_result;
        }

        double sum_of_results = sum_results(team, categories, {finals_category});
        event_data[team.name()] = sum_of_results;
        if (sum_of_results > best_result_non_finalist) {
            best_result_non_finalist = sum_of_results;
        }
    }
    event_data["best_result_non_finalist"] = best_result_non_finalist;
    event_data["best_result_finalist"] = best_result_finalist;
    return event_data;
}

EventData EventSimulatorStandard::preprocessing_static_no_finals(const Teams& teams, std::vector<EventCategory> categories)
{
    EventData event_data;
    for (auto& team: teams) {
        event_data[team.name()] = sum_results(team, categories);
    }
    return event_data;
}