#include "datareceiver.h"

DataReceiver::DataReceiver(QObject *parent)
  : QObject(parent)
{
  m_Timer = new QTimer(this);
  connect(m_Timer, SIGNAL(timeout()), this, SLOT(receiveCompassData()));
  m_Timer->start(1000);
  m_Number = 0;
}

DataReceiver::~DataReceiver()
{
  delete m_Timer;
}

void DataReceiver::receiveCompassData()
{
  m_Number++;
  qDebug() << m_Number;
  emit dataReceived(m_Number);
}

