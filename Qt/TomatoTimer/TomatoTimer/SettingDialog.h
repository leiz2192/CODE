#ifndef __SETTINGDIALOG_H__
#define __SETTINGDIALOG_H__

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "CommonDef.h"

class SettingDialog : public QDialog
{
    Q_OBJECT
public:
    SettingDialog()
    {
        initialization();
    }

    ~SettingDialog();

private:
    void initialization()
    {
        m_setType = new QComboBox;
        m_setType->addItem(tr(WorkSetTypeNameForTimerSet.c_str()));
        m_setType->addItem(tr(RestSetTypeNameForTimerSet.c_str()));
        m_setType->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        m_lineEdit = new QLineEdit();
        QIntValidator *intValidator = new QIntValidator();
        intValidator->setBottom(0);
        m_lineEdit->setValidator(intValidator);
        //connect(m_lineEditForTimerSet, SIGNAL(editingFinished()), this, SLOT(timerSetLineEditSlot()));

        QPushButton *button = new QPushButton(tr("OK"));
        button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        connect(button, SIGNAL(clicked()), this, SLOT(timerSetLineEditSlot()));

        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(m_setType);
        layout->addWidget(m_lineEdit);
        layout->addWidget(button);

        setLayout(layout);
        setWindowTitle(tr(SettingDialogName.c_str()));

        connect(this, SIGNAL(finished(int)), this, SLOT(settingDialogSlot()));
    }

signals:
    void infoSend(const QString &);

private slots:
    void settingDialogSlot()
    {

    }

    void timerSetLineEditSlot()
    {
        const QString txt = m_lineEdit->text();
        emit infoSend(txt);
    }

private:
    QComboBox *m_setType;
    QLineEdit *m_lineEdit;
};

#endif  //__SETTINGDIALOG_H__



