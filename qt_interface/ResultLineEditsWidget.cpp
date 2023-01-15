#include "ResultLineEditsWidget.h"
#include "TeamListItem.h"
#include "compsim_classes/Event.h"
#include "compsim_classes/constants.h"
#include "compsim_enums/enums.h"
#include "constants.h"
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <qboxlayout.h>
#include <qgridlayout.h>

ResultLineEditsWidget::ResultLineEditsWidget(TeamListItem * team_item, EventCategory category,
                                             QWidget *parent): QWidget(parent) {
    m_team = &team_item->team;
    m_category = category;
}



UntimedResultLineEditsWidget::UntimedResultLineEditsWidget(TeamListItem * team_item, EventCategory category, QWidget *parent)
                                                       :ResultLineEditsWidget(team_item, category, parent) {

    QVBoxLayout * layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel * label = new QLabel(QString::fromStdString(EVENT_CATEGORY_TO_STRING.at(m_category)));
    layout->addWidget(label);

    QLineEdit * result_input = new QLineEdit();
    result_input->setValidator(new QIntValidator(result_input));
    result_input->setPlaceholderText("Result");
    result_input->setMaximumWidth(150);
    layout->addWidget(result_input);
    m_result_input = result_input;

    this->setLayout(layout);
}


UntimedResultLineEditsWidget::~UntimedResultLineEditsWidget() {
    delete this->m_result_input;
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete this->layout();
}


void UntimedResultLineEditsWidget::insertResultsIntoTeam() {
    double result = m_result_input->text().toDouble();
    m_team->set_category_result(m_category, result);
}

TimedResultLineEditsWidget::TimedResultLineEditsWidget(TeamListItem * team_item, LapTimeParser * parser, EventType event_type,
                                                       EventCategory category, QWidget *parent)
                                                       :ResultLineEditsWidget(team_item, category, parent) {

    m_parser = parser;
    m_event_type = event_type;

    QGridLayout * layout = new QGridLayout();
    layout->setVerticalSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel * label = new QLabel(QString::fromStdString(EVENT_CATEGORY_TO_STRING.at(m_category)));
    label->setFont(QFont("Sans Serif", 12));
    layout->addWidget(label, 0, 0);


    // for each thing to input by user, a line edit with int validator and placeholder text is created
    // a pointer to this line edit is saved to member variable and the line edit is added to widget's layout
    QLineEdit * minutes_input = new QLineEdit();
    minutes_input->setValidator(new QIntValidator(minutes_input));
    minutes_input->setPlaceholderText("Minutes");
    minutes_input->setMaximumWidth(150);
    layout->addWidget(minutes_input, 1, 0);
    m_minutes_input = minutes_input;

    QLineEdit * seconds_input = new QLineEdit();
    seconds_input->setValidator(new QIntValidator(seconds_input));
    seconds_input->setPlaceholderText("Seconds");
    seconds_input->setMaximumWidth(150);
    layout->addWidget(seconds_input, 2, 0);
    m_seconds_input = seconds_input;

    QLineEdit * miliseconds_input = new QLineEdit();
    miliseconds_input->setValidator(new QIntValidator(miliseconds_input));
    miliseconds_input->setPlaceholderText("Miliseconds");
    miliseconds_input->setMaximumWidth(150);
    layout->addWidget(miliseconds_input, 3, 0);
    m_miliseconds_input = miliseconds_input;

    QLineEdit * doo_input = new QLineEdit();
    doo_input->setValidator(new QIntValidator(doo_input));
    doo_input->setPlaceholderText("Down-or-over (cones)");
    doo_input->setMaximumWidth(150);
    layout->addWidget(doo_input, 1, 1);
    m_doo_input = doo_input;

    QLineEdit * oc_input = new QLineEdit();
    oc_input->setValidator(new QIntValidator(oc_input));
    oc_input->setPlaceholderText("Off-course");
    oc_input->setMaximumWidth(150);
    layout->addWidget(oc_input, 2, 1);
    m_oc_input = oc_input;

    QLineEdit * uss_input = new QLineEdit();
    uss_input->setValidator(new QIntValidator(uss_input));
    uss_input->setPlaceholderText("Unsafe Stop");
    uss_input->setMaximumWidth(150);
    layout->addWidget(uss_input, 3, 1);
    m_uss_input = uss_input;

    this->setLayout(layout);
}

TimedResultLineEditsWidget::~TimedResultLineEditsWidget() {
    delete m_minutes_input;
    delete m_seconds_input;
    delete m_miliseconds_input;
    delete m_doo_input;
    delete m_oc_input;
    delete m_uss_input;
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete this->layout();
}


void TimedResultLineEditsWidget::insertResultsIntoTeam() {
    // endurance demands a special case because it's the only event which
    // also requires the value of uncorrected time, so both corrected and uncorrected
    // times need to be saved
    if (m_category == end_uncorrected_time) {
        insertResultsEndurance();
        return;
    }

    unsigned int minutes = m_minutes_input->text().toUInt();
    unsigned int seconds = m_seconds_input->text().toUInt();
    unsigned int miliseconds = m_miliseconds_input->text().toUInt();
    unsigned int doo = m_doo_input->text().toUInt();
    unsigned int oc = m_oc_input->text().toUInt();
    unsigned int uss = m_uss_input->text().toUInt();
    double time = m_parser->parse_time(m_event_type, minutes, seconds, miliseconds, doo, oc, uss);
    m_team->set_category_result(m_category, time);
}


void TimedResultLineEditsWidget::insertResultsEndurance() {
    unsigned int minutes = m_minutes_input->text().toUInt();
    unsigned int seconds = m_seconds_input->text().toUInt();
    unsigned int miliseconds = m_miliseconds_input->text().toUInt();
    unsigned int doo = m_doo_input->text().toUInt();
    unsigned int oc = m_oc_input->text().toUInt();
    unsigned int uss = m_uss_input->text().toUInt();

    double uncorrected_time = m_parser->parse_time(m_event_type, minutes, seconds, miliseconds, 0, 0, 0);
    double corrected_time = m_parser->parse_time(m_event_type, minutes, seconds, miliseconds, doo, oc, uss);

    m_team->set_category_result(end_uncorrected_time, uncorrected_time);
    m_team->set_category_result(end_corrected_time, corrected_time);
}