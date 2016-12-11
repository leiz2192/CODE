#include "TimerLCDDisplay.h"

#include <QTime>
#include <QString>

TimerLCDDisplay::TimerLCDDisplay(QWidget *parent, unsigned timecount)
    : LCDDisplay(parent)
    , timecnt_(timecount)
{
}

void TimerLCDDisplay::initialize()
{
    LCDDisplay::initialize();
}

void TimerLCDDisplay::displaySlot()
{
    if (timecnt_ < 0) {
    } else {
        QTime time(0, 0, 0);
        time = time.addSecs(timecnt_);
        QString text = time.toString("hh:mm:ss");
        display_->display(text);

        --timecnt_;
    }
}

