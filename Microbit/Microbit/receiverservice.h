#ifndef RECEIVERSERVICE_H
#define RECEIVERSERVICE_H

#include <QObject>
#include "datareceiver.h"

class ReceiverService : public QObject
{
  Q_OBJECT

public:
  ReceiverService(QObject *parent);
  ~ReceiverService();
  static void setReceiver(QObject *parent);
private:
  static DataReceiver* m_Receiver;


public slots:
  void receive(Metrics);
signals:
  void dataReceived(Metrics);
};

#endif // RECEIVERSERVICE_H
