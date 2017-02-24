#ifndef DATASENDER_H
#define DATASENDER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include "config.h"
#include "logger.h"

class Sender : public QObject
{
  Q_OBJECT

public:
  Sender(QObject *parent);
  static void setPort(QSharedPointer<QSerialPort> port);
  
public slots:
  void sendData(int row, int column);

private:
  QScopedPointer<Logger> m_Logger;
  static QSharedPointer<QSerialPort> m_SerialPort;
};

#endif
