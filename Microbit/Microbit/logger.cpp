#include "logger.h"
#include <QDebug>
#include <QLoggingCategory>

QVector<QtMsgType> messageType = { QtDebugMsg, QtInfoMsg, QtWarningMsg, QtCriticalMsg };

Logger::Logger(const char* category) {
  m_environment = QProcessEnvironment::systemEnvironment();
  //m_logLevel = m_environment.value("LOG", category);
  m_logLevel = category;
  m_cout = new QTextStream(stdout);
  m_cerr = new QTextStream(stderr);
  //QStringList qStringList = m_environment.toStringList();
  //qStringList.append(category);
  m_logging = new QLoggingCategory(category);
  setLevel();
  dummyLogging();
}

Logger::Logger(QTextStream* mockStreamCout, QTextStream* mockStreamCerr, const char* logLevel) {
  m_logLevel = logLevel;
  m_cout = mockStreamCout;
  m_cerr = mockStreamCerr;
  m_logging = new QLoggingCategory(logLevel);
  setLevel();
}

Logger::~Logger()
{
  delete m_cout;
  delete m_cerr;
  delete m_logging;
}

void Logger::setLevel()
{
  if (m_logLevel == "DEBUG") {
    setLoggingLevels(0);
  }
  else if (m_logLevel == "INFO")
  {
    setLoggingLevels(1);
  }
  else if (m_logLevel == "WARNING")
  {
    setLoggingLevels(2);
  }
  else if (m_logLevel == "CRITICAL")
  {
    setLoggingLevels(3);
  }
}

void Logger::debug(const char* debug)
{
  if (m_logging->isDebugEnabled())
  {
    m_logLevel = "DEBUG";
    *m_cout << m_logLevel << ": " << debug << endl;
  }
}

void Logger::info(const char* info)
{
  if (m_logging->isInfoEnabled())
  {
    m_logLevel = "INFO";
    *m_cout << m_logLevel << ": " << info << endl;
  }
}

void Logger::warning(const char* warning)
{
  if (m_logging->isWarningEnabled())
  {
    m_logLevel = "WARNING";
    *m_cerr << m_logLevel << ": " << warning << endl;
  }
}

void Logger::critical(const char* critical)
{
  if (m_logging->isCriticalEnabled())
  {
    m_logLevel = "CRITICAL";
    *m_cerr << m_logLevel << ": " << critical << endl;
  }
}

void Logger::dummyLogging()
{
  debug("eljutottam idaig");
  info("mindig ehes vagyok");
  warning("inni kell sokat");
  critical("most nincs ilyen");
}

void Logger::setLoggingLevels(int startingPoint)
{
  for (unsigned int i = startingPoint; i < messageType.size(); ++i)
  {
    m_logging->setEnabled(messageType[i], true);
  }
}