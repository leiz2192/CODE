#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <QDialog>

#include <QLCDNumber>
#include <QTimer>

class LCDDisplay : public QDialog
{
public:
    LCDDisplay(QWidget *parent = 0);
    virtual ~LCDDisplay() {}
    virtual void initialize();
    virtual void displaySlot() = 0;

private:
    std::auto_ptr<QLCDNumber> display_;
    std::auto_ptr<QTimer> timer_;
    std::auto_ptr<QGroupBox> displayGroupBox_;
}

#endif  //__DISPLAY_H__

