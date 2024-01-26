#pragma once

#include <QWidget>

class ScoresShowingWidget: public QWidget {


    public:
        ScoresShowingWidget(QWidget* parent): QWidget(parent) {}

        void setScores(std::vector< std::pair<std::string, double>> classification_to_show);

    private:
        void removeLayout();
};