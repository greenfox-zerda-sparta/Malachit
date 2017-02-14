#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QObject>
#include "receiverservice.h"
#include "senderservice.h"
#include "datareceiver.h"
#include "datasender.h"
#include "config.h"
#include <QtSerialPort/QSerialPort>

class ServiceManager : public QObject
{
  Q_OBJECT

public:
  ServiceManager(QObject *parent);
  ~ServiceManager();

private:
  QSerialPort m_SharedPort;
  void setUpSerialPort();
};

#endif // SERVICEMANAGER_H
