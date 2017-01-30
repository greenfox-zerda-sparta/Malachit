/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "accelerometer.h"
#include "compass.h"
#include "matrix.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionMatrix;
    QAction *actionCompass;
    QAction *actionAccelerometer;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *matrixPage;
    QGridLayout *gridLayout;
    Matrix *matrixWidget;
    QWidget *compassPage;
    QVBoxLayout *verticalLayout;
    Compass *compassWidget;
    QSlider *compassSlider;
    QWidget *accelerometerPage;
    QGridLayout *gridLayout_4;
    Accelerometer *accelerometerWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *matrixButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *compassButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *accelerometerButton;
    QMenuBar *menuBar;
    QMenu *menuDevices;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(401, 511);
        actionMatrix = new QAction(MainWindowClass);
        actionMatrix->setObjectName(QStringLiteral("actionMatrix"));
        actionCompass = new QAction(MainWindowClass);
        actionCompass->setObjectName(QStringLiteral("actionCompass"));
        actionAccelerometer = new QAction(MainWindowClass);
        actionAccelerometer->setObjectName(QStringLiteral("actionAccelerometer"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        matrixPage = new QWidget();
        matrixPage->setObjectName(QStringLiteral("matrixPage"));
        gridLayout = new QGridLayout(matrixPage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        matrixWidget = new Matrix(matrixPage);
        matrixWidget->setObjectName(QStringLiteral("matrixWidget"));

        gridLayout->addWidget(matrixWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(matrixPage);
        compassPage = new QWidget();
        compassPage->setObjectName(QStringLiteral("compassPage"));
        verticalLayout = new QVBoxLayout(compassPage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        compassWidget = new Compass(compassPage);
        compassWidget->setObjectName(QStringLiteral("compassWidget"));
        compassSlider = new QSlider(compassWidget);
        compassSlider->setObjectName(QStringLiteral("compassSlider"));
        compassSlider->setGeometry(QRect(100, 40, 160, 22));
        compassSlider->setMaximum(360);
        compassSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(compassWidget);

        stackedWidget->addWidget(compassPage);
        accelerometerPage = new QWidget();
        accelerometerPage->setObjectName(QStringLiteral("accelerometerPage"));
        gridLayout_4 = new QGridLayout(accelerometerPage);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        accelerometerWidget = new Accelerometer(accelerometerPage);
        accelerometerWidget->setObjectName(QStringLiteral("accelerometerWidget"));

        gridLayout_4->addWidget(accelerometerWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(accelerometerPage);

        verticalLayout_2->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        matrixButton = new QPushButton(centralWidget);
        matrixButton->setObjectName(QStringLiteral("matrixButton"));

        horizontalLayout->addWidget(matrixButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        compassButton = new QPushButton(centralWidget);
        compassButton->setObjectName(QStringLiteral("compassButton"));

        horizontalLayout->addWidget(compassButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        accelerometerButton = new QPushButton(centralWidget);
        accelerometerButton->setObjectName(QStringLiteral("accelerometerButton"));

        horizontalLayout->addWidget(accelerometerButton);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 401, 21));
        menuDevices = new QMenu(menuBar);
        menuDevices->setObjectName(QStringLiteral("menuDevices"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuDevices->menuAction());
        menuDevices->addAction(actionMatrix);
        menuDevices->addAction(actionCompass);
        menuDevices->addAction(actionAccelerometer);

        retranslateUi(MainWindowClass);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Micro:bit Controller", Q_NULLPTR));
        actionMatrix->setText(QApplication::translate("MainWindowClass", "Matrix", Q_NULLPTR));
        actionCompass->setText(QApplication::translate("MainWindowClass", "Compass", Q_NULLPTR));
        actionAccelerometer->setText(QApplication::translate("MainWindowClass", "Accelerometer", Q_NULLPTR));
        matrixButton->setText(QApplication::translate("MainWindowClass", "Matrix", Q_NULLPTR));
        compassButton->setText(QApplication::translate("MainWindowClass", "Compass", Q_NULLPTR));
        accelerometerButton->setText(QApplication::translate("MainWindowClass", "Accelerometer", Q_NULLPTR));
        menuDevices->setTitle(QApplication::translate("MainWindowClass", "Devices", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
