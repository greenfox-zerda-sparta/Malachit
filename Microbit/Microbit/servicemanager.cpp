#include "servicemanager.h"

ServiceManager::ServiceManager(QObject *parent)
  : QObject(parent)
{
  setUpSerialPort();
  ReceiverService::setReceiver(parent);
  SenderService::setSender(parent);
  DataReceiver::setPort(&m_SharedPort);
  DataSender::setPort(&m_SharedPort);
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