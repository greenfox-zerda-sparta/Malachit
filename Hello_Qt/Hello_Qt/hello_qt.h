#ifndef HELLO_QT_H
#define HELLO_QT_H

#include <QtWidgets/QMainWindow>
#include "ui_hello_qt.h"

class Hello_Qt : public QMainWindow
{
	Q_OBJECT

public:
	Hello_Qt(QWidget *parent = 0);
	~Hello_Qt();

private:
	Ui::Hello_QtClass ui;
};

#endif // HELLO_QT_H
