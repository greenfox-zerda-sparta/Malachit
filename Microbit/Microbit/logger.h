#pragma once
#include <QProcessEnvironment>
#include <QTextStream>
#include <QVector>

class Logger {
private:
  QProcessEnvironment m_environment;
  const char* m_logLevel;
  QTextStream* m_cout;
  QTextStream* m_cerr;
  QLoggingCategory* m_logging;
  

public:
  Logger(const char*);
  Logger::Logger(QTextStream*, QTextStream*, const char*);
  ~Logger();
  void setLevel();
  void debug(const char*);
  void info(const char*);
  void warning(const char*);
  void critical(const char*);
  void dummyLogging();
  void setLoggingLevels(int);
};

