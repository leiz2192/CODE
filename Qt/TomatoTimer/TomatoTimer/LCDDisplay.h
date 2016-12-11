#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <QDialog>

#include <QLCDNumber>
#include <QTimer>
#include <QGroupBox>

#include <memory>

class LCDDisplay : public QDialog
{
    Q_OBJECT

public :
    LCDDisplay(QWidget *parent = 0);
    virtual ~LCDDisplay() {}
    virtual void initialize();

protected slots :
    virtual void displaySlot() = 0;

protected :
    std::shared_ptr<QLCDNumber> display_;
    std::shared_ptr<QTimer> timer_;
    std::shared_ptr<QGroupBox> displayGroupBox_;
};

#endif  //__DISPLAY_H__

