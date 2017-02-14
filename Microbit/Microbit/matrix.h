#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QPushButton>
//#include <QtGui>
class Matrix : public QWidget
{
  Q_OBJECT

public:
  Matrix(QWidget *parent);
  ~Matrix();

  void fillQVector();
  QPushButton* createButton(int i, int j);
  QVector<QVector<QPushButton*>> getMatrix();

private:
  QVector<QVector<QPushButton*>> matrix;
  unsigned int matrix_x = 5;
  unsigned int matrix_y = 5;
};

#endif // MATRIX_H
