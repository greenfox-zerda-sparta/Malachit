#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "accelerometer.h"
#include "compass.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void setupConnections();

private:
  Ui::MainWindowClass ui;
  private slots:
  void exit();
  void showCompassPage();
  void showMatrixPage();
  void showAccelerometerPage();
  void showAccelerometerPlotPage();
};

#endif // MAINWINDOW_H
