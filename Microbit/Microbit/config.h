#pragma once
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QString>
#include <QFont>

namespace Config
{
  const int preferredAccelerometerVectorSize = 3;
  const int preferredDataSize = 4;
  const QString serialPort = "COM9";
  const int baudRate = QSerialPort::Baud115200;

  const double maxBarValue = 1500.0;
  const double barWidth = 50.0;
  const int numberOfBars = 3;
  const double paddingProportion = 0.1;
  const QFont axisTitleFont("Arial", 10, 100);
  const QFont axisLableFont("Arial", 10);
  const int spaceBetweenAxisXAndLabel = 15;
  const int spaceBetweenAxisYAndLabel = 33;
  const int topAxisYLabel = 1500;
  const int labelStep = 500;
  const int numberOfAxisYLabels = 7;
  const int numberOfAxisXLabels = 3;

  const int fullRotation = 360;
  const int numOfScales = 60;
  const int scaleLength = 5;
  const int azimuthHandWidth = 12;
  const double diameterToWidgetProportion = 0.66;

  const int matrixSize = 5;
  const int buttonSize = 60;
  const int buttonPosition = 100;
  const double minMargin = 10.0;
  const double proportionOfMargin = 0.1;
};