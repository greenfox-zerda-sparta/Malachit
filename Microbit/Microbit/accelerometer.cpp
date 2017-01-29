#include "accelerometer.h"

Accelerometer::Accelerometer(QWidget *parent)
  : QWidget(parent)
{
  m_HeightX = 0.0;
  m_HeightY = 0.0;
  m_HeightZ = 0.0;
  m_WidthAll = 50.0;

}

Accelerometer::~Accelerometer()
{
  
}

void Accelerometer::createAxisX()
{
  QLineF axisX(30.0, 310.0, 340.0, 310.0);
  QPainter painter(this);
  painter.setPen(Qt::black);
  painter.drawLine(axisX);
  
  QVector<QString> labels;
  labels << "X" << "Y" << "Z";

  painter.setFont(QFont("Arial", 12, 100));
  painter.drawText(140.0, 345.0, "Direction");

  painter.setFont(QFont("Arial", 12));
  QPointF point(40.0, 330.0);
  for (int i = 0; i < labels.size(); ++i)
  {
    painter.drawText(point, labels[i]);
    point += QPointF(80.0, 0.0);
  }
}

void Accelerometer::createAxisY()
{
  QLineF axisY(30.0, 310.0, 30.0, 10.0);
  QPainter painter(this);
  painter.setPen(Qt::black);
  painter.drawLine(axisY);

  painter.setFont(QFont("Arial", 12, 100));
  painter.drawText(5, 150, "g");

  QVector<QString> ticks;
  ticks << "300" << "200" << "100";
  painter.setFont(QFont("Arial", 12));
  QPointF point(2.0, 15.0);
  for (int i = 0; i < ticks.size(); ++i)
  {
    painter.drawText(point, ticks[i]);
    point += QPointF(0, 100.0);
  }
}

void Accelerometer::drawBars()
{

  /*QRectF r1(100, 200, 11, 16);
  QRectF r2(30, 30, 30, 30);
  QRectF r3(30, 30, 30, 30);*/

  QPainter painter(this);
  painter.setPen(Qt::NoPen);
  painter.setBrush(Qt::red);
  painter.save();
  painter.drawRect(30, 310 - m_HeightX, m_WidthAll, m_HeightX);
  painter.setBrush(Qt::darkGreen);
  painter.drawRect(110, 310 - m_HeightY, m_WidthAll, m_HeightY);
  painter.setBrush(Qt::blue);
  painter.drawRect(190, 310 - m_HeightZ, m_WidthAll, m_HeightZ);
  painter.setBrush(Qt::cyan);
  //painter.drawRect(r1);

  
}


void Accelerometer::paintEvent(QPaintEvent *e)
{
  drawBars();
  createAxisX();
  createAxisY();
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

