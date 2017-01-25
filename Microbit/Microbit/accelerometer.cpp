#include "accelerometer.h"

Accelerometer::Accelerometer(QWidget *parent)
  : QWidget(parent)
{
  _x = 50;
  _y = 70;
  _z = 150;


}

Accelerometer::~Accelerometer()
{

}

void Accelerometer::paintEvent(QPaintEvent *e) {
  QPainter painter(this);
  painter.setPen(Qt::NoPen);
  painter.setBrush(Qt::red);
  painter.save();
  painter.drawRect(20, 300 - _x, 50, _x);
  painter.setBrush(Qt::darkGreen);
  painter.save();
  painter.drawRect(100, 300 - _y, 50, _y);
  painter.setBrush(Qt::blue);
  painter.save();
  painter.drawRect(180, 300 - _z, 50, _z);
}

void Accelerometer::setX(int x) {
  _x = x;
}

void Accelerometer::setY(int y) {
  _y = y;
}

void Accelerometer::setZ(int z) {
  _z = z;
}