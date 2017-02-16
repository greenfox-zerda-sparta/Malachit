#include "receiverservice.h"

DataReceiver* ReceiverService::m_Receiver = NULL;

ReceiverService::ReceiverService(QObject *parent)
  : QObject(parent)
{
  connect(m_Receiver, SIGNAL(dataReceived(Metrics)), this, SLOT(receive(Metrics)));
}
ReceiverService::~ReceiverService()
{

}
void ReceiverService::receive(Metrics data)
{
  emit dataReceived(data);
}
void ReceiverService::setReceiver(QObject *parent)
{
  m_Receiver = new DataReceiver(parent);
}