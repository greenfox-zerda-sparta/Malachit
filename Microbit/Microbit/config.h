#pragma once
#include <QObject>

#include <QString>
#include <QFont>

namespace Config
{
  const int preferredAccelerometerVectorSize = 3;
  const int preferredDataSize = 4;
  const QString serialPort = "COM4";
  const double maxBarValue = 1500.0;
  const double barWidth = 50.0;
  const int numberOfBars = 3;
  const double paddingProportion = 0.1;
  const QFont axisTitleFont("Arial", 10, 100);
  const QFont axisLableFont("Arial", 10);
  const int spaceBetweenAxisXAndLabel = 15;
  const int spaceBetweenAxisYAndLabel = 33;
  const int topLabel = 1500;
  const int numberOfLabels = 7;
  const int number
  const int labelStep = 500;
};