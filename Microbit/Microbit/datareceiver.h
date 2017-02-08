#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <stdlib.h>
#include <string>
#include <iostream>

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
  QByteArray m_readData;
  QVector<std::string> m_Data;

  QVector<std::string> messageParser(QByteArray message);
signals:
  void dataReceived(int);

};

#endif // DATARECEIVER_H
