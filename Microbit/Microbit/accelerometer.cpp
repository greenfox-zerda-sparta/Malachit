#include "accelerometer.h"

Accelerometer::Accelerometer(QWidget *parent)
  : QWidget(parent)
{
  m_HeightX = 0.0;
  m_HeightY = 0.0;
  m_HeightZ = 0.0;
  m_Heights << m_HeightX << m_HeightY << m_HeightZ;
}

void Accelerometer::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  setCoordinates();
  createAxisX(painter);
  createAxisY(painter);
  drawBars(painter);
}

void Accelerometer::setCoordinates()
{
  m_AxisOffsetTop = (double)(this->height() * Config::paddingProportion);
  m_AxisOffsetRight = (double)(this->width() - this->width() * Config::paddingProportion);
  m_AxisOffsetBottom = (double)(this->height() - this->height() * Config::paddingProportion);
  m_AxisOffsetLeft = (double)(this->width() * Config::paddingProportion);
  m_AxisYMiddle = (m_AxisOffsetBottom + m_AxisOffsetTop) / 2;
}

void Accelerometer::createAxisX(QPainter& painter)
{
  QLineF axisX(m_AxisOffsetLeft, m_AxisYMiddle, m_AxisOffsetRight, m_AxisYMiddle);
  painter.setPen(Qt::black);
  painter.drawLine(axisX);

  setAxisTitle(painter, "Direction", (Qt::AlignHCenter | Qt::AlignBottom));
  setAxisXlabel(painter);
}

void Accelerometer::createAxisY(QPainter& painter)
{
  QLineF axisY(m_AxisOffsetLeft, m_AxisOffsetTop, m_AxisOffsetLeft, m_AxisOffsetBottom);
  painter.setPen(Qt::black);
  painter.drawLine(axisY);

  setAxisTitle(painter, "g", (Qt::AlignVCenter | Qt::AlignLeft));
  setAxisYlabel(painter);
}

void Accelerometer::drawBars(QPainter& painter)
{
  QVector<double> rectXcoordinates;
  for (int i = 1; i <= Config::numberOfBars; ++i)
  {
    rectXcoordinates.push_back(calculateBarPositionOnAxisX(i));
  }

  QVector<QColor> barColors;
  barColors << Qt::darkMagenta << Qt::darkCyan << Qt::darkBlue;
  for (int i = 0; i < Config::numberOfBars; ++i)
  {
    createBar(painter, m_Heights[i], rectXcoordinates[i], barColors[i]);
  }
}

void Accelerometer::createBar(QPainter& painter, double height, double rectXCoordinate, QColor color)
{
  double responsiveHeight = calculateBarHeight(height);
  QRectF rect(rectXCoordinate, m_AxisYMiddle, Config::barWidth, responsiveHeight);
  painter.setPen(Qt::NoPen);
  painter.setBrush(color);
  painter.drawRect(rect);
}

void Accelerometer::setAxisTitle(QPainter& painter, QString name, int flag)
{
  QRectF rect(0, 0, this->width(), this->height());
  painter.setFont(Config::axisTitleFont);
  painter.drawText(rect, flag, name);
}

void Accelerometer::setAxisXlabel(QPainter& painter)
{
  QVector<QString> labels;
  labels << "X" << "Y" << "Z";
  painter.setFont(Config::axisLableFont);

  for (int i = 0; i < labels.size(); ++i)
  {
    QPointF point(calculateAxisXLabelPositionX(i), m_AxisOffsetBottom + Config::spaceBetweenAxisXAndLabel);
    painter.drawText(point, labels[i]);
  }
}

void Accelerometer::setAxisYlabel(QPainter& painter)
{
  QVector<QString> labels;
  for (int i = 0; i < Config::numberOfAxisYLabels; ++i)
  {
    labels << QString::number(Config::topAxisYLabel - i * Config::labelStep);
  }
  painter.setFont(Config::axisLableFont);

  for (int i = 0; i < labels.size(); ++i)
  {
    QPointF point(m_AxisOffsetLeft - Config::spaceBetweenAxisYAndLabel, calculateAxisYLabelPositionY(i));
    painter.drawText(point, labels[i]);
  }
}

double Accelerometer::calculateAxisXLabelPositionX(int index)
{
  return ((m_AxisOffsetRight - m_AxisOffsetLeft) * (index + 1) / (Config::numberOfAxisXLabels + 1) + m_AxisOffsetLeft);
}

double Accelerometer::calculateAxisYLabelPositionY(int index)
{
  return m_AxisOffsetTop + (m_AxisOffsetBottom - m_AxisOffsetTop) * index / (Config::numberOfAxisYLabels - 1);
}

double Accelerometer::calculateBarPositionOnAxisX(int index)
{
  return ((m_AxisOffsetRight - m_AxisOffsetLeft) * index / (Config::numberOfAxisXLabels + 1) + m_AxisOffsetLeft) - Config::barWidth / 2;
}

double Accelerometer::calculateBarHeight(double inputHeight)
{
  return inputHeight / Config::maxBarValue * (m_AxisOffsetTop - m_AxisYMiddle);
}

void Accelerometer::setBars(Metrics microbitData)
{
  m_Heights[0] = microbitData.accelerometerVectors[0];
  m_Heights[1] = microbitData.accelerometerVectors[1];
  m_Heights[2] = microbitData.accelerometerVectors[2];
  update();
}

void Accelerometer::setHeightX(double x)
{
  m_Heights[0] = x;
  update();
}

void Accelerometer::setHeightY(double y)
{
  m_Heights[1] = y;
  update();
}

void Accelerometer::setHeightZ(double z)
{
  m_Heights[2] = z;
  update();
}