#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "receiver.h"
#include "sender.h"

class Handler : public QObject
{
  Q_OBJECT

public:
    explicit Handler(QObject *parent = 0);


private:
  Sender* mySender;
  Receiver* myReceiver;
};

#endif // HANDLER_H
