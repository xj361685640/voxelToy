#pragma once

#include <QtCore>
#include <QString>
#include <string>

class Logger
{
public:
	virtual void operator()(const std::string& msg) = 0;
};

class QtLogger : public QObject, public Logger
{
	Q_OBJECT
public:
	
	virtual ~QtLogger() {}

	virtual void operator()(const std::string& msg);

signals:
	void logMessage(QString);
};

class QtFileLogger : public QtLogger
{
public:
	QtFileLogger();
	virtual ~QtFileLogger();

	virtual void operator()(const std::string& msg);
private:
	FILE* m_fd;
};
