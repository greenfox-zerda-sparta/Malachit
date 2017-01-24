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
void MainWindow::setupConnections() 
{
	connect(ui.actionCompass, &QAction::triggered, this, &MainWindow::showCompassPage);
	connect(ui.actionMatrix, &QAction::triggered, this, &MainWindow::showMatrixPage);
	connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), ui.compassWidget, SLOT(setHeading(int)));

	connect(ui.compassButton, SIGNAL(clicked()), this, SLOT(showCompassPage()));
	connect(ui.matrixButton, SIGNAL(clicked()), this, SLOT(showMatrixPage()));
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.exitButton_2, SIGNAL(clicked()), this, SLOT(exit()));
}
void MainWindow::exit() 
{
	QApplication::exit();
}
