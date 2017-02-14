#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "config.h"

class Matrix : public QWidget
{
  Q_OBJECT

public:
  Matrix(QWidget *parent);
  void fillMatrix();
  QPushButton* createButton();
  QVector<QVector<QPushButton*>> getMatrix();

private:
  QVector<QVector<QPushButton*>> m_Matrix;
  QGridLayout* m_MatrixGridLayout;
};

#endif
