#include "compass.h"

Compass::Compass(QWidget *parent)
  : QWidget(parent)
{
  heading = 0;
  offset = this->width();
  setAzimutHandSize();
}

Compass::~Compass()
{

}

void Compass::setHeading(int angle)
{
  heading = angle;
  update();
}

void Compass::setOffset()
{
  offset = this->width();
}

void Compass::setAzimutHandSize()
{
  setOffset();
  azimutHand[0] = QPoint(6, 7);
  azimutHand[1] = QPoint(-6, 7);
  azimutHand[2] = QPoint(0, -offset / 3);
}

void Compass::paintAzimutHand()
{
  setAzimutHandSize();

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(offset / 2, offset / 2);

  painter.setPen(Qt::NoPen);
  painter.setBrush(Qt::red);
  painter.save();
  painter.rotate(heading);
  painter.drawConvexPolygon(azimutHand, 3);
  painter.restore();

  painter.setPen(Qt::NoPen);
  painter.setBrush(Qt::blue);

  painter.save();
  painter.rotate(heading + 180);
  painter.drawConvexPolygon(azimutHand, 3);
  painter.end();
}

void Compass::paintDegreeChart()
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(offset / 2, offset / 2);
  painter.setPen(Qt::black);

  for (int j = 0; j < 60; ++j) {
    painter.drawLine(offset / 3, 0, offset / 3 - 5, 0);
    painter.rotate(6.0);
  }
  painter.end();
}

void Compass::paintEvent(QPaintEvent* e)
{
  paintAzimutHand();
  paintDegreeChart();
}