#include "testlogger.h"

TestLogger::TestLogger(QObject * parent) : QObject(parent)
{
	
}

void TestLogger::testInfoMethod() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  const char* logLevel = "INFO";
  Logger logger(mockCout, mockCerr, logLevel);
  logger.info("");
  QCOMPARE(mockCout->readLine(), QString("INFO: "));
  QCOMPARE(mockCerr->readLine(), QString(""));
}