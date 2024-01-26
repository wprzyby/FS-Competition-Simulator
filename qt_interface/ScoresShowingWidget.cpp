#include "ScoresShowingWidget.h"
#include <QGridLayout>
#include <QLabel>


void ScoresShowingWidget::setScores(std::vector<std::pair<std::string, double>> classification_to_show) {
    this->removeLayout();
    QGridLayout* layout = new QGridLayout();
    int current_team_index = 0;

    for (auto& [team_name, score]: classification_to_show) {

        QString team_index = QString::number(current_team_index + 1) + ". ";
        QString team_name_shown = QString::fromStdString(team_name);

        QLabel* team_name_label = new QLabel(team_index + team_name_shown);
        QLabel* score_label = new QLabel(QString::number(score, 'f', 1));
        team_name_label->setFont(QFont("Sans Serif", 20));
        score_label->setFont(QFont("Sans Serif", 20));

        layout->addWidget(team_name_label, current_team_index, 0);
        layout->addWidget(score_label, current_team_index, 1);

        current_team_index++;
    }

    this->setLayout(layout);
}

void ScoresShowingWidget::removeLayout() {
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete this->layout();
}