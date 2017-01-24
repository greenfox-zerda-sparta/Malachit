/********************************************************************************
** Form generated from reading UI file 'logger.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGER_H
#define UI_LOGGER_H

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

class Ui_LoggerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoggerClass)
    {
        if (LoggerClass->objectName().isEmpty())
            LoggerClass->setObjectName(QStringLiteral("LoggerClass"));
        LoggerClass->resize(600, 400);
        menuBar = new QMenuBar(LoggerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        LoggerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoggerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoggerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LoggerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LoggerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LoggerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoggerClass->setStatusBar(statusBar);

        retranslateUi(LoggerClass);

        QMetaObject::connectSlotsByName(LoggerClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoggerClass)
    {
        LoggerClass->setWindowTitle(QApplication::translate("LoggerClass", "Logger", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoggerClass: public Ui_LoggerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGER_H
