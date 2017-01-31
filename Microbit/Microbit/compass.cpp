#include "compass.h"

Compass::Compass(QWidget *parent)
  : QWidget(parent)
{
  heading = 0;
  setOffsetAndRadius();
  setAzimuthHandSize();
}

Compass::~Compass()
{

}

void Compass::paintEvent(QPaintEvent* e)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(offset, offset);

  paintAzimuthHand(painter);
  paintDegreeChart(painter);

  painter.end();
}

void Compass::paintAzimuthHand(QPainter& painter)
{
  setAzimuthHandSize();

  paintHalfOfAzimuthHand(painter, Qt::red, 0);
  paintHalfOfAzimuthHand(painter, Qt::blue, 180);
}

void Compass::paintHalfOfAzimuthHand(QPainter& painter, const QColor& color, int degree)
{
  painter.setPen(Qt::NoPen);
  painter.setBrush(color);
  painter.save();
  painter.rotate(heading + degree);
  painter.drawConvexPolygon(azimuthHand, 3);
  painter.restore();
}

void Compass::paintDegreeChart(QPainter& painter)
{
  painter.setPen(Qt::black);

  for (int j = 0; j < 60; ++j) {
    painter.drawLine(0, radius, 0, radius - 5);
    painter.rotate(6.0);
  }

  painter.restore();
}

void Compass::setHeading(int angle)
{
  heading = angle;
  update();
}

void Compass::setOffsetAndRadius()
{
  offset = this->width() / 2;
  radius = offset / 3 * 2;
}

void Compass::setAzimuthHandSize()
{
  setOffsetAndRadius();
  azimuthHandWidth = 12;
  azimuthHand[0] = QPoint(azimuthHandWidth / 2, 0);
  azimuthHand[1] = QPoint(-azimuthHandWidth / 2, 0);
  azimuthHand[2] = QPoint(0, -radius);
}


