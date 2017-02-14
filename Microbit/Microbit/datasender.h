#ifndef DATASENDER_H
#define DATASENDER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include "config.h"

class DataSender : public QObject
{
  Q_OBJECT

public:
  DataSender(QObject *parent);
  ~DataSender();

public slots:
  void sendData();
private:
  QSerialPort m_SerialPort;
  void setupSerialPort();
};

#endif // DATASENDER_H
