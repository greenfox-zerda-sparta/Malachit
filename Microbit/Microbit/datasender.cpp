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
void DataSender::sendData(int row, int column)
{
  QString message = QString::number(row) + QString::number(column);
  QByteArray data = message.toUtf8();
  qDebug() << data;
  m_SerialPort->write(data);
}