#include "datareceiver.h"

DataReceiver::DataReceiver(QObject *parent)
  : QObject(parent)
{
  m_Timer = new QTimer(this);
  connect(m_Timer, SIGNAL(timeout()), this, SLOT(receiveCompassData()));
  m_Timer->start(500);
  setupSerialPort();
}

DataReceiver::~DataReceiver()
{
  delete m_Timer;
}

void DataReceiver::setupSerialPort()
{
  serialPortName = "COM4";
  serialPort.setPortName(serialPortName);
  serialPortBaudRate = QSerialPort::Baud115200;
  serialPort.setBaudRate(serialPortBaudRate);
}

void DataReceiver::receiveCompassData()
{
  serialPort.open(QIODevice::ReadOnly);
  m_ReadData = serialPort.readAll();
  
  if (m_ReadData.size() >= 8)
  {
    m_Metric = parseMessage(m_ReadData);
  }

  if (m_Metric.accelerometerVectors.size() == 3) {
    std::cout << m_Metric.compassHeading <<  " | " << m_Metric.accelerometerVectors[0] << " | " << m_Metric.accelerometerVectors[1] << " | " << m_Metric.accelerometerVectors[2] << "\n";
    emit dataReceived(m_Metric.compassHeading);
  }
}

Metrics DataReceiver::parseMessage(const QByteArray& message)
{
  QVector<std::string> data = processStringData(message);
  Metrics buffer;
  if (data.size() == 4)
  {
    buffer = convertProcessedStringToMetrics(data);
  }
  return buffer;
}

QVector<std::string> DataReceiver::processStringData(const QByteArray& message)
{
  QVector<std::string> data;
  std::string temp = "";
  for (int i = 0; i < message.length(); ++i)
  {
    if (message[i] == ',')
    {
      data.push_back(temp);
      temp = "";
    }
    else 
    {
      temp += message[i];
    }
  }
  return data;
}

Metrics DataReceiver::convertProcessedStringToMetrics(QVector<std::string> data)
{
  Metrics buffer;
  buffer.compassHeading = std::stoi(data[0]);
  for (int i = 1; i < data.size(); ++i)
  {
    buffer.accelerometerVectors.push_back(std::stoi(data[i]));
  }
  return buffer;
}
