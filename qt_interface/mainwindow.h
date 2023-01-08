#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonChooseCompsim_clicked();
    void on_pushButtonAddTeam_clicked();
    void updateCheckBoxes();
    void backToMainMenu();
    void finishSetup();
    void returnToSetup();
    void resultSettingNextEvent();
    void resultSettingPreviousEvent();


private:
    Ui::MainWindow *ui;
    std::list<TeamListItem*> m_teams;
    CompetitionManager competition_manager;
    int m_result_setting_current_index=0;

    void resultSettingChangeScreen(int event_index);
};
#endif // MAINWINDOW_H
