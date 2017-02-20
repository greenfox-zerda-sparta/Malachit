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

public slots:
  void drawGraph();
  void realtimeDataSlot(Metrics);
};

#endif // ACCELEROMETERPLOT_H
