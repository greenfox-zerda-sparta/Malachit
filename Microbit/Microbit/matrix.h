#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "config.h"
#include "senderservice.h"
#include "ledlight.h"

class Matrix : public QWidget
{
  Q_OBJECT

public:
  Matrix(QWidget *parent);
  void fillMatrix();
  LedLight* createButton(int, int);
  QVector<QVector<QPushButton*>> getMatrix();

private:
  QVector<QVector<QPushButton*>> m_Matrix;
  QGridLayout* m_MatrixGridLayout;  
  QScopedPointer<SenderService> m_SenderService;
  double m_Margin;
};

#endif
