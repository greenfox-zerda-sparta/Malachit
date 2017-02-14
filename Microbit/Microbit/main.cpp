#ifdef _TEST

#include <QtTest>
#include "testlogger.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  TestLogger test;
  return QTest::qExec(&test, argc, argv);
}

#endif

#ifndef _TEST

#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "receiverservice.h"
#include "senderservice.h"
#include "datareceiver.h"
#include "datasender.h"
#include "config.h"
#include <QtSerialPort/QSerialPort>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  
  QSerialPort sharedPort;
  sharedPort.setPortName(Config::serialPort);
  sharedPort.setBaudRate(Config::baudRate);
  sharedPort.open(QIODevice::ReadWrite);

  ReceiverService::setReceiver(&a);
  SenderService::setSender(&a);
  DataReceiver::setPort(&sharedPort);
  DataSender::setPort(&sharedPort);

  MainWindow w;
  w.show();

  return a.exec();
}

#endif