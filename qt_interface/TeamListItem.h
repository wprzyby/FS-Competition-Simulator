#pragma once

#include <QObject>
#include <QWidget>
#include <QListWidgetItem>
#include <compsim_classes/Team.h>


class TeamListItem
        : public QListWidgetItem
{
public:
    Team team;
    TeamListItem(QString name, QString university="", QString number=0, QListWidget *parent = nullptr);
};
