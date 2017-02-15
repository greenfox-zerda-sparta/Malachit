#include "senderservice.h"

DataSender* SenderService::m_Sender = NULL;

SenderService::SenderService(QObject *parent)
  : QObject(parent)
{
  connect(this, SIGNAL(sendToSender()), m_Sender, SLOT(sendData()));
}

SenderService::~SenderService()
{

}
void SenderService::setSender(QObject *parent)
{
  m_Sender = new DataSender(parent);
}
void SenderService::send()
{
  emit sendToSender();
}