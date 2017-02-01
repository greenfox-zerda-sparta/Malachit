#include "accelerometer.h"

Accelerometer::Accelerometer(QWidget *parent)
  : QWidget(parent)
{
  m_HeightX = 0.0;
  m_HeightY = 0.0;
  m_HeightZ = 0.0;
  m_MaxHeight = 300.0;
  m_WidthAll = 50.0;
  m_proportion = 0.1;
  m_numberOfBars = 3;
}

Accelerometer::~Accelerometer()
{
  
}

void Accelerometer::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  setCoordinates();
  drawBars(painter);
  createAxisX(painter);
  createAxisY(painter);
}

void Accelerometer::setCoordinates()
{
  m_axisOffsetTop = (double)(this->height() * m_proportion);
  m_axisOffsetRight = (double)(this->width() - this->width() * m_proportion);
  m_axisOffsetBottom = (double)(this->height() - this->height() * m_proportion);
  m_axisOffsetLeft = (double)(this->width() * m_proportion);
}

void Accelerometer::createAxisX(QPainter& painter)
{
  QLineF axisX(m_axisOffsetLeft, m_axisOffsetBottom, m_axisOffsetRight, m_axisOffsetBottom);
  painter.setPen(Qt::black);
  painter.drawLine(axisX);
  
  setAxisTitle(painter, "Direction", (Qt::AlignHCenter | Qt::AlignBottom));
  setAxisXlabel(painter);
}

void Accelerometer::createAxisY(QPainter& painter)
{
  QLineF axisY(m_axisOffsetLeft, m_axisOffsetTop, m_axisOffsetLeft, m_axisOffsetBottom);
  painter.setPen(Qt::black);
  painter.drawLine(axisY);

  setAxisTitle(painter, "g", (Qt::AlignVCenter | Qt::AlignLeft));
  setAxisYlabel(painter);
}

void Accelerometer::setAxisTitle(QPainter& painter, QString name, int flag)
{
  QRectF rect(0, 0, this->width(), this->height());
  painter.setFont(QFont("Arial", 10, 100));
  painter.drawText(rect, flag, name);
}

void Accelerometer::setAxisXlabel(QPainter& painter)
{
  QVector<QString> labels;
  labels << "X" << "Y" << "Z";
  painter.setFont(QFont("Arial", 10));

  for (int i = 0; i < labels.size(); ++i)
  {
    QPointF point(calculateAxisXLabelPositionX(i), m_axisOffsetBottom + 15);
    painter.drawText(point, labels[i]);
  }
}

void Accelerometer::setAxisYlabel(QPainter& painter)
{
  QVector<QString> labels;
  labels << "300" << "200" << "100";
  painter.setFont(QFont("Arial", 10));

  for (int i = 0; i < labels.size(); ++i)
  {
    QPointF point(m_axisOffsetLeft - 22, calculateAxisYLabelPositionY(i));
    painter.drawText(point, labels[i]);
  }
}

void Accelerometer::drawBars(QPainter& painter)
{
  QVector<double> rectXcoordinates;
  for (int i = 1; i <= m_numberOfBars; ++i)
  {
    rectXcoordinates.push_back(calculateBarPositionOnAxisX(i));
  }

  double responsiveHeightX = calculateBarHeight(m_HeightX);
  double responsiveHeightY = calculateBarHeight(m_HeightY);
  double responsiveHeightZ = calculateBarHeight(m_HeightZ);


  QRectF rect1(rectXcoordinates[0], m_axisOffsetBottom - responsiveHeightX, m_WidthAll, responsiveHeightX);
  QRectF rect2(rectXcoordinates[1], m_axisOffsetBottom - responsiveHeightY, m_WidthAll, responsiveHeightY);
  QRectF rect3(rectXcoordinates[2], m_axisOffsetBottom - responsiveHeightZ, m_WidthAll, responsiveHeightZ);

  painter.setPen(Qt::NoPen);
  painter.setBrush(Qt::red);
  painter.drawRect(rect1);
  painter.setBrush(Qt::darkGreen);
  painter.drawRect(rect2);
  painter.setBrush(Qt::blue);
  painter.drawRect(rect3);
  painter.setBrush(Qt::cyan);
}

double Accelerometer::calculateAxisXLabelPositionX(int index)
{
  return ((m_axisOffsetRight - m_axisOffsetLeft) * 0.25 * (index + 1) + m_axisOffsetLeft);
}

double Accelerometer::calculateAxisYLabelPositionY(int index)
{
  return m_axisOffsetTop + (m_axisOffsetBottom - m_axisOffsetTop) * 1 / 3 * index;
}

double Accelerometer::calculateBarPositionOnAxisX(int index)
{
  return ((m_axisOffsetRight - m_axisOffsetLeft) * 0.25 * index + m_axisOffsetLeft) - m_WidthAll / 2;
}

double Accelerometer::calculateBarHeight(double inputHeight)
{
  return inputHeight / m_MaxHeight * (m_axisOffsetBottom - m_axisOffsetTop);
}

void Accelerometer::setHeightX(double x)
{
  m_HeightX = x;
  update();
}

void Accelerometer::setHeightY(double y)
{
  m_HeightY = y;
  update();
}

void Accelerometer::setHeightZ(double z)
{
  m_HeightZ = z;
  update();
}

void Accelerometer::setWidthAll(double w)
{
  m_WidthAll = w;
}

