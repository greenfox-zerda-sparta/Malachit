#include "logger.h"
#include <QDebug>
#include <QLoggingCategory>

Logger::Logger(const char* category) {
	_environment = QProcessEnvironment::systemEnvironment();
	_baseLevel = _environment.value("LOG", category);
	_cout = new QTextStream(stdout);
	_cerr = new QTextStream(stderr);
	QStringList qStringList = _environment.toStringList();
	qStringList.append(category);
	_logging = new QLoggingCategory(category);
	setLevel();
	dummyLogging();
}

Logger::~Logger()
{
	delete _cout;
	delete _cerr;
	delete _logging;
}


void Logger::setLevel()

{
  if (_baseLevel == "DEBUG") {
  	qDebug() << "Megvan a debug";
		_logging->setEnabled(QtDebugMsg, true);
		_logging->setEnabled(QtInfoMsg, true);
    _logging->setEnabled(QtWarningMsg, true);
		_logging->setEnabled(QtCriticalMsg, true);

	}
  else if (_baseLevel == "INFO")
	{
    qDebug() << "Info van";
    _logging->setEnabled(QtDebugMsg, false);
    _logging->setEnabled(QtInfoMsg, true);
    _logging->setEnabled(QtWarningMsg, true);
    _logging->setEnabled(QtCriticalMsg, true);
	}
	else if (_baseLevel == "WARNING")
	{
		qDebug() << "Warning van";
    _logging->setEnabled(QtDebugMsg, false);
		_logging->setEnabled(QtInfoMsg, false);
		_logging->setEnabled(QtWarningMsg, true);
		_logging->setEnabled(QtCriticalMsg, true);
	}
	else if (_baseLevel == "CRITICAL")
	{
		qDebug() << "Critical van";
		_logging->setEnabled(QtDebugMsg, false);
		_logging->setEnabled(QtInfoMsg, false);
		_logging->setEnabled(QtWarningMsg, false);
		_logging->setEnabled(QtCriticalMsg, true);
	}
}



void Logger::debug(const char* debug)
{
	if (_logging->isDebugEnabled())
	{
		*_cout << "DEBUG: " << debug << endl;
	}
}



void Logger::info(const char* info)
{
	if (_logging->isInfoEnabled())
	{
		*_cout << "INFO: " << info << endl;
	}
}

void Logger::warning(const char* warning)
{
	if (_logging->isWarningEnabled())
	{
		*_cerr << "WARNING: " << warning << endl;
	}
}

void Logger::critical(const char* critical)
{
	if (_logging->isCriticalEnabled())
	{
		*_cerr << "CRITICAL: " << critical << endl;
	}
}

void Logger::dummyLogging()
{
	debug("eljutottam idaig");
	info("mindig ehes vagyok");
	warning("inni kell sokat");
	critical("most nincs ilyen");
}
