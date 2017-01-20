#include "microbitmatrix.h"

MicrobitMatrix::MicrobitMatrix(QWidget *parent)
    : QMainWindow(parent)
{
  ui.setupUi(this);
  fillQVector();  
  connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(exit()));
}

MicrobitMatrix::~MicrobitMatrix()
{

}

void MicrobitMatrix::fillQVector() {
  vector.resize(5);
  for (unsigned int i = 0; i < vector.size(); ++i) {
    for (unsigned int j = 0; j < vector.size(); ++j) {
      QPushButton* button = new QPushButton(this);
      button->setObjectName(QStringLiteral("button"));
      button->setGeometry(QRect(20 + i * 60, 20 + j * 60, 50, 50));
      button->setCheckable(true);
      button->setChecked(true);
      button->setStyleSheet("background-color: red");
      vector[i].push_back(button);
    }
  }
}

void MicrobitMatrix::exit() {
  QApplication::exit();
}