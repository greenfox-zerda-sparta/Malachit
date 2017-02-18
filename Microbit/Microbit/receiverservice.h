#ifndef RECEIVERSERVICE_H
#define RECEIVERSERVICE_H

#include <QObject>
#include "receiver.h"

class ReceiverService : public QObject
{
  Q_OBJECT

public:
  ReceiverService(QObject *parent);
  ~ReceiverService();
  static void setReceiver(QObject *parent);
private:
  static Receiver* m_Receiver;
public slots:
  void receive(Metrics);
signals:
  void metricsReceived(Metrics);
};

#endif // RECEIVERSERVICE_H
