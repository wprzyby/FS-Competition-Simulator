#include "TeamListItem.h"
#include <QWidget>
#include <qnamespace.h>

TeamListItem::TeamListItem(QString name, QListWidget *parent)
        : QListWidgetItem(parent) {
            setTextAlignment(Qt::AlignCenter);
            setFont(QFont("Lato Medium", 25));
            setText(name);
            team.set_name(name.toStdString());
        }