/********************************************************************************
** Form generated from reading UI file 'tomatotimer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOMATOTIMER_H
#define UI_TOMATOTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TomatoTimerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TomatoTimerClass)
    {
        if (TomatoTimerClass->objectName().isEmpty())
            TomatoTimerClass->setObjectName(QStringLiteral("TomatoTimerClass"));
        TomatoTimerClass->resize(600, 400);
        menuBar = new QMenuBar(TomatoTimerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TomatoTimerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TomatoTimerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TomatoTimerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TomatoTimerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TomatoTimerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TomatoTimerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TomatoTimerClass->setStatusBar(statusBar);

        retranslateUi(TomatoTimerClass);

        QMetaObject::connectSlotsByName(TomatoTimerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TomatoTimerClass)
    {
        TomatoTimerClass->setWindowTitle(QApplication::translate("TomatoTimerClass", "TomatoTimer", 0));
    } // retranslateUi

};

namespace Ui {
    class TomatoTimerClass: public Ui_TomatoTimerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOMATOTIMER_H
