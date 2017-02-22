#include "mainwindow.h"
MainWindow::MainWindow(QObject* application, QWidget *parent)
  : QMainWindow(parent)
{
  myServiceManager = new ServiceManager(application);
  ui.setupUi(this);
  setupConnections();
  connect(ui.comPortSignInWidget, SIGNAL(comportNameSelected(QString)), myServiceManager, SLOT(setUpSerialPort(QString)));
  connect(ui.comPortSignInWidget, SIGNAL(comportNameSelected(QString)), this, SLOT(showMatrixPage()));
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

void MainWindow::setupConnections()
{
  connect(ui.actionMatrix, &QAction::triggered, this, &MainWindow::showMatrixPage);
  connect(ui.actionCompass, &QAction::triggered, this, &MainWindow::showCompassPage);
  connect(ui.actionAccelerometer, &QAction::triggered, this, &MainWindow::showAccelerometerPage);

  connect(ui.matrixButton, SIGNAL(clicked()), this, SLOT(showMatrixPage()));
  connect(ui.compassButton, SIGNAL(clicked()), this, SLOT(showCompassPage()));
  connect(ui.accelerometerButton, SIGNAL(clicked()), this, SLOT(showAccelerometerPage()));
}

void MainWindow::exit()
{
  QApplication::exit();
}
