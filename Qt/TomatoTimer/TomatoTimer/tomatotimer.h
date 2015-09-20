#ifndef TOMATOTIMER_H
#define TOMATOTIMER_H

#include <QtWidgets/QMainWindow>
#include "ui_tomatotimer.h"

#include <QLCDNumber>
#include <QGroupBox>
#include <QDialog>
#include <QPushButton>

#include <QMenu>
#include <QCursor>

enum LCDSHOWTYPE {TIME, WORK, REST};

const int DEFAULT_WORKTIMERCOUNT = 25 * 60;
const int DEFAULT_RESTTIMERCOUNT = 5 * 60;

class TomatoTimer : public QDialog
{
    Q_OBJECT

public:
    TomatoTimer(QWidget *parent = 0);
    ~TomatoTimer();

private:
    void createTimeGroupBox();
    void createTimerGroupBox();

    void contextMenuEvent(QContextMenuEvent *);

private:
    QTimer * timeTimer;

    QGroupBox *timeGroupBox;
    QLCDNumber *timeLCD;

    QGroupBox *timerGroupBox;
    QPushButton *workTimerButton;
    QPushButton *restTimerButton;

    LCDSHOWTYPE lcdShowFlag;

    int workTimerCount;
    int restTimerCount;

    int RESET_WORKTIMERCOUNT;
    int RESET_RESTTIMERCOUNT;

    QAction *setTimeAction;
    QComboBox *timeSetSelectType;
    QLineEdit *lineEdit;
    QDialog *setTimeDialog;

private slots:
    void showLCD();
    void workTimerButtonEvent(bool checked);
    void restTimerButtonEvent(bool checked);

    void setTimeActionEvent();
    void setTimeLineEditEvent();
};

#endif // TOMATOTIMER_H
