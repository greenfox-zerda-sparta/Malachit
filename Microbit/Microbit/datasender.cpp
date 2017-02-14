#include "datasender.h"
#include <QDebug>
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
  qDebug() << data;
  m_SerialPort->write(data);
}