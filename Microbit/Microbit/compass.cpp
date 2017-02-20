#include "compass.h"

Compass::Compass(QWidget *parent)
  : QWidget(parent),
  m_ReceiverService(new ReceiverService(parent))
{
  m_Heading = 0;
  setAzimuthHandSize();
  setScaleMarkPoints();

  connect(m_ReceiverService.data(), SIGNAL(metricsReceived(Metrics)), this, SLOT(setHeading(Metrics)));
}

void Compass::paintEvent(QPaintEvent* e)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  setOffsetAndRadius();
  painter.translate(m_Offset, m_Offset);
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
  painter.rotate(m_Heading + degree);
  painter.drawConvexPolygon(azimuthHand, 3);
  painter.restore();
}

void Compass::paintDegreeChart(QPainter& painter)
{
  painter.setPen(Qt::black);
  setScaleMarkPoints();
  for (int j = 0; j < Config::numOfScales; ++j) {
    painter.drawLine(scaleMarkPoints[0], scaleMarkPoints[1]);
    painter.rotate(Config::fullRotation / Config::numOfScales);
  }
}

void Compass::setHeading(Metrics microbitData)
{
  m_Heading = microbitData.compassHeading;
  update();
}

void Compass::setOffsetAndRadius()
{
  m_Offset = this->width() / 2;
  m_Radius = m_Offset * Config::diameterToWidgetProportion;
}

void Compass::setAzimuthHandSize()
{
  azimuthHand[0] = QPoint(Config::azimuthHandWidth / 2, 0);
  azimuthHand[1] = QPoint(-Config::azimuthHandWidth / 2, 0);
  azimuthHand[2] = QPoint(0, -m_Radius);
}

void Compass::setScaleMarkPoints()
{
  scaleMarkPoints[0] = QPoint(0, m_Radius);
  scaleMarkPoints[1] = QPoint(0, m_Radius - Config::scaleLength);
}


