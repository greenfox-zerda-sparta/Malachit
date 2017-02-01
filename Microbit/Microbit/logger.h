#pragma once
#include <QProcessEnvironment>
#include <QDebug>
#include <QLoggingCategory>
#include <QTextStream>
#include <QVector>

class Logger {
private:
  QProcessEnvironment m_environment;
  QString m_logLevel;
  QTextStream* m_cout;
  QTextStream* m_cerr;
  QLoggingCategory* m_logging;
  void init(const char*);

public:
  Logger(const char*);
  Logger::Logger(QTextStream*, QTextStream*, const char*);
  void setCategoryLevels();
  void setLoggingLevels(int);
  void debug(const char*);
  void info(const char*);
  void warning(const char*);
  void critical(const char*);
};
