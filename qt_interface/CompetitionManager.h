#pragma once

#include <memory>
#include <vector>
#include "TeamListItem.h"

class CompetitionManager {
    public:
        Competition competition;
    private:
        std::vector<EventType> m_event_types;
        std::vector<std::unique_ptr<Event>> m_events;
        bool m_run_endurance_efficiency=false;
        unsigned int m_autocross_6mps_time=0;
        std::map<EventType, unsigned int> m_numbers_of_finalists={};
        std::map<EventType, std::map<Team, double>> m_finals_scores_to_set={};

    public:
        CompetitionManager() {};

        EventType event_type_at(int index) {return m_event_types.at(index);}
        bool is_event_dynamic(int index) {return m_events.at(index)->is_dynamic();}
        std::vector<EventType> event_types() {return m_event_types;}

        void set_event_types(std::vector<EventType> event_types);
        void set_endurance_efficiency(bool run_efficiency) {m_run_endurance_efficiency = run_efficiency;}
        void set_number_of_finalists(EventType event_type, unsigned int number_of_finalists);
        void set_autocross_6mps_time(unsigned int time);

        void setup_competition(std::list<TeamListItem *> team_items);
    private:
        void set_teams(std::list<TeamListItem*> team_items);
        void setup_finalists(EventType event_type, std::list<TeamListItem*> team_items);
};