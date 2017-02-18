#ifndef DATASENDER_H
#define DATASENDER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <string>
#include "config.h"
#include "logger.h"

class Sender : public QObject
{
  Q_OBJECT

public:
  Sender(QObject *parent);
  static void setPort(QSerialPort* port);
public slots:
  void sendData(int row, int column);
private:
  Logger* m_Logger;
  static QSerialPort* m_SerialPort;
};

#endif // DATASENDER_H
