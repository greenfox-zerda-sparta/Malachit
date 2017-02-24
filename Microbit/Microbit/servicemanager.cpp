#include "servicemanager.h"

ServiceManager::ServiceManager(QObject *parent)
  : QObject(parent),
  m_SharedPort(new QSerialPort)
{
  ReceiverService::setReceiver(this);
  SenderService::setSender(this);
}

void ServiceManager::setUpSerialPort(QString serialPortName)
{
  m_SharedPort->setPortName(serialPortName);
  m_SharedPort->setBaudRate(Config::baudRate);
  m_SharedPort->open(QIODevice::ReadWrite);  
  shareSerialPort();
}

void ServiceManager::shareSerialPort()
{
  Receiver::setPort(m_SharedPort);
  Sender::setPort(m_SharedPort);
  Receiver::startReceiving();
}