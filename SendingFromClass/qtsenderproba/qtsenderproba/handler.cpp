#include "handler.h"

Handler::Handler(QObject *parent)
  : QObject(parent)
{
  myReceiver = new Receiver(this);
  mySender = new Sender(this);
  connect(mySender, SIGNAL(dataReceived(int)), myReceiver, SLOT(printData(int)));
}

