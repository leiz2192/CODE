#include "TomatoTimepiece.h"

TomatoTimepiece::TomatoTimepiece(QWidget *parent /* = 0 */)
{
    timeDisplay_ = std::shared_ptr<TimeLCDDisplay>(new TimeLCDDisplay(parent));
    
    workTimerDisplay_ = std::shared_ptr<TimerLCDDisplay>(new TimerLCDDisplay(parent, DEFAULT_WORKTIMERCOUNT));
    connect(workTimerDisplay_.get(), SIGNAL(timer_end()), this, SLOT(cancelslots()));

    
    restTimerDisplay_ = std::shared_ptr<TimerLCDDisplay>(new TimerLCDDisplay(parent, DEFAULT_RESTTIMERCOUNT));
    connect(restTimerDisplay_.get(), SIGNAL(timer_end()), this, SLOT(cancelslots()));


    displayGroupBox_ = timeDisplay_->getDisplayQGroupBox();
    
    menuBar_ = std::shared_ptr<QMenuBar>(new QMenuBar(this));
    tomatoMenu_ = std::shared_ptr<QMenu>(menuBar_->addMenu(tr("&TomatoTimer")));

    workAct_ = std::shared_ptr<QAction>(new QAction(tr("&Work"), this));
    connect(workAct_.get(), SIGNAL(triggered()), this, SLOT(workslots()));

    restAct_ = std::shared_ptr<QAction>(new QAction(tr("&Rest"), this));
    connect(restAct_.get(), SIGNAL(triggered()), this, SLOT(restslots()));
    
    cancelAct_ = std::shared_ptr<QAction>(new QAction(tr("&Cancel"), this));
    connect(cancelAct_.get(), SIGNAL(triggered()), this, SLOT(cancelslots()));
    cancelAct_->setEnabled(false);

    tomatoMenu_->addAction(workAct_.get());
    tomatoMenu_->addAction(restAct_.get());
    tomatoMenu_->addAction(cancelAct_.get());

    helpMenu_ = std::shared_ptr<QMenu>(menuBar_->addMenu(tr("&Help")));

    timeAct_ = std::shared_ptr<QAction>(new QAction(tr("&Time"), this));
    connect(timeAct_.get(), SIGNAL(triggered()), this, SLOT(timeslots()));

    exitAct_ = std::shared_ptr<QAction>(new QAction(tr("&Exit"), this));
    connect(exitAct_.get(), SIGNAL(triggered()), this, SLOT(exitslots()));

    helpMenu_->addAction(timeAct_.get());
    helpMenu_->addAction(exitAct_.get());

    mainLayout_ = std::shared_ptr<QHBoxLayout>(new QHBoxLayout());
    mainLayout_->addWidget(displayGroupBox_.get());
    mainLayout_->setMenuBar(menuBar_.get());
    setLayout(mainLayout_.get());

    setWindowTitle(tr(MainDialogName.c_str()));
    resize(289, 112);
}

TomatoTimepiece::~TomatoTimepiece()
{
}

void TomatoTimepiece::exitslots()
{
    close();
}

void TomatoTimepiece::timeslots()
{
    cancelAct_->setEnabled(false);

    displayGroupBox_->setParent(NULL);

    displayGroupBox_ = timeDisplay_->getDisplayQGroupBox();
    mainLayout_->addWidget(displayGroupBox_.get());
}

void TomatoTimepiece::workslots()
{
    restAct_->setEnabled(false);
    cancelAct_->setEnabled(true);

    displayGroupBox_->setParent(NULL);

    workTimerDisplay_->initialize();
    displayGroupBox_ = workTimerDisplay_->getDisplayQGroupBox();
    mainLayout_->addWidget(displayGroupBox_.get());
}

void TomatoTimepiece::restslots()
{
    workAct_->setEnabled(false);
    cancelAct_->setEnabled(true);

    displayGroupBox_->setParent(NULL);

    restTimerDisplay_->initialize();
    displayGroupBox_ = restTimerDisplay_->getDisplayQGroupBox();
    mainLayout_->addWidget(displayGroupBox_.get());
}

void TomatoTimepiece::cancelslots()
{
    restAct_->setEnabled(true);
    workAct_->setEnabled(true);

    workTimerDisplay_->timer_stop();
    restTimerDisplay_->timer_stop();

    timeslots();
}

