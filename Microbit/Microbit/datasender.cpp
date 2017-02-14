#include "datasender.h"

QSerialPort* DataSender::m_SerialPort = NULL;

DataSender::DataSender(QObject *parent)
  : QObject(parent)
{

}

DataSender::~DataSender()
{

}
void DataSender::setPort(QSerialPort* port)
{
  m_SerialPort = port;
}
void DataSender::sendData()
{
  QByteArray data = "a";
  m_SerialPort->write(data);
}