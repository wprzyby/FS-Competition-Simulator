#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "teamlistitem.h"
#include "constants.h"
#include <QDebug>
#include <qdebug.h>
#include <compsim_enums/enums.h>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->baseStack->setCurrentIndex(MainMenuIndexNumber);
    updateCheckBoxes();
    ui->lineEditTeamNumber->setValidator(new QIntValidator(this));
    connect(ui->pushButtonBackToMenu, SIGNAL(clicked()), this, SLOT(backToMainMenu()));
    connect(ui->checkBoxStandardCompetition, SIGNAL(clicked()), this, SLOT(updateCheckBoxes()));
    connect(ui->checkBoxDriverlessCup, SIGNAL(clicked()), this, SLOT(updateCheckBoxes()));
    connect(ui->checkBoxAcceleration, SIGNAL(clicked()), this, SLOT(updateCheckBoxes()));
    connect(ui->checkBoxEndurance, SIGNAL(clicked()), this, SLOT(updateCheckBoxes()));
    connect(ui->checkBoxSkidpad, SIGNAL(clicked()), this, SLOT(updateCheckBoxes()));
    connect(ui->pushButtonFinishSetup, SIGNAL(clicked()), this, SLOT(finishSetup()));
    connect(ui->pushButtonChangeSetup, SIGNAL(clicked()), this, SLOT(returnToSetup()));
}

MainWindow::~MainWindow() {
    delete ui;
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
    TeamListItem team_to_add(name, uni, number);
    teams.push_back(team_to_add);
    ui->listWidgetTeams->addItem(&teams.back());
    ui->lineEditTeamName->clear();
    ui->lineEditTeamUni->clear();
    ui->lineEditTeamNumber->clear();
}

void MainWindow::updateCheckBoxes() {
    // updating updating availability of check boxes for modes of Competition (Standard/Driverless Cup)
    bool isStandardCompetitionChecked = ui->checkBoxStandardCompetition->isChecked();
    ui->checkBoxesEventsStandard->setEnabled(isStandardCompetitionChecked);
    ui->checkBoxesEventsDC->setEnabled(!isStandardCompetitionChecked);

    // updating availability of check boxes for additional events (e.g. DV Acceleration) based on whether the main event is checked (e.g. Acceleration)
    ui->checkBoxAccelerationDV->setEnabled(ui->checkBoxAcceleration->isChecked());
    ui->checkBoxSkidpadDV->setEnabled(ui->checkBoxSkidpad->isChecked());
    ui->checkBoxEnduranceEfficiency->setEnabled(ui->checkBoxEndurance->isChecked());
}


void MainWindow::finishSetup() {
    std::vector<EventType> event_types;

    if (ui->checkBoxStandardCompetition->isChecked()) {
        // Checking choices for events in Standard Competition (if selected)
        if (ui->checkBoxAcceleration->isChecked())              {event_types.push_back(acceleration);
            if (ui->checkBoxAccelerationDV->isChecked())        {event_types.push_back(acceleration_DV);} }
        if (ui->checkBoxAutocross->isChecked())                 {event_types.push_back(autocross);}
        if (ui->checkBoxEndurance->isChecked())                 {event_types.push_back(endurance);}
        if (ui->checkBoxSkidpad->isChecked())                   {event_types.push_back(skidpad);
            if (ui->checkBoxSkidpadDV->isChecked())             {event_types.push_back(skidpad_DV);} }
        if (ui->checkBoxBusinessplan->isChecked())              {event_types.push_back(businessplan);}
        if (ui->checkBoxCostAndManufacturing->isChecked())      {event_types.push_back(cost_and_manufacturing);}
        if (ui->checkBoxEngineeringDesign->isChecked())         {event_types.push_back(engineering_design);}
    } else {
        // Checking choices for events in Driverless Cup (if selected)
        if (ui->checkBoxAccelerationDC->isChecked())            {event_types.push_back(acceleration_DC);}
        if (ui->checkBoxAutocrossDC->isChecked())               {event_types.push_back(autocross_DC);}
        if (ui->checkBoxSkidpadDC->isChecked())                 {event_types.push_back(skidpad_DC);}
        if (ui->checkBoxTrackdrive->isChecked())                {event_types.push_back(trackdrive);}
    }

    // passing choices to competition manager
    competition_manager.set_event_types(event_types);
    competition_manager.set_endurance_efficiency(ui->checkBoxEnduranceEfficiency->isChecked());

    // going to next screen
    ui->baseStack->setCurrentIndex(ResultSettingScreenIndexNumber);
}


void MainWindow::returnToSetup() {
    ui->baseStack->setCurrentIndex(SetupScreenIndexNumber);
}