#ifndef TOMATOTIMER_H
#define TOMATOTIMER_H

#include <QtWidgets/QMainWindow>
#include "ui_tomatotimer.h"

#include <QLCDNumber>
#include <QGroupBox>
#include <QDialog>
#include <QPushButton>

enum LCDSHOWTYPE {TIME, WORK, REST};

const int WORKTIMERCOUNT = 25 * 60;
const int RESTTIMERCOUNT = 5 * 60;

class TomatoTimer : public QDialog
{
    Q_OBJECT

public:
    TomatoTimer(QWidget *parent = 0);
    ~TomatoTimer();

private:
    void createTimeGroupBox();
    void createTimerGroupBox();

    QTimer * timeTimer;

    QGroupBox *timeGroupBox;
    QLCDNumber *timeLCD;

    QGroupBox *timerGroupBox;
    QPushButton *workTimerButton;
    QPushButton *restTimerButton;

    LCDSHOWTYPE lcdShowFlag;

    int workTimerCount;
    int restTimerCount;
private slots:
    void showLCD();
    void workTimerButtonEvent(bool checked);
    void restTimerButtonEvent(bool checked);
};

#endif // TOMATOTIMER_H
