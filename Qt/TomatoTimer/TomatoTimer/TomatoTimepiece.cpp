#include "TomatoTimepiece.h"

TomatoTimepiece::TomatoTimepiece(QWidget *parent /* = 0 */)
{
    timeDisplay_ = std::shared_ptr<TimeLCDDisplay>(new TimeLCDDisplay(parent));
    workTimerDisplay_ = std::shared_ptr<TimerLCDDisplay>(new TimerLCDDisplay(parent, DEFAULT_WORKTIMERCOUNT));
    restTimerDisplay_ = std::shared_ptr<TimerLCDDisplay>(new TimerLCDDisplay(parent, DEFAULT_RESTTIMERCOUNT));

    displayGroupBox_ = timeDisplay_->getDisplayQGroupBox();
    
    menuBar_ = std::shared_ptr<QMenuBar>(new QMenuBar(this));
    helpMenu_ = std::shared_ptr<QMenu>(menuBar_->addMenu(tr("&Help")));

    timeAct_ = std::shared_ptr<QAction>(new QAction(tr("&Time"), this));
    connect(timeAct_.get(), SIGNAL(triggered()), this, SLOT(timeslots()));

    workAct_ = std::shared_ptr<QAction>(new QAction(tr("&Work"), this));
    connect(workAct_.get(), SIGNAL(triggered()), this, SLOT(workslots()));

    restAct_ = std::shared_ptr<QAction>(new QAction(tr("&Rest"), this));
    connect(restAct_.get(), SIGNAL(triggered()), this, SLOT(restslots()));

    exitAct_ = std::shared_ptr<QAction>(new QAction(tr("&Exit"), this));
    connect(exitAct_.get(), SIGNAL(triggered()), this, SLOT(exitslots()));
    
    helpMenu_->addAction(timeAct_.get());
    helpMenu_->addAction(workAct_.get());
    helpMenu_->addAction(restAct_.get());
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
    displayGroupBox_->setParent(NULL);

    displayGroupBox_ = timeDisplay_->getDisplayQGroupBox();
    mainLayout_->addWidget(displayGroupBox_.get());
}

void TomatoTimepiece::workslots()
{
    displayGroupBox_->setParent(NULL);

    workTimerDisplay_->initialize();
    displayGroupBox_ = workTimerDisplay_->getDisplayQGroupBox();
    mainLayout_->addWidget(displayGroupBox_.get());
}

void TomatoTimepiece::restslots()
{
    displayGroupBox_->setParent(NULL);

    restTimerDisplay_->initialize();
    displayGroupBox_ = restTimerDisplay_->getDisplayQGroupBox();
    mainLayout_->addWidget(displayGroupBox_.get());
}

