#include "logger.h"

QVector<QtMsgType> messageType = { QtDebugMsg, QtInfoMsg, QtWarningMsg, QtCriticalMsg };
QVector<QString> logLevels = { "DEBUG", "INFO", "WARNING", "CRITICAL" };

Logger::Logger(const char* category) {
  init(category);
}

Logger::Logger(QTextStream* mockStreamCout, QTextStream* mockStreamCerr, const char* category) {
  m_logLevel = m_environment.value("LOG", category);
  m_cout = mockStreamCout;
  m_cerr = mockStreamCerr;
  m_logging = new QLoggingCategory(category);
  setCategoryLevels();
}

void Logger::init(const char* category)
{
  m_environment = QProcessEnvironment::systemEnvironment();
  m_logLevel = m_environment.value("LOG", category);
  m_logLevel = category;
  m_cout = new QTextStream(stdout);
  m_cerr = new QTextStream(stderr);
  m_logging = new QLoggingCategory(category);
  setCategoryLevels();
}

void Logger::setCategoryLevels()
{
  for (unsigned int i = 0; i < logLevels.size(); ++i)
  {
    if (m_logLevel == logLevels[i])
    {
      setLoggingLevels(i);
    }
  }
}

void Logger::setLoggingLevels(int startingPoint)
{
  for (unsigned int i = 0; i < messageType.size(); ++i)
  {
    m_logging->setEnabled(messageType[i], i >= startingPoint);
  }
}

void Logger::debug(const char* debug)

{
  if (m_logging->isDebugEnabled())
  {
    *m_cout << "DEBUG: " << debug << endl;
  }
}

void Logger::info(const char* info)
{
  if (m_logging->isInfoEnabled())
  {
    *m_cout << "INFO: " << info << endl;
  }
}

void Logger::warning(const char* warning)
{
  if (m_logging->isWarningEnabled())
  {
    *m_cerr << "WARNING: " << warning << endl;
  }
}

void Logger::critical(const char* critical)
{
  if (m_logging->isCriticalEnabled())
  {
    *m_cerr << "CRITICAL: " << critical << endl;
  }
}