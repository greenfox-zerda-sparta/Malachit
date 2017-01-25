#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <QWidget>
#include <QtGui>

class Accelerometer : public QWidget
{
  Q_OBJECT

public:
    Accelerometer(QWidget *parent);
    ~Accelerometer();
    
private slots:
void paintEvent(QPaintEvent *e);
void setX(int x);
void setY(int y);
void setZ(int z);

private:
  int _x;
  int _y;
  int _z;
};

#endif // ACCELEROMETER_H
