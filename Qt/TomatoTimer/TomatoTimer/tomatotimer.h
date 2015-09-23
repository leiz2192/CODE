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

protected:
    void contextMenuEvent(QContextMenuEvent *);

private:
    void initDisplayGroupBox();
    void initTimerButtonGroupBox();
    void initMenu();
    void initTimerSetDialog();

private:
    //定时器
    QTimer * m_timer;
    //显示
    QGroupBox  *m_displayGroupBox;
    QLCDNumber *m_displayLCD;
    //计时显示
    QGroupBox   *m_timerButtonGroupBox;
    QPushButton *m_workTimerButton;
    QPushButton *m_restTimerButton;

    LCDSHOWTYPE m_lcdShowType;

    //计时
    int workTimerCount;
    int restTimerCount;

    int RESET_WORKTIMERCOUNT;
    int RESET_RESTTIMERCOUNT;
    
    //右键计时设置
    QAction *m_timerSetAction;

    //计时设置窗口
    QDialog   *m_timerSetDialog;
    QComboBox *m_setTypeForTimerSet;
    QLineEdit *m_lineEditForTimerSet;

private slots:
    void lcdDisplaySlot();

    void workTimerButtonSlot(bool checked);
    void restTimerButtonSlot(bool checked);

    void timerSetActionSlot();
    void timerSetLineEditSlot();

    void timerSetDialogSlot();
};

#endif // TOMATOTIMER_H

