#include "datareceiver.h"

DataReceiver::DataReceiver(QObject *parent)
  : QObject(parent)
{
  m_Timer = new QTimer(this);
  connect(m_Timer, SIGNAL(timeout()), this, SLOT(receiveCompassData()));
  m_Timer->start(500);
  setupSerialPort();
  m_Logger = new Logger("INFO");
}

DataReceiver::~DataReceiver()
{
  delete m_Timer;
}

void DataReceiver::setupSerialPort()
{
  m_SerialPort.setPortName(Config::serialPort);
  m_BaudRate = QSerialPort::Baud115200;
  m_SerialPort.setBaudRate(m_BaudRate);
}

void DataReceiver::receiveCompassData()
{
  m_SerialPort.open(QIODevice::ReadOnly);
  m_ReadData = m_SerialPort.readAll();
  if (!m_ReadData.isEmpty())
  {
    m_Metric = parseMessage(m_ReadData);
  }
  if (m_Metric.accelerometerVectors.size() == Config::preferredAccelerometerVectorSize)
  {
    m_Logger->info(m_Metric);
    emit dataReceived(m_Metric);
  }
}

Metrics DataReceiver::parseMessage(const QByteArray& message)
{
  QVector<std::string> data = processStringData(message);
  Metrics buffer;
  if (data.size() == Config::preferredDataSize)
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
