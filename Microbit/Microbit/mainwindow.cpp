#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
  m_Receiver = new DataReceiver(this);
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

void MainWindow::setupConnections()
{
	connect(ui.actionMatrix, &QAction::triggered, this, &MainWindow::showMatrixPage);
  connect(ui.actionCompass, &QAction::triggered, this, &MainWindow::showCompassPage);
	connect(ui.actionAccelerometer, &QAction::triggered, this, &MainWindow::showAccelerometerPage);

	connect(ui.matrixButton, SIGNAL(clicked()), this, SLOT(showMatrixPage()));
	connect(ui.compassButton, SIGNAL(clicked()), this, SLOT(showCompassPage()));
	connect(ui.accelerometerButton, SIGNAL(clicked()), this, SLOT(showAccelerometerPage()));

<<<<<<< HEAD
  connect(m_Receiver, SIGNAL(dataReceived(int)), ui.compassWidget, SLOT(setHeading(int)));
  connect(ui.compassSlider, SIGNAL(valueChanged(int)), ui.compassWidget, SLOT(setHeading(int)));
=======
  //connect(ui.compassSlider, SIGNAL(valueChanged(int)), ui.compassWidget, SLOT(setHeading(int)));
>>>>>>> 74386ddc2dad4826c1d191b6cfb338ff84ed7348

  connect(ui.controllerToR1, SIGNAL(valueChanged(double)), ui.accelerometerWidget, SLOT(setHeightX(double)));
  connect(ui.controllerToR2, SIGNAL(valueChanged(double)), ui.accelerometerWidget, SLOT(setHeightY(double)));
  connect(ui.controllerToR3, SIGNAL(valueChanged(double)), ui.accelerometerWidget, SLOT(setHeightZ(double)));

  connect(m_Receiver, SIGNAL(valueChanged(int)), ui.compassWidget, SLOT(setHeading(int)));
}

void MainWindow::exit() 
{
	QApplication::exit();
}
