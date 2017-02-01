#pragma once
#include <QProcessEnvironment>
#include <QTextStream>

class Logger {
private:
	QProcessEnvironment _environment;
	QString _baseLevel;
	QTextStream* _cout;
	QTextStream* _cerr;
	QLoggingCategory* _logging;
	QString _actualLogLevel = "";

public:
	Logger(const char*);
	~Logger();
	void setLevel();
	void debug(const char*);
	void info(const char*);
	void warning(const char*);
	void critical(const char*);
	void dummyLogging();
};

