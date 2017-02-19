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
  QPointer<QCustomPlot> m_Plot;
  QPointer<ReceiverService> m_ReceiverService;

public slots:
  void drawGraph();
  void realtimeDataSlot(Metrics);
};

#endif // ACCELEROMETERPLOT_H
