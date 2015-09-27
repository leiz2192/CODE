#ifndef TOMATOTIMER_H
#define TOMATOTIMER_H

#include <QtWidgets/QMainWindow>
#include "ui_tomatotimer.h"

#include <string>

#include <QLCDNumber>
#include <QGroupBox>
#include <QDialog>
#include <QPushButton>

#include <QMenu>
#include <QCursor>

enum LCDSHOWTYPE {TIME, WORK, REST};

const int DEFAULT_WORKTIMERCOUNT = 25 * 60;
const int DEFAULT_RESTTIMERCOUNT = 5 * 60;

const std::string MainDialogName = "Tomato Timer";
const std::string WorkTimerButtonName = "Start &Work";
const std::string RestTimerButtonName = "Start &Rest";

const std::string TimerSetActionName = "Set Timer";
const std::string TimerSetDialogName = "Set Timer";

const std::string WorkSetTypeNameForTimerSet = "Work Timer";
const std::string RestSetTypeNameForTimerSet = "Rest Timer";

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

    void timerOverSlot(LCDSHOWTYPE lcdShowType);

private:
    //��ʱ��
    QTimer * m_timer;
    //��ʾ
    QGroupBox  *m_displayGroupBox;
    QLCDNumber *m_displayLCD;
    //��ʱ��ʾ
    QGroupBox   *m_timerButtonGroupBox;
    QPushButton *m_workTimerButton;
    QPushButton *m_restTimerButton;

    LCDSHOWTYPE m_lcdShowType;

    //��ʱ
    int workTimerCount;
    int restTimerCount;

    int RESET_WORKTIMERCOUNT;
    int RESET_RESTTIMERCOUNT;
    
    //�Ҽ���ʱ����
    QAction *m_timerSetAction;

    //��ʱ���ô���
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

