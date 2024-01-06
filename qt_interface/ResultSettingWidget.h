#pragma once

#include <QWidget>
#include <QStackedWidget>
#include <list>
#include <QLineEdit>
#include <QBoxLayout>
#include <QGridLayout>
#include <vector>

#include <compsim_enums/enums.h>
#include "TeamListItem.h"
#include <laptime_parser/LapTimeParser.h>
#include "constants.h"
#include "ResultLineEditsWidget.h"




class ResultSettingWidget : public QStackedWidget {
    private:
        std::list<TeamListItem*> m_teams;
        std::vector<EventCategory> m_queries;
        std::vector<EventType> m_event_types;
        std::vector<ResultLineEditsWidget*> m_input_line_edits;
        bool m_IsPenaltyQueryEnabled=true;
        LapTimeParser m_laptime_parser=LapTimeParser(PenaltyConfigFilePath, ms);

    public:
        ResultSettingWidget(QWidget *parent=nullptr): QStackedWidget(parent) {}
        ~ResultSettingWidget();
        void setTeams(std::list<TeamListItem*> teams) {m_teams = teams;}
        void setEventTypes(std::vector<EventType> event_types);
        void setupLayouts();
        void saveInput();
        void clearWidget();

    private:
        QWidget* create_single_team_results_input(TeamListItem *team, EventType event_type);
        QGridLayout* create_event_layout(EventType event_type);
        void removeLayout();
};
