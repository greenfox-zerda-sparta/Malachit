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
    ~MicrobitMatrix();

private:
    Ui::MicrobitMatrixClass ui;
    QVector<QVector<QPushButton*>> vector;
private slots:
  void exit();
};

#endif
