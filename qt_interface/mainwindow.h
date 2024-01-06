#pragma once
#include "TeamListItem.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include <list>
#include "CompetitionManager.h"

#include <compsim_classes/Team.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum class ResultShowingMode {Events, Competition};
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonChooseCompsim_clicked();
    void on_pushButtonAddTeam_clicked();
    void backToMainMenu();
    void finishSetup();
    void returnToSetup();
    void resultSettingNextEvent();
    void resultSettingPreviousEvent();
    void resultSettingFinish();
    void resultShowingNextEvent();
    void resultShowingPreviousEvent();
    void returnToResultSetting();
    void changeResultShowingMode();
    void updateFinalsSpinBoxes();


private:
    Ui::MainWindow *ui;
    std::list<TeamListItem*> m_teams;
    CompetitionManager competition_manager;
    int m_result_setting_current_index=0;
    int m_result_showing_current_index=0;
    ResultShowingMode m_result_showing_mode=ResultShowingMode::Events;


    void resultShowingChangeScreen(int event_index);
    void resultSettingChangeScreen(int event_index);
    void resultShowingUpdateMode();
    void resultShowingShowCompetition();
};