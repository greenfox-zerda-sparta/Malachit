#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include "config.h"
#include "ledlight.h"
#include "senderservice.h"

class Matrix : public QWidget
{
  Q_OBJECT

public:
  Matrix(QWidget *parent);
  void fillMatrix();
  LedLight* createButton(int, int);
  QVector<QVector<LedLight*>> getMatrix();
  //void setParameters();
  //void resizeEvent(QResizeEvent* event);

private:
  QVector<QVector<LedLight*>> m_Matrix;
  QGridLayout* m_MatrixGridLayout;
  double m_Margin;
  QVector<QHBoxLayout*> m_HorizontalLayouts;
  QVBoxLayout* m_VerticalLayout;


  SenderService* m_SenderService;

};

#endif
