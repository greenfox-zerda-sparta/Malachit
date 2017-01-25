#include "testlogger.h"
#include "logger.h"

TestLogger::TestLogger(QObject * parent) : QObject(parent) {
	
}

void TestLogger::test_debug() {
  Logger logger("Debug");
  QLoggingCategory* debug = logger.getDebugCategory();
}

void TestLogger::test_info() {
  Logger info("Info");
}

void TestLogger::test_warning() {
  Logger warning("Warning");
}

void TestLogger::test_critical() {
  Logger critical("Critical");
}