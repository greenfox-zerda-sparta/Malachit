#ifndef ACCELEROMETERPLOT_H
#define ACCELEROMETERPLOT_H

#include <QWidget>
#include "qcustomplot.h"
#include "receiverservice.h"

class AccelerometerPlot : public QWidget
{
  Q_OBJECT

public:
  AccelerometerPlot(QWidget *parent);
  void paintEvent(QPaintEvent* e);
private:
  QScopedPointer<QCustomPlot> m_Plot;
  QScopedPointer<ReceiverService> m_ReceiverService;
  QSharedPointer<QCPAxisTickerTime> m_TimeTicker;
  void addGraphs();
  void setGraphProperties();
  void setupConnections();
  void addDataPoints(double key, Metrics metrics);
public slots:
  void realtimeDataSlot(Metrics);
};

#endif // ACCELEROMETERPLOT_H
