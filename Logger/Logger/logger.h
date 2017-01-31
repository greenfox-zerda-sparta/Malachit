#pragma once
#include <QProcessEnvironment>

class Logger {
private:
  QProcessEnvironment processEnvironment;
  // QLoggingCategory::CategoryFilter oldCategoryFilter;
public:
  Logger(QString category);
  QLoggingCategory* debug;
  QLoggingCategory* info;
  QLoggingCategory* warning;
  QLoggingCategory* critical;
  ~Logger();
  void myCategoryFilter(QLoggingCategory *category);
  QLoggingCategory* getDebugCategory();
  QLoggingCategory* getInfoCategory();
  QLoggingCategory* getWarningCategory();
  QLoggingCategory* getCriticalCategory();
};