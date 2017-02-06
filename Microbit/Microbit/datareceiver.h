#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class DataReceiver : public QObject
{
  Q_OBJECT

public:
  DataReceiver(QObject *parent);
  ~DataReceiver();

public slots:
  void receiveCompassData();
private:
  QTimer* m_Timer;
  int m_Number;
signals:
  void dataReceived(int);

};

#endif // DATARECEIVER_H
