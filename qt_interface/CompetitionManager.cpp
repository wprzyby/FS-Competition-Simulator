#include "CompetitionManager.h"
#include <compsim_classes/event_base.h>
#include <events/events.h>
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

void CompetitionManager::setup_competition(std::list<TeamListItem *> team_items) {
    m_events.clear();

    for (auto& event_type: m_event_types) {
        std::unique_ptr<Event> event;

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
            case businessplan:
                event = std::make_unique<BusinessPlanEvent>();
                break;
            case cost_and_manufacturing:
                event = std::make_unique<CostAndManufacturingEvent>();
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
