#include "tomatotimer.h"

#include <QTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPalette>

#include <QDebug>

TomatoTimer::TomatoTimer(QWidget *parent)
    : lcdShowFlag(TIME)
    , workTimerCount(WORKTIMERCOUNT)
    , restTimerCount(RESTTIMERCOUNT)
{
    createTimeGroupBox();
    createTimerGroupBox();

    QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->addWidget(timeGroupBox);
    mainLayout->addWidget(timerGroupBox);
    setLayout(mainLayout);
    
    setTimeAction = new QAction(tr("SetTime"), this);
    connect(setTimeAction, SIGNAL(triggered()), this, SLOT(setTimeActionEvent()));

    setWindowTitle(tr("Tomato Timer"));
    resize(316, 75);
}

TomatoTimer::~TomatoTimer()
{
}

void TomatoTimer::createTimeGroupBox()
{
    timeLCD = new QLCDNumber(this);
    timeLCD->setSegmentStyle(QLCDNumber::Flat);
    timeLCD->setDigitCount(8);

    timeTimer = new QTimer(this);
    connect(timeTimer, SIGNAL(timeout()), this, SLOT(showLCD()));
    timeTimer->start(1000);
    
    showLCD();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(timeLCD);

    timeGroupBox = new QGroupBox();
    timeGroupBox->setLayout(layout);
}

void TomatoTimer::createTimerGroupBox()
{
    workTimerButton = new QPushButton(tr("Start &Work"));
    workTimerButton->setDefault(true);
    workTimerButton->setCheckable(true);
    connect(workTimerButton, SIGNAL(toggled(bool)), this, SLOT(workTimerButtonEvent(bool)));

    restTimerButton = new QPushButton(tr("Start &Rest"));
    restTimerButton->setCheckable(true);
    connect(restTimerButton, SIGNAL(toggled(bool)), this, SLOT(restTimerButtonEvent(bool)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(workTimerButton);
    layout->addWidget(restTimerButton);

    timerGroupBox = new QGroupBox();
    timerGroupBox->setLayout(layout);
    timerGroupBox->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
}

void TomatoTimer::showLCD()
{
    QString text;
    QTime time(0, 0, 0);
    switch (lcdShowFlag) {
    case WORK:
        if (workTimerCount > 0) {
            //text = QString("%1:%2:%3").arg(workTimerCount / 3600, 2).arg(workTimerCount / 60, 2).arg(workTimerCount % 60, 2);
            time = time.addSecs(workTimerCount);
            --workTimerCount;
        } else {
            workTimerButton->toggle();
            QMessageBox::information(this, "WORK", "Work Time Finished", QMessageBox::Ok);
        }
        break;
    case REST:
        if (restTimerCount > 0) {
            //text = QString("%1:%2:%3").arg(restTimerCount / 3600, 2).arg(restTimerCount / 60, 2).arg(restTimerCount % 60, 2);
            time = time.addSecs(restTimerCount);
            --restTimerCount;
        } else {
            restTimerButton->toggle();
            QMessageBox::information(this, "REST", "Rest Time Finished", QMessageBox::Ok);
        }
        break;
    case TIME:
    default:
        time = QTime::currentTime();
    }

    text = time.toString("hh:mm:ss");
    timeLCD->display(text);
}

void TomatoTimer::workTimerButtonEvent(bool checked)
{
    if (checked) {
        workTimerButton->setText(tr("&Working..."));
        restTimerButton->setDisabled(true);
        lcdShowFlag = WORK;
    }
    else {
        workTimerButton->setText(tr("Start &Work"));
        restTimerButton->setDisabled(false);
        lcdShowFlag = TIME;
        workTimerCount = WORKTIMERCOUNT;
    }
}

void TomatoTimer::restTimerButtonEvent(bool checked)
{
    if (checked) {
        restTimerButton->setText(tr("&Resting..."));
        workTimerButton->setDisabled(true);
        lcdShowFlag = REST;
    }
    else {
        restTimerButton->setText(tr("Start &Rest"));
        workTimerButton->setDisabled(false);
        lcdShowFlag = TIME;
        restTimerCount = RESTTIMERCOUNT;
    }
}

void TomatoTimer::contextMenuEvent(QContextMenuEvent *)
{
    QMenu *menu = new QMenu(this);
    menu->addAction(setTimeAction);

    QCursor cur = this->cursor();
    menu->exec(cur.pos());
}

void TomatoTimer::setTimeActionEvent()
{
    QDialog *setTimeDialog = new QDialog();
    setTimeDialog->setWindowTitle(tr("Set Time"));
    setTimeDialog->show();
}

