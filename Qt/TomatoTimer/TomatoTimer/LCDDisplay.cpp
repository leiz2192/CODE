#include "LCDDisplay.h"

LCDDisplay::LCDDisplay(QWidget *parent /* = 0 */)
{
}

void LCDDisplay::initialize()
{
    display_ = std::auto_ptr<QLCDNumber>(new QLCDNumber(this));
    display_->setSegmentStyle(QLCDNumber::Flat);
    display_->setDigitCount(8);

    timer_ = std::auto_ptr<QTimer>(new QTimer(this));
    connect(timer_, SIGNAL(timeout()), this, SLOT(displaySlot()));
    timer_->start(1000);
    displaySlot();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(display_);

    displayGroupBox_ = new QGroupBox();
    displayGroupBox_->setLayout(layout);
}

