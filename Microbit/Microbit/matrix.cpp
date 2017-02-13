#include "matrix.h"

Matrix::Matrix(QWidget *parent)
  : QWidget(parent)
{
  fillQVector();
}

Matrix::~Matrix()
{

}
QVector<QVector<QPushButton*>> Matrix::getMatrix()
{
  return matrix;
}
void Matrix::fillQVector()
{
  matrix.resize(matrix_x);
  for (unsigned int i = 0; i < matrix_x; ++i) {
    for (unsigned int j = 0; j < matrix_y; ++j) {
      QPushButton* button = createButton(i, j);
      matrix[i].push_back(button);
    }
  }
}
QPushButton* Matrix::createButton(int i, int j)
{
  QPushButton* button = new QPushButton(this);
  button->setObjectName(QStringLiteral("button"));
  button->setGeometry(QRect(20 + i * 60, 20 + j * 60, 50, 50));
  button->setCheckable(true);
  button->setChecked(true);
  button->setStyleSheet("background-color: red");
  return button;
}