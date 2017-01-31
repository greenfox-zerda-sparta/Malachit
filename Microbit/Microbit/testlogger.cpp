#include "testlogger.h"

TestLogger::TestLogger(QObject * parent) : QObject(parent)
{
	
}

void TestLogger::testDebugLevel() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  const char* logLevel = "DEBUG";
  Logger logger(mockCout, mockCerr, logLevel);
  logger.debug("Debug message");
  logger.info("Info message");
  logger.warning("Warning message");
  logger.critical("Critical message");
  QCOMPARE(mockCout->readAll(), QString("DEBUG: Debug message\nINFO: Info message\n"));
  QCOMPARE(mockCerr->readAll(), QString("WARNING: Warning message\nCRITICAL: Critical message\n"));
}

void TestLogger::testInfoLevel() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  const char* logLevel = "INFO";
  Logger logger(mockCout, mockCerr, logLevel);
  logger.debug("Debug message");
  logger.info("Info message");
  logger.warning("Warning message");
  logger.critical("Critical message");
  QCOMPARE(mockCout->readAll(), QString("INFO: Info message\n"));
  QCOMPARE(mockCerr->readAll(), QString("WARNING: Warning message\nCRITICAL: Critical message\n"));
}

void TestLogger::testWarningLevel() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  const char* logLevel = "WARNING";
  Logger logger(mockCout, mockCerr, logLevel);
  logger.debug("Debug message");
  logger.info("Info message");
  logger.warning("Warning message");
  logger.critical("Critical message");
  QCOMPARE(mockCout->readAll(), QString(""));
  QCOMPARE(mockCerr->readAll(), QString("WARNING: Warning message\nCRITICAL: Critical message\n"));
}

void TestLogger::testCriticalLevel() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  const char* logLevel = "CRITICAL";
  Logger logger(mockCout, mockCerr, logLevel);
  logger.debug("Debug message");
  logger.info("Info message");
  logger.warning("Warning message");
  logger.critical("Critical message");
  QCOMPARE(mockCout->readAll(), QString(""));
  QCOMPARE(mockCerr->readAll(), QString("CRITICAL: Critical message\n"));
}