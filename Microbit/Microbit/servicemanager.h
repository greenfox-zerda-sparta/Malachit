#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "receiverservice.h"
#include "senderservice.h"
#include "receiver.h"
#include "sender.h"

class ServiceManager : public QObject
{
  Q_OBJECT

public:
  ServiceManager(QObject *parent);

signals:
  void portNameSet();
  void serialPortSet();

public slots:
  void setUpSerialPort(QString);
  void shareSerialPort();

private:
  QSharedPointer<QSerialPort> m_SharedPort;
  void setUpSerialPort();
};

#endif