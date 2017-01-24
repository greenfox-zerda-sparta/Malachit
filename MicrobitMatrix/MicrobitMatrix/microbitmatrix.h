#ifndef MICROBITMATRIX_H
#define MICROBITMATRIX_H

#include <QtWidgets/QMainWindow>
#include "ui_microbitmatrix.h"

class MicrobitMatrix : public QMainWindow
{
  Q_OBJECT

public:
  MicrobitMatrix(QWidget *parent = 0);
  void fillQVector();
  QPushButton* create_button(int, int);
  QVector<QVector<QPushButton*>> get_matrix();

private:
  Ui::MicrobitMatrixClass ui;
  QVector<QVector<QPushButton*>> matrix;
  unsigned int matrix_x = 5;
  unsigned int matrix_y = 5;

private slots:
  void exit();
};

#endif