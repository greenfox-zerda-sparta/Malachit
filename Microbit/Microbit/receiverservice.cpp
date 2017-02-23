#include "receiverservice.h"

Receiver* ReceiverService::m_Receiver = NULL;

ReceiverService::ReceiverService(QObject *parent)
  : QObject(parent)
{
  connect(m_Receiver, SIGNAL(metricsReceived(Metrics)), this, SLOT(receive(Metrics)));
}

void ReceiverService::receive(Metrics data)
{
  emit metricsReceived(data);
}

void ReceiverService::setReceiver(QObject *parent)
{
  m_Receiver = new Receiver(parent);
}