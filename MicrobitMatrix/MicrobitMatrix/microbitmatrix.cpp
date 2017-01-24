#include "microbitmatrix.h"

MicrobitMatrix::MicrobitMatrix(QWidget* parent) : QMainWindow(parent)
{
  ui.setupUi(this);
  fillQVector();
  connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(exit()));
}

QVector<QVector<QPushButton*>> MicrobitMatrix::get_matrix()
{
  return matrix;
}

void MicrobitMatrix::fillQVector()
{
  matrix.resize(matrix_x);
  for (unsigned int i = 0; i < matrix_x; ++i) {
    for (unsigned int j = 0; j < matrix_y; ++j) {
      QPushButton* button = create_button(i, j);
      matrix[i].push_back(button);
    }
  }
}

QPushButton* MicrobitMatrix::create_button(int i, int j)
{
  QPushButton* button = new QPushButton(this);
  button->setObjectName(QStringLiteral("button"));
  button->setGeometry(QRect(20 + i * 60, 20 + j * 60, 50, 50));
  button->setCheckable(true);
  button->setChecked(true);
  button->setStyleSheet("background-color: red");
  return button;
}

void MicrobitMatrix::exit()
{
  QApplication::exit();
}