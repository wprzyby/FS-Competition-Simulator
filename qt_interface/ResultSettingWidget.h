#pragma once

#include <QWidget>
#include <list>
#include <QLineEdit>
#include <QBoxLayout>
#include <vector>

#include <compsim_enums/enums.h>
#include "TeamListItem.h"
#include "laptime_parser/LapTimeParser.h"
#include "constants.h"

class ResultSettingWidget : public QWidget {
    private:
        std::list<TeamListItem*> m_teams;
        std::vector<EventsCategories> m_queries;
        EventType m_event_type;
        bool m_IsPenaltyQueryEnabled=true;
        LapTimeParser m_laptime_parser=LapTimeParser(PenaltyConfigFilePath, ms);

    public:
        ResultSettingWidget(QWidget *parent=nullptr): QWidget(parent) {}
        void setTeams(std::list<TeamListItem*> teams) {m_teams = teams;}
        void setQueries(std::vector<EventsCategories> queries) {m_queries = queries;}
        void setEventType(EventType event_type) {m_event_type = event_type;}
        void setPenaltyQueryEnabled(bool isEnabled) {m_IsPenaltyQueryEnabled = isEnabled;}
        void displayInputScreen();
        void saveInput() {}

    private:
        QWidget* create_single_team_results_input(TeamListItem *team);
        void removeLayout();
};

class ResultLineEdit: public QLineEdit {
    private:
        Team* m_team=nullptr;
        LapTimeParser* m_parser=nullptr;
        EventType m_event_type;
        EventsCategories m_category;
    public:
        ResultLineEdit(QWidget *parent=nullptr);
        ResultLineEdit(TeamListItem * team_item, LapTimeParser * parser, EventType event_type, EventsCategories category, QWidget *parent=nullptr);
        void insertResultsIntoTeam();
};