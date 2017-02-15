#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <QWidget>
#include <QtGui>
#include "datareceiver.h"
#include "receiverservice.h"


class Accelerometer : public QWidget
{
  Q_OBJECT

public:
  Accelerometer(QWidget* parent);
  void setCoordinates();
  void createAxisX(QPainter& painter);
  void createAxisY(QPainter& painter);
  void setAxisTitle(QPainter& painter, QString name, int flag);
  void setAxisXlabel(QPainter& painter);
  void setAxisYlabel(QPainter& painter);
  void drawBars(QPainter& painter);

private slots:
  void paintEvent(QPaintEvent* e);
  void setBars(Metrics microbitData);
  void setHeightX(double x);
  void setHeightY(double y);
  void setHeightZ(double z);

private:
  QVector<double> m_Heights;
  double m_HeightX;
  double m_HeightY;
  double m_HeightZ;
  double m_AxisOffsetTop;
  double m_AxisOffsetRight;
  double m_AxisOffsetBottom;
  double m_AxisOffsetLeft;
  double m_AxisYMiddle;
  void createBar(QPainter& painter, double height, double rectXCoordinate, QColor color);
  double calculateAxisXLabelPositionX(int index);
  double calculateAxisYLabelPositionY(int index);
  double calculateBarPositionOnAxisX(int index);
  double calculateBarHeight(double inputHeight);
  ReceiverService* m_ReceiverService;
};

#endif