#ifndef __WORKLCDDISPLAY_H__
#define __WORKLCDDISPLAY_H__

#include "LCDDisplay.h"

const unsigned int DEFAULT_WORKTIMERCOUNT = 25 * 60;

class TimerLCDDisplay : public LCDDisplay
{
public:
    TimerLCDDisplay(QWidget *parent, unsigned timecount);
    virtual ~TimerLCDDisplay() {}

    virtual void initialize();

private slots:
    virtual void displaySlot();

private:
    unsigned int timecnt_;
};

#endif  //__WORKLCDDISPLAY_H__


