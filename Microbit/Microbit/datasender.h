#ifndef DATASENDER_H
#define DATASENDER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <string>
#include "config.h"

class DataSender : public QObject
{
  Q_OBJECT

public:
  DataSender(QObject *parent);
  ~DataSender();
  static void setPort(QSerialPort* port);

public slots:
  void sendData(int row, int column);
private:
  static QSerialPort* m_SerialPort;
};

#endif // DATASENDER_H