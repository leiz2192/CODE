#ifndef __TOMATOTIMEPIECE_H__
#define __TOMATOTIMEPIECE_H__

//#include <QtWidgets/QMainWindow>
//#include "ui_tomatotimer.h"

#include "LCDDisplay.h"
#include "TimeLCDDisplay.h"
#include "TimerLCDDisplay.h"

class TomatoTimepiece
{
public:
    TomatoTimepiece(QWidget *parent = 0);
    virtual ~TomatoTimepiece();

private:
    std::shared_ptr<LCDDisplay> timeDisplay_;
    std::shared_ptr<LCDDisplay> workTimerDisplay_;
    std::shared_ptr<LCDDisplay> restTimerDisplay_;
};


#endif  //__TOMATOTIMEPIECE_H__


