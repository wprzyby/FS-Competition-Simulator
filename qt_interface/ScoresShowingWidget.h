#pragma once

#include <QWidget>
#include <compsim_classes/event_base.h>

class ScoresShowingWidget: public QWidget {


    public:
        ScoresShowingWidget(QWidget* parent): QWidget(parent) {}

        void setScores(std::vector< std::pair<Team, double>> classification_to_show);

    private:
        void removeLayout();
};