#include "TeamListItem.h"
#include <QWidget>
#include <qnamespace.h>

TeamListItem::TeamListItem(QString name, QString university, QString number, QListWidget *parent)
        : QListWidgetItem(parent) {
            setTextAlignment(Qt::AlignCenter);
            setFont(QFont("Lato Medium", 25));
            QString number_on_display = (number.toInt()==0) ? "--" : number;
            setText(name + " (" + number_on_display + ")");
            team.set_name(name.toStdString());
            team.set_university(university.toStdString());
            team.set_number(number.toInt());
        }