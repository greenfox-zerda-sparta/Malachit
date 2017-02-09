#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <stdlib.h>
#include <string>
#include <iostream>

struct Metrics
{
  int compassHeading;
  QVector<int> accelerometerVectors;
};

class DataReceiver : public QObject
{
  Q_OBJECT

public:
  DataReceiver(QObject *parent);
  ~DataReceiver();

public slots:
  void receiveCompassData();
private:
  QTimer* m_Timer;
  QSerialPort serialPort;
  QString serialPortName;
  int serialPortBaudRate;
  QByteArray m_ReadData;
  Metrics m_Metric;
  void setupSerialPort();
  Metrics parseMessage(const QByteArray& message);
  QVector<std::string> processStringData(const QByteArray& message);
  Metrics convertProcessedStringToMetrics(QVector<std::string> data);
signals:
  void dataReceived(Metrics);
};

#endif // DATARECEIVER_H
