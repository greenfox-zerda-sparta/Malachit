#include "senderservice.h"

DataSender* SenderService::m_Sender = NULL;

SenderService::SenderService(QObject *parent)
  : QObject(parent)
{
  connect(this, SIGNAL(sendToSender(int, int)), m_Sender, SLOT(sendData(int, int)));
}

SenderService::~SenderService()
{

}
void SenderService::setSender(QObject *parent)
{
  m_Sender = new DataSender(parent);
}
void SenderService::send(int row, int column)
{
  emit sendToSender(row, column);
}