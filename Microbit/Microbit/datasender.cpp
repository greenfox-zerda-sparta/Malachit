#include "datasender.h"

DataSender::DataSender(QObject *parent)
  : QObject(parent)
{
  setupSerialPort();
}

DataSender::~DataSender()
{

}
void DataSender::setupSerialPort()
{
  m_SerialPort.setPortName(Config::serialPort);
  m_SerialPort.setBaudRate(Config::baudRate);
  m_SerialPort.open(QIODevice::ReadWrite);
}
void DataSender::sendData()
{
  QByteArray data = "a";
  m_SerialPort.write(data);
}