#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "TeamListItem.h"
#include "compsim_classes/Competition.h"
#include "compsim_classes/constants.h"
#include "constants.h"
#include <QDebug>
#include <qdebug.h>
#include <compsim_enums/enums.h>
#include <events/constants.h>
#include <vector>
#include "qt_interface/ResultSettingWidget.h"
#include "tools.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->baseStack->setCurrentIndex(MainMenuIndexNumber);
    ui->lineEditTeamNumber->setValidator(new QIntValidator(this));
    ui->lineEditAutocrossTime6mps->setValidator(new QIntValidator(this));
    ui->spinBoxBusinessplanFinalists->setMaximum(0);
    ui->spinBoxCostAndManufacturingFinalists->setMaximum(0);
    connect(ui->pushButtonBackToMenu, SIGNAL(clicked()), this, SLOT(backToMainMenu()));
    connect(ui->pushButtonFinishSetup, SIGNAL(clicked()), this, SLOT(finishSetup()));
    connect(ui->pushButtonChangeSetup, SIGNAL(clicked()), this, SLOT(returnToSetup()));
    connect(ui->pushButtonResultSettingNext, SIGNAL(clicked()), this, SLOT(resultSettingNextEvent()));
    connect(ui->pushButtonResultSettingPrevious, SIGNAL(clicked()), this, SLOT(resultSettingPreviousEvent()));
    connect(ui->pushButtonResultSettingFinish, SIGNAL(clicked()), this, SLOT(resultSettingFinish()));
    connect(ui->pushButtonEventScoresNext, SIGNAL(clicked()), this, SLOT(resultShowingNextEvent()));
    connect(ui->pushButtonEventScoresPrevious, SIGNAL(clicked()), this, SLOT(resultShowingPreviousEvent()));
    connect(ui->pushButtonChangeResults, SIGNAL(clicked()), this, SLOT(returnToResultSetting()));
    connect(ui->pushButtonShowCompetitionScores, SIGNAL(clicked()), this, SLOT(changeResultShowingMode()));
    connect(ui->pushButtonAddTeam, SIGNAL(clicked()), this, SLOT(updateFinalsSpinBoxes()));
}

MainWindow::~MainWindow() {
    delete ui;
    while(!m_teams.empty()) delete m_teams.front(), m_teams.pop_front();
}

void MainWindow::on_pushButtonChooseCompsim_clicked() {
    ui->baseStack->setCurrentIndex(SetupScreenIndexNumber);
}

void MainWindow::backToMainMenu() {
    ui->baseStack->setCurrentIndex(MainMenuIndexNumber);
}


void MainWindow::on_pushButtonAddTeam_clicked()
{
    QString name = ui->lineEditTeamName->text();
    QString uni = ui->lineEditTeamUni->text();
    QString number = ui->lineEditTeamNumber->text();
    TeamListItem *team_to_add = new TeamListItem(name, uni, number);
    m_teams.push_back(team_to_add);
    ui->listWidgetTeams->addItem(m_teams.back());
    ui->lineEditTeamName->clear();
    ui->lineEditTeamUni->clear();
    ui->lineEditTeamNumber->clear();
}


void MainWindow::finishSetup() {
    std::vector<EventType> event_types;

        // Checking choices for events in Standard Competition
        if (ui->checkBoxAcceleration->isChecked())              {event_types.push_back(acceleration);}
        if (ui->checkBoxAccelerationDV->isChecked())            {event_types.push_back(acceleration_DV);}
        if (ui->checkBoxAutocross->isChecked())                 {event_types.push_back(autocross);}
        if (ui->checkBoxEndurance->isChecked())                 {event_types.push_back(endurance);}
        if (ui->checkBoxSkidpad->isChecked())                   {event_types.push_back(skidpad);}
        if (ui->checkBoxSkidpadDV->isChecked())                 {event_types.push_back(skidpad_DV);}
        if (ui->checkBoxBusinessplan->isChecked())              {event_types.push_back(businessplan);}
        if (ui->checkBoxCostAndManufacturing->isChecked())      {event_types.push_back(cost_and_manufacturing);}
        if (ui->checkBoxEngineeringDesign->isChecked())         {event_types.push_back(engineering_design);}

        // Checking choices for events in Driverless Cup
        if (ui->checkBoxAccelerationDC->isChecked())            {event_types.push_back(acceleration_DC);}
        if (ui->checkBoxAutocrossDC->isChecked())               {event_types.push_back(autocross_DC);}
        if (ui->checkBoxSkidpadDC->isChecked())                 {event_types.push_back(skidpad_DC);}
        if (ui->checkBoxTrackdrive->isChecked())                {event_types.push_back(trackdrive);}
        if (ui->checkBoxEngineeringDesignDC->isChecked())       {event_types.push_back(engineering_design_DC);}

        // fetching additional event configuration information
        unsigned int number_of_finalists_businessplan = ui->spinBoxBusinessplanFinalists->value();
        unsigned int number_of_finalists_cost_and_manufacturing = ui->spinBoxCostAndManufacturingFinalists->value();
        unsigned int autocross_6mps_time = ui->lineEditAutocrossTime6mps->text().toUInt();

    // passing choices to competition manager
    competition_manager.set_event_types(event_types);
    competition_manager.set_endurance_efficiency(ui->checkBoxEnduranceEfficiency->isChecked());
    competition_manager.set_number_of_finalists(businessplan, number_of_finalists_businessplan);
    competition_manager.set_number_of_finalists(cost_and_manufacturing, number_of_finalists_cost_and_manufacturing);
    competition_manager.set_autocross_6mps_time(autocross_6mps_time);


    // going to next screen
    m_result_setting_current_index = 0;
    ui->baseStack->setCurrentIndex(ResultSettingScreenIndexNumber);

    ui->widgetResultSetting->clearWidget();
    ui->widgetResultSetting->setTeams(this->m_teams);
    ui->widgetResultSetting->setEventTypes(event_types);
    ui->widgetResultSetting->setupLayouts();

    this->resultSettingChangeScreen(m_result_setting_current_index);
}


void MainWindow::returnToSetup() {
    ui->baseStack->setCurrentIndex(SetupScreenIndexNumber);
    m_result_setting_current_index = 0;
    m_result_showing_current_index = 0;
    m_result_showing_mode = ResultShowingMode::Events;
}


void MainWindow::resultSettingChangeScreen(int event_index) {
    // setting ResultSettingWidget's screen to an event corresponding to the index
    EventType current_event_type = competition_manager.event_type_at(event_index);
    ui->widgetResultSetting->setCurrentIndex(event_index);
    ui->labelEventToSetResults->setText(QString::fromStdString(EVENT_TYPE_TO_STRING.at(current_event_type)));

    bool isAtFinalEvent = competition_manager.event_types().size() - 1 == m_result_setting_current_index;
    bool isAtFirstEvent = m_result_setting_current_index == 0;
    ui->pushButtonResultSettingNext->setEnabled(!isAtFinalEvent);
    ui->pushButtonResultSettingPrevious->setEnabled(!isAtFirstEvent);
    ui->pushButtonResultSettingFinish->setEnabled(isAtFinalEvent);
}


void MainWindow::resultSettingNextEvent() {
    m_result_setting_current_index += 1;
    this->resultSettingChangeScreen(m_result_setting_current_index);
}


void MainWindow::resultSettingPreviousEvent() {
    m_result_setting_current_index -= 1;
    this->resultSettingChangeScreen(m_result_setting_current_index);
}


void MainWindow::resultSettingFinish() {
    ui->widgetResultSetting->saveInput();
    ui->baseStack->setCurrentIndex(EventScoresScreenIndexNumber);
    competition_manager.setup_competition(m_teams);
    competition_manager.competition.create_classification();
    this->resultShowingUpdateMode();
}


void MainWindow::resultShowingNextEvent() {
    m_result_showing_current_index += 1;
    this->resultShowingChangeScreen(m_result_showing_current_index);
}

void MainWindow::resultShowingPreviousEvent() {
    m_result_showing_current_index -= 1;
    this->resultShowingChangeScreen(m_result_showing_current_index);
}


void MainWindow::resultShowingChangeScreen(int event_index) {
    EventType event_type_to_show = competition_manager.event_type_at(event_index);
    std::vector< std::pair<Team, double>> classification_to_show = competition_manager.competition.get_events_classifications().at(event_type_to_show);
    ui->widgetScoresShowing->setScores(classification_to_show);
    ui->labelEventShowingScores->setText(QString::fromStdString(EVENT_TYPE_TO_STRING.at(event_type_to_show)));

    bool isAtFinalEvent = competition_manager.event_types().size() - 1 == m_result_showing_current_index;
    bool isAtFirstEvent = m_result_showing_current_index == 0;
    ui->pushButtonEventScoresNext->setEnabled(!isAtFinalEvent);
    ui->pushButtonEventScoresPrevious->setEnabled(!isAtFirstEvent);
}

void MainWindow::resultShowingShowCompetition() {
    std::vector< std::pair<Team, double>> classification_to_show = competition_manager.competition.get_final_classification();
    ui->widgetScoresShowing->setScores(classification_to_show);
    ui->labelEventShowingScores->setText("Whole Competition Final Classification");
    this->ui->pushButtonEventScoresNext->setEnabled(false);
    this->ui->pushButtonEventScoresPrevious->setEnabled(false);
}


void MainWindow::returnToResultSetting() {
    this->ui->baseStack->setCurrentIndex(ResultSettingScreenIndexNumber);
}


void MainWindow::changeResultShowingMode() {
    if (m_result_showing_mode == ResultShowingMode::Competition) {
        m_result_showing_mode = ResultShowingMode::Events;
    } else {
        m_result_showing_mode = ResultShowingMode::Competition;
    }

    this->resultShowingUpdateMode();
}


void MainWindow::resultShowingUpdateMode() {
    switch(m_result_showing_mode) {
        case ResultShowingMode::Competition:
            this->resultShowingShowCompetition();
            this->ui->pushButtonShowCompetitionScores->setText("SHOW EVENTS SCORES");
            break;
        case ResultShowingMode::Events:
            this->resultShowingChangeScreen(m_result_showing_current_index);
            this->ui->pushButtonShowCompetitionScores->setText("SHOW COMPETITION SCORES");
            break;
    }
}


void MainWindow::updateFinalsSpinBoxes() {
    ui->spinBoxBusinessplanFinalists->setMaximum(m_teams.size());
    ui->spinBoxCostAndManufacturingFinalists->setMaximum(m_teams.size());
}
