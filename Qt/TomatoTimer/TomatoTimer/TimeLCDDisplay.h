#ifndef __TIMEDISPLAY_H__
#define __TIMEDISPLAY_H__

#include "Display.h"

class TimeLCDDisplay : public LCDDisplay
{
public:
    TimeLCDDisplay(QWidget *parent = 0);
    virtual ~TimeLCDDisplay() {}

    virtual void displaySlot();
}

#endif  //__TIMEDISPLAY_H__

