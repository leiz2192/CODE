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
#include <QCloseEvent>

TomatoTimer::TomatoTimer(QWidget *parent)
    : m_lcdShowType(TIME)
    , workTimerCount(DEFAULT_WORKTIMERCOUNT)
    , restTimerCount(DEFAULT_RESTTIMERCOUNT)
    , RESET_WORKTIMERCOUNT(DEFAULT_WORKTIMERCOUNT)
    , RESET_RESTTIMERCOUNT(DEFAULT_RESTTIMERCOUNT)
{
    initDisplayGroupBox();
    initTimerButtonGroupBox();
    initMenu();
    initTimerSetDialog();

    QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_displayGroupBox);
    mainLayout->addWidget(m_timerButtonGroupBox);
    setLayout(mainLayout);
    
    setWindowTitle(tr("Tomato Timer"));
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    resize(316, 75);
}

TomatoTimer::~TomatoTimer()
{
}

void TomatoTimer::initDisplayGroupBox()
{
    m_displayLCD = new QLCDNumber(this);
    m_displayLCD->setSegmentStyle(QLCDNumber::Flat);
    m_displayLCD->setDigitCount(8);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(lcdDisplaySlot()));
    m_timer->start(1000);
    
    lcdDisplaySlot();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(m_displayLCD);

    m_displayGroupBox = new QGroupBox();
    m_displayGroupBox->setLayout(layout);
}

void TomatoTimer::initTimerButtonGroupBox()
{
    m_workTimerButton = new QPushButton(tr("Start &Work"));
    m_workTimerButton->setDefault(true);
    m_workTimerButton->setCheckable(true);
    connect(m_workTimerButton, SIGNAL(toggled(bool)), this, SLOT(workTimerButtonSlot(bool)));

    m_restTimerButton = new QPushButton(tr("Start &Rest"));
    m_restTimerButton->setCheckable(true);
    connect(m_restTimerButton, SIGNAL(toggled(bool)), this, SLOT(restTimerButtonSlot(bool)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(m_workTimerButton);
    layout->addWidget(m_restTimerButton);

    m_timerButtonGroupBox = new QGroupBox();
    m_timerButtonGroupBox->setLayout(layout);
    m_timerButtonGroupBox->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
}

void TomatoTimer::initMenu()
{
    m_timerSetAction = new QAction(tr("Set Timer"), this);
    connect(m_timerSetAction, SIGNAL(triggered()), this, SLOT(timerSetActionSlot()));
}

void TomatoTimer::initTimerSetDialog()
{
    m_setTypeForTimerSet = new QComboBox;
    m_setTypeForTimerSet->addItem(tr("Work Time"));
    m_setTypeForTimerSet->addItem(tr("Rest Time"));
    m_setTypeForTimerSet->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_lineEditForTimerSet = new QLineEdit();
    QIntValidator *intValidator = new QIntValidator();
    intValidator->setBottom(0);
    m_lineEditForTimerSet->setValidator(intValidator);
    connect(m_lineEditForTimerSet, SIGNAL(editingFinished()), this, SLOT(timerSetLineEditSlot()));

    QPushButton *button = new QPushButton(tr("OK"));
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    connect(button, SIGNAL(clicked()), this, SLOT(timerSetLineEditSlot()));

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(m_setTypeForTimerSet);
    layout->addWidget(m_lineEditForTimerSet);
    layout->addWidget(button);

    m_timerSetDialog = new QDialog();
    m_timerSetDialog->setLayout(layout);
    m_timerSetDialog->setWindowTitle(tr("Set Timer"));

    connect(m_timerSetDialog, SIGNAL(finished(int)), this, SLOT(timerSetDialogSlot()));
}

void TomatoTimer::lcdDisplaySlot()
{
    QString text;
    QTime time(0, 0, 0);
    switch (m_lcdShowType) {
    case WORK:
        if (workTimerCount > 0) {
            //text = QString("%1:%2:%3").arg(workTimerCount / 3600, 2).arg(workTimerCount / 60, 2).arg(workTimerCount % 60, 2);
            time = time.addSecs(workTimerCount);
            --workTimerCount;
            break;
        } else {
            m_workTimerButton->toggle();
            QMessageBox::information(this, "WORK", "Work Time Finished", QMessageBox::Ok);
        }
    case REST:
        if (restTimerCount > 0) {
            //text = QString("%1:%2:%3").arg(restTimerCount / 3600, 2).arg(restTimerCount / 60, 2).arg(restTimerCount % 60, 2);
            time = time.addSecs(restTimerCount);
            --restTimerCount;
            break;
        } else {
            m_restTimerButton->toggle();
            QMessageBox::information(this, "REST", "Rest Time Finished", QMessageBox::Ok);
        }
    case TIME:
    default:
        time = QTime::currentTime();
    }

    text = time.toString("hh:mm:ss");
    m_displayLCD->display(text);
}

void TomatoTimer::workTimerButtonSlot(bool checked)
{
    if (!checked) {
        workTimerCount = RESET_WORKTIMERCOUNT;
    }

    m_workTimerButton->setText(tr((checked) ? "&Working..." : "Start &Work"));
    m_lcdShowType = (checked) ? WORK : TIME;
    m_restTimerButton->setDisabled(checked);
    m_timerSetAction->setDisabled(checked);
}

void TomatoTimer::restTimerButtonSlot(bool checked)
{
    if (!checked) {
        restTimerCount = RESET_RESTTIMERCOUNT;
    }

    m_restTimerButton->setText(tr((checked) ? "&Resting..." : "Start &Rest"));
    m_lcdShowType = (checked) ? REST : TIME;
    m_workTimerButton->setDisabled(checked);
    m_timerSetAction->setDisabled(checked);
}

void TomatoTimer::contextMenuEvent(QContextMenuEvent *)
{
    QMenu *menu = new QMenu(this);
    menu->addAction(m_timerSetAction);
    menu->exec(cursor().pos());
}

void TomatoTimer::timerSetActionSlot()
{
    //setTimeDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    //setTimeDialog->setWindowFlags(Qt::Widget);
    m_timerSetDialog->show();

    m_workTimerButton->setDisabled(true);
    m_restTimerButton->setDisabled(true);
}

void TomatoTimer::timerSetLineEditSlot()
{
    if (m_lineEditForTimerSet->text().isEmpty())
    {
        workTimerCount = DEFAULT_WORKTIMERCOUNT;
        restTimerCount = DEFAULT_RESTTIMERCOUNT;
    } else if (m_setTypeForTimerSet->currentText() == "Work Time") {
        workTimerCount = m_lineEditForTimerSet->text().toInt();
    } else if (m_setTypeForTimerSet->currentText() == "Rest Time") {
        restTimerCount = m_lineEditForTimerSet->text().toInt();
    }
    RESET_WORKTIMERCOUNT = workTimerCount;
    RESET_RESTTIMERCOUNT = restTimerCount;
    m_timerSetDialog->close();

    timerSetDialogSlot();
}

void TomatoTimer::timerSetDialogSlot()
{
    m_workTimerButton->setDisabled(false);
    m_restTimerButton->setDisabled(false);
}

