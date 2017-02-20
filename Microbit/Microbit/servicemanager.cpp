#include "servicemanager.h"

ServiceManager::ServiceManager(QObject *parent)
  : QObject(parent)
{
  setUpSerialPort();
  ReceiverService::setReceiver(parent);
  SenderService::setSender(parent);
  Receiver::setPort(&m_SharedPort);
  Sender::setPort(&m_SharedPort);
}

ServiceManager::~ServiceManager()
{

}

void ServiceManager::setUpSerialPort()
{
  m_SharedPort.setPortName(Config::serialPort);
  m_SharedPort.setBaudRate(Config::baudRate);
  m_SharedPort.open(QIODevice::ReadWrite);
}