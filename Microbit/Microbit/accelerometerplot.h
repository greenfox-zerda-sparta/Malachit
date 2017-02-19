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

  QPointer<QTimer> dataTimer;

public slots:
  void drawGraph();
  void realtimeDataSlot();
};

#endif // ACCELEROMETERPLOT_H
