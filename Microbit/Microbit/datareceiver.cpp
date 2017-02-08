#include "datareceiver.h"

DataReceiver::DataReceiver(QObject *parent)
  : QObject(parent)
{
  m_Timer = new QTimer(this);
  connect(m_Timer, SIGNAL(timeout()), this, SLOT(receiveCompassData()));
  m_Timer->start(500);

  serialPortName = "COM8";
  serialPort.setPortName(serialPortName);
  serialPortBaudRate = QSerialPort::Baud115200;
  serialPort.setBaudRate(serialPortBaudRate);

  m_Data.push_back("");
  m_Data.push_back("");
  m_Data.push_back("");
  m_Data.push_back("");

  //connect(serialPort, &QSerialPort::readyRead, this, &DataReceiver::receiveCompassData);
}

DataReceiver::~DataReceiver()
{
  delete m_Timer;
}

void DataReceiver::receiveCompassData()
{
  serialPort.open(QIODevice::ReadOnly);
  m_readData = serialPort.readAll();
  m_Data = messageParser(m_readData);

  if (m_Data.size() == 4) {
    std::cout << std::stoi(m_Data.at(0)) <<  " | " << m_Data.at(1) << " | " << m_Data.at(2) << " | " << m_Data.at(3) << "\n";
    emit dataReceived(std::stoi(m_Data.at(0)));
  }
  //std::cout << m_Data.at(0) << " | "<< m_Data.size() << "\n";
  //std::string izeke = (std::string)m_readData;
 // qDebug() << stoi(izeke);
  //int ize = std::stoi(m_Data[0]);
}

QVector<std::string> DataReceiver::messageParser(QByteArray message)
{
  QVector<std::string> data;
  std::string temp = "";
  for (int i = 0; i < message.length(); ++i) {
    if (message[i] == ',') {
      data.push_back(temp);
      temp = "";
    }
    else {
      temp += message[i];
    }
  }
  data.push_back(temp);
  return data;
}

