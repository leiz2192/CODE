#include "tomatotimer.h"
#include <QDebug>

#include <QTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPalette>
#include <QComboBox>
#include <QLineEdit>
#include <QValidator>

TomatoTimer::TomatoTimer(QWidget *parent)
    : lcdShowFlag(TIME)
    , workTimerCount(DEFAULT_WORKTIMERCOUNT)
    , restTimerCount(DEFAULT_RESTTIMERCOUNT)
    , RESET_WORKTIMERCOUNT(DEFAULT_WORKTIMERCOUNT)
    , RESET_RESTTIMERCOUNT(DEFAULT_RESTTIMERCOUNT)
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
    if (!checked) {
        workTimerCount = RESET_WORKTIMERCOUNT;
    }

    workTimerButton->setText(tr((checked) ? "&Working..." : "Start &Work"));
    lcdShowFlag = (checked) ? WORK : TIME;
    restTimerButton->setDisabled(checked);
    setTimeAction->setDisabled(checked);
}

void TomatoTimer::restTimerButtonEvent(bool checked)
{
    if (! checked) {
        restTimerCount = RESET_RESTTIMERCOUNT;
    }

    restTimerButton->setText(tr((checked) ? "&Resting..." : "Start &Rest"));
    lcdShowFlag = (checked) ? REST : TIME;
    workTimerButton->setDisabled(checked);
    setTimeAction->setDisabled(checked);
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
    timeSetSelectType = new QComboBox;
    timeSetSelectType->addItem(tr("Work Time"));
    timeSetSelectType->addItem(tr("Rest Time"));
    timeSetSelectType->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    lineEdit = new QLineEdit();
    QIntValidator *intValidator = new QIntValidator();
    intValidator->setBottom(0);
    lineEdit->setValidator(intValidator);
    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(setTimeLineEditEvent()));

    QPushButton *button = new QPushButton(tr("OK"));
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    connect(button, SIGNAL(clicked()), this, SLOT(setTimeLineEditEvent()));

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(timeSetSelectType);
    layout->addWidget(lineEdit);
    layout->addWidget(button);

    setTimeDialog = new QDialog();
    setTimeDialog->setWindowTitle(tr("Set Time"));
    setTimeDialog->setLayout(layout);

    setTimeDialog->show();
}

void TomatoTimer::setTimeLineEditEvent()
{
    if (lineEdit->text().isEmpty())
    {
        workTimerCount = RESET_WORKTIMERCOUNT;
        restTimerCount = RESET_RESTTIMERCOUNT;
    } else if (timeSetSelectType->currentText() == "Work Time") {
        workTimerCount = lineEdit->text().toInt();
        RESET_WORKTIMERCOUNT = workTimerCount;
    } else if (timeSetSelectType->currentText() == "Rest Time") {
        restTimerCount = lineEdit->text().toInt();
        RESET_RESTTIMERCOUNT = restTimerCount;
    }
    setTimeDialog->close();
}

