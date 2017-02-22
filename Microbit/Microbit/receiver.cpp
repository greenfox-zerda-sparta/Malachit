#include "receiver.h"

QSerialPort* Receiver::m_SerialPort = NULL;
QTimer* Receiver::m_Timer = NULL;

Receiver::Receiver(QObject *parent)
  : QObject(parent)
{
  connect(m_Timer, SIGNAL(timeout()), this, SLOT(receive()));
  m_Logger = new Logger("INFO");
}
void Receiver::setPort(QSerialPort* port)
{
  m_SerialPort = port;
}

Receiver::~Receiver()
{
  delete m_Timer;
}

void Receiver::receive()
{
  m_ReadData = m_SerialPort->readAll();
  if (!m_ReadData.isEmpty())
  {
    m_Metric = parseMessage(m_ReadData);
  }
  if (m_Metric.accelerometerVectors.size() == Config::preferredAccelerometerVectorSize)
  {
    m_Logger->info(m_Metric);
    emit metricsReceived(m_Metric);
  }

}

Metrics Receiver::parseMessage(const QByteArray& message)
{
  QVector<std::string> data = processStringData(message);
  Metrics buffer;
  if (data.size() == Config::preferredDataSize)
  {
    buffer = convertProcessedStringToMetrics(data);
  }
  return buffer;
}

QVector<std::string> Receiver::processStringData(const QByteArray& message)
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

Metrics Receiver::convertProcessedStringToMetrics(QVector<std::string> data)
{
  Metrics buffer;
  buffer.compassHeading = std::stoi(data[0]);
  for (int i = 1; i < data.size(); ++i)
  {
    buffer.accelerometerVectors.push_back(std::stoi(data[i]));
  }
  return buffer;
}

void Receiver::createTimer(QObject *parent) {
  m_Timer = new QTimer(parent);
}

void Receiver::startReceiving()
{
  m_Timer->start(500);
}

void Receiver::receiveConnect()
{
  connect(m_Timer, SIGNAL(timeout()), this, SLOT(receive()));
}