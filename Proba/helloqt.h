#ifndef HELLOQT_H
#define HELLOQT_H

#include <QtWidgets/QMainWindow>
#include "ui_helloqt.h"

class HelloQT : public QMainWindow
{
    Q_OBJECT

public:
    HelloQT(QWidget *parent = 0);
    ~HelloQT();

private:
    Ui::HelloQTClass ui;
    private slots:
      void exit();
};

#endif // HELLOQT_H
