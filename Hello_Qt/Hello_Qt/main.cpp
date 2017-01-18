#include "hello_qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Hello_Qt w;
	w.show();
	return a.exec();
}
