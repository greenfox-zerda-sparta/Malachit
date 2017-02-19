#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  ui.setupUi(this);
  setupConnections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::showCompassPage()
{
  ui.stackedWidget->setCurrentWidget(ui.compassPage);
}

void MainWindow::showMatrixPage()
{
  ui.stackedWidget->setCurrentWidget(ui.matrixPage);
}

void MainWindow::showAccelerometerPage()
{
  ui.stackedWidget->setCurrentWidget(ui.accelerometerPage);
}
void MainWindow::showAccelerometerPlotPage()
{
  ui.stackedWidget->setCurrentWidget(ui.accelerometerPlotPage);
}

void MainWindow::setupConnections()
{
  connect(ui.actionMatrix, &QAction::triggered, this, &MainWindow::showMatrixPage);
  connect(ui.actionCompass, &QAction::triggered, this, &MainWindow::showCompassPage);
  connect(ui.actionAccelerometer, &QAction::triggered, this, &MainWindow::showAccelerometerPage);
  connect(ui.actionAccelerometerGraph, &QAction::triggered, this, &MainWindow::showAccelerometerPlotPage);

  connect(ui.matrixButton, SIGNAL(clicked()), this, SLOT(showMatrixPage()));
  connect(ui.compassButton, SIGNAL(clicked()), this, SLOT(showCompassPage()));
  connect(ui.accelerometerButton, SIGNAL(clicked()), this, SLOT(showAccelerometerPage()));
  connect(ui.accelerometerPlotButton, SIGNAL(clicked()), this, SLOT(showAccelerometerPlotPage()));
}

void MainWindow::exit()
{
  QApplication::exit();
}
