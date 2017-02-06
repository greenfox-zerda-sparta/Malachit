#include "compass.h"

Compass::Compass(QWidget *parent)
  : QWidget(parent),
  fullRotation(360)
{
  heading = 0;
  numOfScales = 60;
  scaleLength = 5;
  setAzimuthHandSize();
  setScaleMarkPoints();
}

Compass::~Compass()
{

}

void Compass::paintEvent(QPaintEvent* e)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  setOffsetAndRadius();
  painter.translate(offset, offset);
  paintAzimuthHand(painter);
  paintDegreeChart(painter);
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
  setScaleMarkPoints();
  for (int j = 0; j < numOfScales; ++j) {
    painter.drawLine(scaleMarkPoints[0], scaleMarkPoints[1]);
    painter.rotate(fullRotation / numOfScales);
  }
}

void Compass::setHeading(int angle)
{
  heading = angle;
  update();
}

void Compass::setOffsetAndRadius()
{
  offset = this->width() / 2;
  radius = offset * 0.66;
}

void Compass::setAzimuthHandSize()
{
  azimuthHandWidth = 12;
  azimuthHand[0] = QPoint(azimuthHandWidth / 2, 0);
  azimuthHand[1] = QPoint(-azimuthHandWidth / 2, 0);
  azimuthHand[2] = QPoint(0, -radius);
}

void Compass::setScaleMarkPoints()
{
  scaleMarkPoints[0] = QPoint(0, radius);
  scaleMarkPoints[1] = QPoint(0, radius - scaleLength);
}


