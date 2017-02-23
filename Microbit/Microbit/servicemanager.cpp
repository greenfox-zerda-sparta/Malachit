#include "servicemanager.h"

ServiceManager::ServiceManager(QObject *parent)
  : QObject(parent),
  m_SharedPort(new QSerialPort)
{
  ReceiverService::setReceiver(parent);
  SenderService::setSender(parent);
  connect(this, SIGNAL(portNameSet()), this, SLOT(shareSerialPort()));
}

void ServiceManager::setUpSerialPort(QString serialPortName)
{
  m_SharedPort->setPortName(serialPortName);
  m_SharedPort->setBaudRate(Config::baudRate);
  m_SharedPort->open(QIODevice::ReadWrite);  
  emit portNameSet();
}

void ServiceManager::shareSerialPort()
{
  Receiver::setPort(&m_SharedPort);
  Sender::setPort(&m_SharedPort);
  Receiver::startReceiving();
  emit serialPortSet();
}