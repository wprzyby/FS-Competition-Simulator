#pragma once

#include <compsim_classes/event_base.h>
#include <compsim_classes/Competition.h>
#include <compsim_enums/enums.h>
#include <memory>
#include <vector>
#include "TeamListItem.h"

class CompetitionManager {
    public:
        Competition competition;
    private:
        std::vector<EventType> m_event_types;
        std::vector<std::unique_ptr<Event>> m_events;
        bool m_run_endurance_efficiency;
    public:
        CompetitionManager() {};

        EventType event_type_at(int index) {return m_event_types.at(index);}
        bool is_event_dynamic(int index) {return m_events.at(index)->is_dynamic();}
        std::vector<EventType> event_types() {return m_event_types;}

        void set_event_types(std::vector<EventType> event_types);
        void set_endurance_efficiency(bool run_efficiency) {m_run_endurance_efficiency = run_efficiency;}

        void setup_competition(std::list<TeamListItem *> team_items);
    private:
        void set_teams(std::list<TeamListItem*> team_items);
};