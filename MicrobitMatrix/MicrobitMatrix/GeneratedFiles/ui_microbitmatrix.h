/********************************************************************************
** Form generated from reading UI file 'microbitmatrix.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MICROBITMATRIX_H
#define UI_MICROBITMATRIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "compass.h"

QT_BEGIN_NAMESPACE

class Ui_MicrobitMatrixClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    compass *widget;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MicrobitMatrixClass)
    {
        if (MicrobitMatrixClass->objectName().isEmpty())
            MicrobitMatrixClass->setObjectName(QStringLiteral("MicrobitMatrixClass"));
        MicrobitMatrixClass->resize(600, 393);
        centralWidget = new QWidget(MicrobitMatrixClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 310, 81, 31));
        widget = new compass(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(339, 9, 251, 301));
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 250, 181, 22));
        horizontalSlider->setMaximum(360);
        horizontalSlider->setOrientation(Qt::Horizontal);
        MicrobitMatrixClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MicrobitMatrixClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        MicrobitMatrixClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MicrobitMatrixClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MicrobitMatrixClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MicrobitMatrixClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MicrobitMatrixClass->setStatusBar(statusBar);

        retranslateUi(MicrobitMatrixClass);

        QMetaObject::connectSlotsByName(MicrobitMatrixClass);
    } // setupUi

    void retranslateUi(QMainWindow *MicrobitMatrixClass)
    {
        MicrobitMatrixClass->setWindowTitle(QApplication::translate("MicrobitMatrixClass", "MicrobitMatrix", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MicrobitMatrixClass", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MicrobitMatrixClass: public Ui_MicrobitMatrixClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICROBITMATRIX_H
