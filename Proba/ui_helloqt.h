/********************************************************************************
** Form generated from reading UI file 'helloqt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOQT_H
#define UI_HELLOQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloQTClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HelloQTClass)
    {
        if (HelloQTClass->objectName().isEmpty())
            HelloQTClass->setObjectName(QStringLiteral("HelloQTClass"));
        HelloQTClass->resize(600, 400);
        centralWidget = new QWidget(HelloQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 70, 75, 23));
        HelloQTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HelloQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        HelloQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HelloQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HelloQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HelloQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HelloQTClass->setStatusBar(statusBar);

        retranslateUi(HelloQTClass);

        QMetaObject::connectSlotsByName(HelloQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *HelloQTClass)
    {
        HelloQTClass->setWindowTitle(QApplication::translate("HelloQTClass", "HelloQT", Q_NULLPTR));
        pushButton->setText(QApplication::translate("HelloQTClass", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HelloQTClass: public Ui_HelloQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOQT_H
