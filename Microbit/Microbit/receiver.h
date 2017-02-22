#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <stdlib.h>
#include <string>
#include "logger.h"
#include "metrics.h"
#include "config.h"

class Receiver : public QObject
{
  Q_OBJECT

public:
  Receiver(QObject *parent);
  ~Receiver();

public slots:
  void receive();

public: 
  static void setPort(QSerialPort* port);
  static void createTimer(QObject *parent);
  static void startReceiving();
  void receiveConnect();

private:
  static QTimer* m_Timer;
  Logger* m_Logger;
  static QSerialPort* m_SerialPort;
  QByteArray m_ReadData;
  Metrics m_Metric;

  Metrics parseMessage(const QByteArray& message);
  QVector<std::string> processStringData(const QByteArray& message);
  Metrics convertProcessedStringToMetrics(QVector<std::string> data);

  

signals:
  void metricsReceived(Metrics);

  
};

#endif