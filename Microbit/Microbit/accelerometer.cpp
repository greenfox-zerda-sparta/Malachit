#include "accelerometer.h"

Accelerometer::Accelerometer(QWidget *parent)
  : QWidget(parent)
{
  m_HeightX = 0.0;
  m_HeightY = 0.0;
  m_HeightZ = 0.0;
  m_Heights << m_HeightX << m_HeightY << m_HeightZ;
  m_MaxHeight = 300.0;
  m_WidthAll = 50.0;
  m_Proportion = 0.1;
  m_NumberOfBars = 3;
  m_LabelXAxis << "X" << "Y" << "Z";
  m_LabelYAxis << "300" << "200" << "100";
}

Accelerometer::~Accelerometer() {}

void Accelerometer::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  setCoordinates();
  createAxisX(painter);
  createAxisY(painter);
  setLabels(painter);
  drawBars(painter);
}

void Accelerometer::setCoordinates()
{
  m_AxisOffsetTop = (double)(this->height() * m_Proportion);
  m_AxisOffsetRight = (double)(this->width() - this->width() * m_Proportion);
  m_AxisOffsetBottom = (double)(this->height() - this->height() * m_Proportion);
  m_AxisOffsetLeft = (double)(this->width() * m_Proportion);
}

void Accelerometer::createAxisX(QPainter& painter)
{
  QLineF axisX(m_AxisOffsetLeft, m_AxisOffsetBottom, m_AxisOffsetRight, m_AxisOffsetBottom);
  painter.setPen(Qt::black);
  painter.drawLine(axisX);
  
  setAxisTitle(painter, "Direction", (Qt::AlignHCenter | Qt::AlignBottom));
  /*setAxisXlabel(painter);*/
}

void Accelerometer::createAxisY(QPainter& painter)
{
  QLineF axisY(m_AxisOffsetLeft, m_AxisOffsetTop, m_AxisOffsetLeft, m_AxisOffsetBottom);
  painter.setPen(Qt::black);
  painter.drawLine(axisY);

  setAxisTitle(painter, "g", (Qt::AlignVCenter | Qt::AlignLeft));
  /*setAxisYlabel(painter);*/
}

void Accelerometer::drawBars(QPainter& painter)
{
  QVector<double> rectXcoordinates;
  for (int i = 1; i <= m_NumberOfBars; ++i)
  {
    rectXcoordinates.push_back(calculateBarPositionOnAxisX(i));
  }

  QVector<QColor> barColors;
  barColors << Qt::darkMagenta << Qt::darkCyan << Qt::darkBlue;
  for (int i = 0; i < m_NumberOfBars; ++i)
  {
    createBar(painter, m_Heights[i], rectXcoordinates[i], barColors[i]);
  }
}

void Accelerometer::createBar(QPainter& painter, double height, double rectXCoordinate, QColor color)
{
  double responsiveHeight = calculateBarHeight(height);
  QRectF rect(rectXCoordinate, m_AxisOffsetBottom - responsiveHeight, m_WidthAll, responsiveHeight);
  painter.setPen(Qt::NoPen);
  painter.setBrush(color);
  painter.drawRect(rect);
}

void Accelerometer::setAxisTitle(QPainter& painter, QString name, int flag)
{
  QRectF rect(0, 0, this->width(), this->height());
  painter.setFont(QFont("Arial", 10, 100));
  painter.drawText(rect, flag, name);
}

void Accelerometer::setLabels(QPainter& painter)
{
  drawLabels(painter, getXLabelPositions(m_LabelsX));
  drawLabels(painter, getYLabelPositions(m_LabelsY));
}

void Accelerometer::drawLabels(QPainter& painter, QVector<Label> labels)
{
    painter.setFont(QFont("Arial", 10));
    for (int i = 0; i < labels.size(); ++i)
    {
      painter.drawText(labels[i].coordinates, labels[i].name);
    }
}

QVector<Label> Accelerometer::getXLabelPositions(QVector<QString> labelsX)
{
  QVector<Label> temp;

  for (int i = 0; i < labelsX.size(); ++i)
  {
    temp[i].name = labelsX[i];
    temp[i].coordinates.setX(calculateAxisXLabelPositionX(i));
    temp[i].coordinates.setY(m_AxisOffsetBottom + X_AXIS_MARGIN);
  }

  return temp;
}

QVector<Label> Accelerometer::getYLabelPositions(QVector<QString> labelsY)
{
  QVector<Label> temp;

  for (int i = 0; i < labelsY.size(); ++i)
  {
    temp[i].name = labelsY[i];
    temp[i].coordinates.setX(m_AxisOffsetLeft - Y_AXIS_MARGIN);
    temp[i].coordinates.setY(calculateAxisYLabelPositionY(i));
  }

  return temp;
}

//void Accelerometer::setAxisXlabel(QPainter& painter)
//{
//  QVector<QString> labels;
//  labels << "X" << "Y" << "Z";
//  painter.setFont(QFont("Arial", 10));
//
//  for (int i = 0; i < labels.size(); ++i)
//  {
//    QPointF point(calculateAxisXLabelPositionX(i), m_axisOffsetBottom + 15);
//    painter.drawText(point, labels[i]);
//  }
//}
//
//void Accelerometer::setAxisYlabel(QPainter& painter)
//{
//  QVector<QString> labels;
//  labels << "300" << "200" << "100";
//  painter.setFont(QFont("Arial", 10));
//
//  for (int i = 0; i < labels.size(); ++i)
//  {
//    QPointF point(m_axisOffsetLeft - 22, calculateAxisYLabelPositionY(i));
//    painter.drawText(point, labels[i]);
//  }
//}

double Accelerometer::calculateAxisXLabelPositionX(int index)
{
  return ((m_AxisOffsetRight - m_AxisOffsetLeft) * 0.25 * (index + 1) + m_AxisOffsetLeft);
}

double Accelerometer::calculateAxisYLabelPositionY(int index)
{
  return (m_AxisOffsetBottom - m_AxisOffsetTop) * 1 / 3 * index + m_AxisOffsetTop;
}

double Accelerometer::calculateBarPositionOnAxisX(int index)
{
  return ((m_AxisOffsetRight - m_AxisOffsetLeft) * 0.25 * index + m_AxisOffsetLeft) - m_WidthAll / 2;
}

double Accelerometer::calculateBarHeight(double inputHeight)
{
  return inputHeight / m_MaxHeight * (m_AxisOffsetBottom - m_AxisOffsetTop);
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

void Accelerometer::setWidthAll(double w)
{
  m_WidthAll = w;
}

