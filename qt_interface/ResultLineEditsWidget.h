#pragma once

#include <compsim_classes/event_base.h>
#include <laptime_parser/LapTimeParser.h>
#include "TeamListItem.h"

#include <QWidget>


class ResultLineEditsWidget: public QWidget {
    protected:
        Team* m_team=nullptr;
        EventCategory m_category;
    public:
        ResultLineEditsWidget(TeamListItem * team_item, EventCategory category, QWidget *parent=nullptr);
        virtual void insertResultsIntoTeam()=0;
    private:
};

class UntimedResultLineEditsWidget: public ResultLineEditsWidget {
    private:
        QLineEdit* m_result_input=nullptr;
    public:
        UntimedResultLineEditsWidget(TeamListItem * team_item, EventCategory category, QWidget *parent=nullptr);
        ~UntimedResultLineEditsWidget();
        void insertResultsIntoTeam() override;
};


class TimedResultLineEditsWidget: public ResultLineEditsWidget {
    private:
        LapTimeParser* m_parser=nullptr;
        EventType m_event_type;

        // line edits for time
        QLineEdit* m_minutes_input=nullptr;
        QLineEdit* m_seconds_input=nullptr;
        QLineEdit* m_miliseconds_input=nullptr;

        // line edits for penalties
        QLineEdit* m_doo_input=nullptr;
        QLineEdit* m_oc_input=nullptr;
        QLineEdit* m_uss_input=nullptr;
    public:
        TimedResultLineEditsWidget(TeamListItem * team_item, LapTimeParser * parser, EventType event_type,
                                   EventCategory category, QWidget *parent=nullptr);
        ~TimedResultLineEditsWidget();
        void insertResultsIntoTeam() override;
    private:
        void insertResultsEndurance();
};

