#include "TimerLCDDisplay.h"

TimerLCDDisplay::TimerLCDDisplay(QWidget *parent, unsigned timecount)
    : LCDDisplay(parent)
    , timecnt_(timecount)
{
}

void TimerLCDDisplay::displaySlot()
{
    if (timecnt_ < 0) {
    } else {
        QTime time(0, 0, timecnt_);
        QString text = time.toString("hh:mm:ss");
        display_->display(text);

        --timecnt_;
    }
}

