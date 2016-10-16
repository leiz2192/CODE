#include "TimeDisplay.hpp"

#include <QTime>
#include <QString>

TimeLCDDisplay::TimeLCDDisplay(QWidget *parent)
    : LCDDisplay(parent)
{
}

void TimeLCDDisplay::displaySlot()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    display_->display(text);
}

