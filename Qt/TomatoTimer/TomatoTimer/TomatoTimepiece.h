#ifndef __TOMATOTIMEPIECE_H__
#define __TOMATOTIMEPIECE_H__

//#include <QtWidgets/QMainWindow>
//#include "ui_tomatotimer.h"

#include "LCDDisplay.h"
#include "TimeLCDDisplay.h"
#include "TimerLCDDisplay.h"
#include "CommonDef.h"

#include <QHBoxLayout>
#include <QDialog>
#include <QMenuBar>

class TomatoTimepiece : public QDialog
{
    Q_OBJECT

public:
    TomatoTimepiece(QWidget *parent = 0);
    virtual ~TomatoTimepiece();

private slots:
    void timeslots();
    void workslots();
    void restslots();
    void exitslots();

private:
    std::shared_ptr<LCDDisplay> timeDisplay_;
    std::shared_ptr<LCDDisplay> workTimerDisplay_;
    std::shared_ptr<LCDDisplay> restTimerDisplay_;

    std::shared_ptr<QGroupBox> displayGroupBox_;

    std::shared_ptr<QHBoxLayout> mainLayout_;
    std::shared_ptr<QMenuBar> menuBar_;
    std::shared_ptr<QMenu> helpMenu_;
    std::shared_ptr<QAction> timeAct_;
    std::shared_ptr<QAction> workAct_;
    std::shared_ptr<QAction> restAct_;
    std::shared_ptr<QAction> exitAct_;
};

#endif  //__TOMATOTIMEPIECE_H__


