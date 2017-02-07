#include "datareceiver.h"

DataReceiver::DataReceiver(QObject *parent)
  : QObject(parent)
{
  m_Timer = new QTimer(this);
  connect(m_Timer, SIGNAL(timeout()), this, SLOT(receiveCompassData()));
  m_Timer->start(1000);
  m_Number = 0;

  serialPortName = "COM9";
  serialPort.setPortName(serialPortName);
  serialPortBaudRate = QSerialPort::Baud115200;
  serialPort.setBaudRate(serialPortBaudRate);

  //connect(serialPort, &QSerialPort::readyRead, this, &DataReceiver::receiveCompassData);
}

DataReceiver::~DataReceiver()
{
  delete m_Timer;
}

void DataReceiver::receiveCompassData()
{
  m_Number++;
  serialPort.open(QIODevice::ReadOnly);
  m_readData.append(serialPort.readAll());
  qDebug() << m_readData;
  emit dataReceived(m_Number);
}

