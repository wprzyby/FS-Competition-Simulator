#include "CompetitionManager.h"
#include <memory>


void CompetitionManager::set_teams(std::list<TeamListItem *> team_items) {
    std::vector<Team> teams_to_set;
    for (auto& team_item: team_items) {
        teams_to_set.push_back(team_item->team);
    }

    for (auto& event: m_events) {
        event->set_teams(teams_to_set);
    }

    competition.set_teams(teams_to_set);
}

void CompetitionManager::set_event_types(std::vector<EventType> event_types) {
    m_event_types=event_types;
}

void CompetitionManager::set_number_of_finalists(EventType event_type, unsigned int number_of_finalists) {
    m_numbers_of_finalists[event_type] = number_of_finalists;
}

void CompetitionManager::set_autocross_6mps_time(unsigned int time) {
    m_autocross_6mps_time = time;
}

void CompetitionManager::setup_competition(std::list<TeamListItem *> team_items) {
    m_events.clear();



    for (auto& event_type: m_event_types) {
        std::unique_ptr<Event> event;

        if (event_type == businessplan || event_type == cost_and_manufacturing) {
            setup_finalists(event_type, team_items);
        }

        switch(event_type) {
            case acceleration:
                event = std::make_unique<AccelerationEvent>();
                break;
            case acceleration_DV:
                event = std::make_unique<DVAccelerationEvent>();
                break;
            case acceleration_DC:
                event = std::make_unique<DCAccelerationEvent>();
                break;
            case autocross:
                event = std::make_unique<AutocrossEvent>();
                break;
            case autocross_DC:
                event = std::make_unique<DCAutocrossEvent>(m_autocross_6mps_time);
                break;
            case businessplan:
                event = std::make_unique<BusinessPlanEvent>(m_numbers_of_finalists.at(businessplan), m_finals_scores_to_set.at(businessplan));
                break;
            case cost_and_manufacturing:
                event = std::make_unique<CostAndManufacturingEvent>(m_numbers_of_finalists.at(cost_and_manufacturing), m_finals_scores_to_set.at(cost_and_manufacturing));
                break;
            case endurance:
                event = std::make_unique<EnduranceEvent>(this->m_run_endurance_efficiency);
                break;
            case engineering_design:
                event = std::make_unique<EngineeringDesignEvent>();
                break;
            case engineering_design_DC:
                event = std::make_unique<DCEngineeringDesignEvent>();
                break;
            case skidpad:
                event = std::make_unique<SkidpadEvent>();
                break;
            case skidpad_DV:
                event = std::make_unique<DVSkidpadEvent>();
                break;
            case skidpad_DC:
                event = std::make_unique<DCSkidpadEvent>();
                break;
            case trackdrive:
                event = std::make_unique<TrackdriveEvent>();
                break;
            default:
                throw std::invalid_argument("Invalid event type selected");
        }

        m_events.push_back(std::move(event));
    }
    this->set_teams(team_items);
    competition.set_events(std::move(m_events));

}


void CompetitionManager::setup_finalists(EventType event_type, std::list<TeamListItem*> team_items) {

    // Temporary solution for injecting results for finalists into the competition
    // Needs change in implementation of base classes

    EventCategory category_to_check = (event_type == businessplan)? businessplan_finals_score : cost_and_manufacturing_finals_score;

    double result_value = 0;
    unsigned int number_of_found_finalists = 0;
    for (auto& team_item: team_items) {
        try {
            result_value = team_item->team.result_of_category(category_to_check);
        } catch (std::out_of_range const&) {
            continue;
        }

        if (result_value != 0) {
            m_finals_scores_to_set[event_type][team_item->team] = result_value;
            number_of_found_finalists += 1;
        }
    }

    if (m_numbers_of_finalists.at(event_type) != number_of_found_finalists) {
        throw UnmatchedNumberOfFinalistsError();
    }

}