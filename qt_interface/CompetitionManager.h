#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>
#include <vector>

class CompetitionManager {
    private:
        std::vector<EventType> m_event_types;
        bool m_run_endurance_efficiency;
    public:
        CompetitionManager() {};
        void set_event_types(std::vector<EventType> event_types) {m_event_types=event_types;}
        void set_endurance_efficiency(bool run_efficiency) {m_run_endurance_efficiency = run_efficiency;}
};