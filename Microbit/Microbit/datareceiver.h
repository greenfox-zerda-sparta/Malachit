#ifndef DATARECEIVER_H
#define DATARECEIVER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QtSerialPort/QSerialPort>

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
  QSerialPort serialPort;
  QString serialPortName;
  int serialPortBaudRate;
  QByteArray m_readData;
signals:
  void dataReceived(int);

};

#endif // DATARECEIVER_H
