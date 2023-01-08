#include "ResultSettingWidget.h"
#include <compsim_classes/constants.h>
#include <compsim_enums/enums.h>
#include <QGridLayout>
#include <QBoxLayout>
#include <QLineEdit>
#include <QtAlgorithms>
#include <QLabel>
#include <cmath>
#include <QBoxLayout>
#include <qlineedit.h>
#include <qnamespace.h>
#include <QSpacerItem>



void ResultSettingWidget::displayInputScreen() {
    this->removeLayout();
    QGridLayout *grid = new QGridLayout;
    int grid_width = static_cast<int>(ceil(sqrt(m_teams.size())));
    std::pair<int, int> grid_coordinates = {0,0};

    for (auto& team: m_teams) {
        QWidget *single_team_queries_layout = create_single_team_results_input(team);
        grid->addWidget(single_team_queries_layout, grid_coordinates.first, grid_coordinates.second);
        if (grid_coordinates.first == grid_width-1) {
            grid_coordinates.first = 0;
            grid_coordinates.second += 1;
        } else {
            grid_coordinates.first += 1;
        }
    }
    this->setLayout(grid);
}


QWidget* ResultSettingWidget::create_single_team_results_input(TeamListItem *team_item) {
    QWidget * single_team_input = new QWidget();
    QVBoxLayout * layout = new QVBoxLayout();

    QLabel * label = new QLabel(QString::fromStdString(team_item->team.name()));
    label->setFont(QFont("Sans Serif", 20));
    layout->addWidget(label);

    for (EventsCategories& query: m_queries) {
        ResultLineEdit * query_line_edit = new ResultLineEdit(team_item, &m_laptime_parser, m_event_type, query);
        layout->addWidget(query_line_edit);
    }
    QSpacerItem * spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addSpacerItem(spacer);
    single_team_input->setLayout(layout);
    return single_team_input;
}


void ResultSettingWidget::removeLayout() {
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete this->layout();
}


ResultLineEdit::ResultLineEdit(TeamListItem * team_item, LapTimeParser * parser, EventType event_type, EventsCategories category, QWidget *parent): QLineEdit(parent) {
    this->setValidator(new QIntValidator(this));

    m_team = &team_item->team;
    m_parser = parser;
    m_event_type = event_type;
    m_category = category;
    this->setPlaceholderText(QString::fromStdString(EVENT_CATEGORY_TO_STRING.at(category)));
}


ResultLineEdit::ResultLineEdit(QWidget *parent): QLineEdit(parent) {
    this->setValidator(new QIntValidator(this));
}


void ResultLineEdit::insertResultsIntoTeam() {
    // if (is_dynamic(m_event_type)) {
    //     unsigned int uncorr_time = this->text().toInt();
    //     double time = m_parser->parse_time(m_event_type, 0, 0, uncorr_time);
    //     m_team->set_category_result(m_category, time);
    // } else {
    //     m_team->set_category_result(m_category, this->text().toInt());
    // }
}
