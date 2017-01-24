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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "compass.h"
#include "matrix.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionMatrix;
    QAction *actionCompass;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *matrixPage;
    QGridLayout *gridLayout_2;
    Matrix *matrixWidget;
    QPushButton *compassButton;
    QPushButton *accelerometerButton;
    QPushButton *exitButton;
    QWidget *compassPage;
    QGridLayout *gridLayout_3;
    Compass *compassWidget;
    QSlider *horizontalSlider;
    QPushButton *exitButton_2;
    QPushButton *accelerometerButton_2;
    QPushButton *matrixButton;
    QMenuBar *menuBar;
    QMenu *menuDevices;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(382, 497);
        actionMatrix = new QAction(MainWindowClass);
        actionMatrix->setObjectName(QStringLiteral("actionMatrix"));
        actionCompass = new QAction(MainWindowClass);
        actionCompass->setObjectName(QStringLiteral("actionCompass"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        matrixPage = new QWidget();
        matrixPage->setObjectName(QStringLiteral("matrixPage"));
        gridLayout_2 = new QGridLayout(matrixPage);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        matrixWidget = new Matrix(matrixPage);
        matrixWidget->setObjectName(QStringLiteral("matrixWidget"));
        compassButton = new QPushButton(matrixWidget);
        compassButton->setObjectName(QStringLiteral("compassButton"));
        compassButton->setGeometry(QRect(220, 350, 91, 23));
        accelerometerButton = new QPushButton(matrixWidget);
        accelerometerButton->setObjectName(QStringLiteral("accelerometerButton"));
        accelerometerButton->setGeometry(QRect(20, 350, 91, 23));
        exitButton = new QPushButton(matrixWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(130, 350, 75, 23));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(matrixWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(matrixPage);
        compassPage = new QWidget();
        compassPage->setObjectName(QStringLiteral("compassPage"));
        gridLayout_3 = new QGridLayout(compassPage);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        compassWidget = new Compass(compassPage);
        compassWidget->setObjectName(QStringLiteral("compassWidget"));
        horizontalSlider = new QSlider(compassWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 40, 160, 22));
        horizontalSlider->setMaximum(360);
        horizontalSlider->setOrientation(Qt::Horizontal);
        exitButton_2 = new QPushButton(compassWidget);
        exitButton_2->setObjectName(QStringLiteral("exitButton_2"));
        exitButton_2->setGeometry(QRect(130, 350, 75, 23));
        accelerometerButton_2 = new QPushButton(compassWidget);
        accelerometerButton_2->setObjectName(QStringLiteral("accelerometerButton_2"));
        accelerometerButton_2->setGeometry(QRect(220, 350, 91, 23));
        matrixButton = new QPushButton(compassWidget);
        matrixButton->setObjectName(QStringLiteral("matrixButton"));
        matrixButton->setGeometry(QRect(30, 350, 75, 23));

        gridLayout_3->addWidget(compassWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(compassPage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 382, 21));
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

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        actionMatrix->setText(QApplication::translate("MainWindowClass", "Matrix", Q_NULLPTR));
        actionCompass->setText(QApplication::translate("MainWindowClass", "Compass", Q_NULLPTR));
        compassButton->setText(QApplication::translate("MainWindowClass", "Compass->", Q_NULLPTR));
        accelerometerButton->setText(QApplication::translate("MainWindowClass", "<-Accelerometer", Q_NULLPTR));
        exitButton->setText(QApplication::translate("MainWindowClass", "Exit", Q_NULLPTR));
        exitButton_2->setText(QApplication::translate("MainWindowClass", "Exit", Q_NULLPTR));
        accelerometerButton_2->setText(QApplication::translate("MainWindowClass", "Accelerometer->", Q_NULLPTR));
        matrixButton->setText(QApplication::translate("MainWindowClass", "<- Matrix", Q_NULLPTR));
        menuDevices->setTitle(QApplication::translate("MainWindowClass", "Devices", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
