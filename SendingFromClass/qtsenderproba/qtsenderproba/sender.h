#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QTimer>

class Sender : public QObject
{
  Q_OBJECT

public:
    explicit Sender(QObject *parent = 0);

public slots:
    void receiveCompassData();
private:
  QTimer* m_Timer;
  int m_Number;
signals:
  void dataReceived(int);
};

#endif // SENDER_H
