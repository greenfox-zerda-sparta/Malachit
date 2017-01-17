#include "helloqt.h"

HelloQT::HelloQT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(exit()));
}

HelloQT::~HelloQT()
{

}

void HelloQT::exit() {
  QApplication::exit();
}