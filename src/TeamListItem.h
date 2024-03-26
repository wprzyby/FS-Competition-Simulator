#pragma once

#include <QObject>
#include <QWidget>
#include <QListWidgetItem>

#include <Team.h>


class TeamListItem
        : public QListWidgetItem
{
public:
    Team team;
    TeamListItem(QString name, QListWidget *parent = nullptr);
};
