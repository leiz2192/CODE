#include "LCDDisplay.h"
#include "CommonDef.h"

#include <QHBoxLayout>
#include <QTime>
#include <QString>

LCDDisplay::LCDDisplay(QWidget *parent /* = 0 */)
{
}

void LCDDisplay::initialize()
{
    display_ = std::shared_ptr<QLCDNumber>(new QLCDNumber(this));
    display_->setSegmentStyle(QLCDNumber::Flat);
    display_->setDigitCount(8);

    timer_ = std::shared_ptr<QTimer>(new QTimer(this));
    connect(timer_.get(), SIGNAL(timeout()), this, SLOT(displaySlot()));
    timer_->start(1000);
    displaySlot();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(display_.get());

    displayGroupBox_ = std::shared_ptr<QGroupBox>(new QGroupBox());
    displayGroupBox_->setLayout(layout);

    QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->addWidget(displayGroupBox_.get());
    setLayout(mainLayout);

    setWindowTitle(tr(MainDialogName.c_str()));
    resize(316, 75);
}

