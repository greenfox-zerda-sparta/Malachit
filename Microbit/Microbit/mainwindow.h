#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "servicemanager.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QObject*, QWidget *parent = 0);

  void setupConnections();

private:
  Ui::MainWindowClass ui;
  ServiceManager* m_ServiceManager;

private slots:
  void exit();
  void showCompassPage();
  void showMatrixPage();
  void showAccelerometerPage();
  void showAccelerometerPlotPage();
};

#endif
