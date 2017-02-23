#include "sender.h"

QSerialPort* Sender::m_SerialPort = NULL;

Sender::Sender(QObject *parent)
  : QObject(parent)
{
  m_Logger = new Logger("INFO");
}

void Sender::setPort(QSerialPort* port)
{
  m_SerialPort = port;
}

void Sender::sendData(int row, int column)
{
  QString message = QString::number(row) + QString::number(column);
  QByteArray data = message.toUtf8();
  m_Logger->info(data);
  m_SerialPort->write(data);
}