#ifndef __WORKLCDDISPLAY_H__
#define __WORKLCDDISPLAY_H__

#include "LCDDisplay.h"

const int DEFAULT_WORKTIMERCOUNT = 25 * 60;

class TimerLCDDisplay : public LCDDisplay
{
public:
    TimerLCDDisplay(QWidget *parent, unsigned timecount);
    virtual ~TimerLCDDisplay() {}

    virtual void displaySlot();

private:
    unsigned timecnt_;
}

#endif  //__WORKLCDDISPLAY_H__


