#include "TomatoTimepiece.h"

TomatoTimepiece::TomatoTimepiece(QWidget *parent /* = 0 */)
{
    //timeDisplay_ = std::shared_ptr<TimeLCDDisplay>(new TimeLCDDisplay(parent));
    //timeDisplay_->initialize();
    //timeDisplay_->show();

    workTimerDisplay_ = std::shared_ptr<TimerLCDDisplay>(new TimerLCDDisplay(parent, DEFAULT_WORKTIMERCOUNT));
    workTimerDisplay_->initialize();
    workTimerDisplay_->show();
}

TomatoTimepiece::~TomatoTimepiece()
{
}


