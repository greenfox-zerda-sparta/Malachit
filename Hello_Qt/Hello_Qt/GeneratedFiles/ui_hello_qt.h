/********************************************************************************
** Form generated from reading UI file 'hello_qt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_QT_H
#define UI_HELLO_QT_H

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

class Ui_Hello_QtClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Hello_QtClass)
    {
        if (Hello_QtClass->objectName().isEmpty())
            Hello_QtClass->setObjectName(QStringLiteral("Hello_QtClass"));
        Hello_QtClass->resize(361, 352);
        centralWidget = new QWidget(Hello_QtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 110, 121, 51));
        QFont font;
        font.setPointSize(20);
        pushButton->setFont(font);
        Hello_QtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Hello_QtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 361, 21));
        Hello_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Hello_QtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Hello_QtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Hello_QtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Hello_QtClass->setStatusBar(statusBar);

        retranslateUi(Hello_QtClass);

        QMetaObject::connectSlotsByName(Hello_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *Hello_QtClass)
    {
        Hello_QtClass->setWindowTitle(QApplication::translate("Hello_QtClass", "Hello_Qt", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Hello_QtClass", "Hello Qt!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Hello_QtClass: public Ui_Hello_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_QT_H
