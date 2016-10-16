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

#include "CommonDef.h"
#include "SettingDialog.h"

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
    void setMainWindowFlags(Qt::WindowFlags type);

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

    //���ô���
    QDialog   *m_settingDialog;
    QComboBox *m_setTypeForTimerSet;
    QLineEdit *m_lineEditForTimerSet;

private slots:
    void lcdDisplaySlot();

    void workTimerButtonSlot(bool checked);
    void restTimerButtonSlot(bool checked);

    void settingActionSlot();
    void timerSetLineEditSlot();

    void settingDialogSlot();
};

class EventRecordDialog : public QDialog
{
    Q_OBJECT
};


#endif // TOMATOTIMER_H

