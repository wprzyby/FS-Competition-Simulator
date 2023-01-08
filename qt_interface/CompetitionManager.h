#pragma once

#include <compsim_classes/event_base.h>
#include <compsim_classes/Competition.h>
#include <compsim_enums/enums.h>
#include <memory>
#include <vector>

class CompetitionManager {
    private:
        std::vector<EventType> m_event_types;
        std::vector<std::unique_ptr<Event>> m_events;
        Competition m_competition;
        bool m_run_endurance_efficiency;
    public:
        CompetitionManager() {};

        EventType event_type_at(int index) {return m_event_types.at(index);}
        std::vector<EventType> event_types() {return m_event_types;}

        void set_event_types(std::vector<EventType> event_types) {m_event_types=event_types;}
        void set_endurance_efficiency(bool run_efficiency) {m_run_endurance_efficiency = run_efficiency;}
};