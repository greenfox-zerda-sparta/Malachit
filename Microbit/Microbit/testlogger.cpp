#include "testlogger.h"

void TestLogger::init()
{
  buffer = new QString;
  buffer2 = new QString;
  mockCout = new QTextStream(buffer, QIODevice::ReadWrite);
  mockCerr = new QTextStream(buffer2, QIODevice::ReadWrite);
}

void TestLogger::testDebugLevel() {
  const char* logLevel = "DEBUG";
  Logger logger(mockCout, mockCerr, logLevel);
  dummyLogging(logger);
  QCOMPARE(mockCout->readAll(), QString("DEBUG: Debug message\nINFO: Info message\n"));
  QCOMPARE(mockCerr->readAll(), QString("WARNING: Warning message\nCRITICAL: Critical message\n"));
}

void TestLogger::testInfoLevel() {
  const char* logLevel = "INFO";
  Logger logger(mockCout, mockCerr, logLevel);
  dummyLogging(logger);
  QCOMPARE(mockCout->readAll(), QString("INFO: Info message\n"));
  QCOMPARE(mockCerr->readAll(), QString("WARNING: Warning message\nCRITICAL: Critical message\n"));
}

void TestLogger::testWarningLevel() {
  const char* logLevel = "WARNING";
  Logger logger(mockCout, mockCerr, logLevel);
  dummyLogging(logger);
  QCOMPARE(mockCout->readAll(), QString(""));
  QCOMPARE(mockCerr->readAll(), QString("WARNING: Warning message\nCRITICAL: Critical message\n"));
}

void TestLogger::testCriticalLevel() {
  const char* logLevel = "CRITICAL";
  Logger logger(mockCout, mockCerr, logLevel);
  dummyLogging(logger);
  QCOMPARE(mockCout->readAll(), QString(""));
  QCOMPARE(mockCerr->readAll(), QString("CRITICAL: Critical message\n"));
}

void TestLogger::dummyLogging(Logger& logger)
{
  logger.debug("Debug message");
  logger.info("Info message");
  logger.warning("Warning message");
  logger.critical("Critical message");
}

void TestLogger::cleanup()
{
  delete buffer;
  delete buffer2;
  delete mockCout;
  delete mockCerr;
}