#include "Logger.h"
#include <QDebug>
#include <QLoggingCategory>


Logger::Logger(QString category) {
  processEnvironment = QProcessEnvironment::systemEnvironment();
  QStringList qStringList = processEnvironment.toStringList();
  qStringList.append(category);
  debug = new QLoggingCategory("Debug");
  info = new QLoggingCategory("Info");
  warning = new QLoggingCategory("Warning");
  critical = new QLoggingCategory("Critical");
  
  for (int i = 0; i < qStringList.size(); ++i) {
    if (qStringList.at(i) == "Debug") {
      qDebug() << "Megvan a debug";
      myCategoryFilter(debug);
    }
    else if (qStringList.at(i) == "Info") {
      qDebug() << "Info van";
      myCategoryFilter(info);
    }
    else if (qStringList.at(i) == "Warning") {
      qDebug() << "Warning van";
      myCategoryFilter(warning);
    }
    else if (qStringList.at(i) == "Critical") {
      qDebug() << "Critical van";
      myCategoryFilter(critical);
    }
    //qDebug() << i << qStringList.at(i).toUtf8().constData();
  }
  
  //qDebug() << debug->categoryName();
  
}

void Logger::myCategoryFilter(QLoggingCategory *category) {
  // configure driver.usb category here, otherwise forward to default filter.
  if (qstrcmp(category->categoryName(), "Debug") == 0) {
    debug->setEnabled(QtDebugMsg, true);
    info->setEnabled(QtDebugMsg, true);           //valszeg nem mindenhova QtDebugMsg-ot kell írni QtMsgType-nak
    warning->setEnabled(QtDebugMsg, true);
    critical->setEnabled(QtDebugMsg, true);
    if (debug->isEnabled(QtDebugMsg)) {
      qDebug() << "PLEASE";
    }
  }
  else if (qstrcmp(category->categoryName(), "Info") == 0) {
    debug->setEnabled(QtDebugMsg, false);
    info->setEnabled(QtDebugMsg, true);
    warning->setEnabled(QtDebugMsg, true);
    critical->setEnabled(QtDebugMsg, true);
  }
  else if (qstrcmp(category->categoryName(), "Warning") == 0) {
    debug->setEnabled(QtDebugMsg, false);
    info->setEnabled(QtDebugMsg, false);
    warning->setEnabled(QtDebugMsg, true);
    critical->setEnabled(QtDebugMsg, true);
  }
  else if (qstrcmp(category->categoryName(), "Critical") == 0) {
    debug->setEnabled(QtDebugMsg, false);
    info->setEnabled(QtDebugMsg, false);
    warning->setEnabled(QtDebugMsg, false);
    critical->setEnabled(QtDebugMsg, true);
    qDebug() << "eljutottam ide is ";
  }
}

Logger::~Logger() {}

QLoggingCategory* Logger::getDebugCategory() {
  return debug;
}

QLoggingCategory* Logger::getInfoCategory() {
  return info;
}

QLoggingCategory* Logger::getWarningCategory() {
  return warning;
}

QLoggingCategory* Logger::getCriticalCategory() {
  return critical;
}
