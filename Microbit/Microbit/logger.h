#pragma once
#include <QProcessEnvironment>
#include <QDebug>
#include <QLoggingCategory>
#include <QTextStream>
#include <QVector>
#include "metrics.h"

class Logger {
private:
  QProcessEnvironment m_environment;
  QString m_logLevel;
  QTextStream* m_cout;
  QTextStream* m_cerr;
  QLoggingCategory* m_logging;

public:
  Logger(const char*);
  Logger::Logger(QTextStream*, QTextStream*, const char*);
  void setCategoryLevels();
  void setLoggingLevels(int);
  void debug(const char*);
  void info(const char*);
  void info(Metrics);
  void warning(const char*);
  void critical(const char*);
};
