#pragma once
#include <QObject>

class Config : public QObject {
  Q_OBJECT

public:
  Config(QObject * parent = Q_NULLPTR);
  static const int preferredAccelerometerVectorSize = 3;
  static const int preferredDataSize = 4;

};
