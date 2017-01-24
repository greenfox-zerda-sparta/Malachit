#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), ui.CompassWidget, SLOT(setHeading(int)));
}

MainWindow::~MainWindow()
{

}
void MainWindow::exit() {
	QApplication::exit();
}
