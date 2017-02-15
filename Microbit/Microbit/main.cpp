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
#include "datareceiver.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  
  ReceiverService::setReceiver(&a);
  MainWindow w;
  w.show();

  return a.exec();
}

#endif