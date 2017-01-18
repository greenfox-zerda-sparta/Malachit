#include "hello_qt.h"

Hello_Qt::Hello_Qt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(exit()));
}

Hello_Qt::~Hello_Qt()
{

}
void Hello_Qt::exit()
{
	QApplication::exit();
}