#include "ResultSettingWidget.h"
#include "ResultLineEditsWidget.h"
#include <compsim_classes/constants.h>
#include <compsim_enums/enums.h>
#include <QGridLayout>
#include <QBoxLayout>
#include <QLineEdit>
#include <QtAlgorithms>
#include <QLabel>
#include <cmath>
#include <QBoxLayout>
#include <QLineEdit>
#include <QSpacerItem>
#include <QWidget>
#include "qt_interface/constants.h"
#include "tools.h"




void ResultSettingWidget::setEventTypes(std::vector<EventType> event_types) {
    m_event_types = event_types;
}


void ResultSettingWidget::setupLayouts() {
    for (auto event_type: m_event_types) {
        QWidget* event_widget = new QWidget();
        event_widget->setLayout(create_event_layout(event_type));
        this->addWidget(event_widget);
    }
}


void ResultSettingWidget::clearWidget() {
    // for (auto& line_edit: m_input_line_edits) {
    //     qDeleteAll(line_edit->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    //     delete line_edit;
    // }

    m_input_line_edits.clear();

    for (int i=this->count() - 1; i >= 0; i--) {
        QWidget* current_widget = this->widget(i);
        this->removeWidget(current_widget);
        qDeleteAll(current_widget->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
        delete current_widget->layout();
    }
}

ResultSettingWidget::~ResultSettingWidget() {
    this->clearWidget();
}


QGridLayout* ResultSettingWidget::create_event_layout(EventType event_type) {

    QGridLayout *grid = new QGridLayout;

    // the inputs for every team are laid out in a square, starting from top left and
    // going right until square width is reached
    // the width of that square depends on the number of teams
    int grid_width = static_cast<int>(ceil(sqrt(m_teams.size())));
    std::pair<int, int> grid_coordinates = {0,0};

    for (auto& team: m_teams) {
        QWidget *single_team_queries_layout = create_single_team_results_input(team, event_type);
        grid->addWidget(single_team_queries_layout, grid_coordinates.first, grid_coordinates.second);
        if (grid_coordinates.first == grid_width-1) {
            grid_coordinates.first = 0;
            grid_coordinates.second += 1;
        } else {
            grid_coordinates.first += 1;
        }
    }

    return grid;
}



QWidget* ResultSettingWidget::create_single_team_results_input(TeamListItem *team_item, EventType event_type) {
    // creates a widget containing input lines for results of a single team

    QWidget * single_team_input = new QWidget();
    QVBoxLayout * layout = new QVBoxLayout();
    layout->setSpacing(0);

    // adds team's name as label to new widget
    QLabel * label = new QLabel(QString::fromStdString(team_item->team.name()));
    label->setFont(QFont("Sans Serif", 20));
    layout->addWidget(label);

    std::vector<EventCategory> queries = get_event_queries(event_type);

    // adds input lines for each set query
    for (EventCategory& query: queries) {
        ResultLineEditsWidget * query_line_edit_widget = nullptr;

        if (!IS_EVENT_DYNAMIC.at(event_type) || (event_type == endurance && !IS_ENDURANCE_CATEGORY_TIMED.at(query))) {
            query_line_edit_widget = new UntimedResultLineEditsWidget(team_item, query);
        } else {
            query_line_edit_widget = new TimedResultLineEditsWidget(team_item, &m_laptime_parser, event_type, query);
        }

        // a pointer to the line edit widget is "saved" so that later all line edits can be accessed to assign final results
        // when the result input is finished
        m_input_line_edits.push_back(query_line_edit_widget);

        layout->addWidget(query_line_edit_widget);
    }
    // a spacer is added for aesthetic purposes
    QSpacerItem * spacer = new QSpacerItem(0, 0, QSizePolicy::Maximum, QSizePolicy::Expanding);

    layout->addSpacerItem(spacer);
    single_team_input->setLayout(layout);
    return single_team_input;
}


void ResultSettingWidget::saveInput() {
    for(auto& input_line_edit: m_input_line_edits) {
        input_line_edit->insertResultsIntoTeam();
    }
}


void ResultSettingWidget::removeLayout() {
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete this->layout();
}


