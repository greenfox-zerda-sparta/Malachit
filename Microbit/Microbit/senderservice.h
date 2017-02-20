#ifndef SENDERSERVICE_H
#define SENDERSERVICE_H

#include <QObject>
#include "sender.h"
class SenderService : public QObject
{
  Q_OBJECT

public:
  SenderService(QObject *parent);
  ~SenderService();
  static void setSender(QObject *parent);
public slots:
  void send(int, int);
private:
  static Sender* m_Sender;
signals:
  void sendToSender(int, int);
};

#endif // SENDERSERVICE_H
