#include "accelerometerplot.h"
#include <QTimer>

AccelerometerPlot::AccelerometerPlot(QWidget *parent)
  : QWidget(parent)
{
  m_Plot = new QCustomPlot(this);
  m_ReceiverService = new ReceiverService(this);

  //connect(m_ReceiverService, SIGNAL(metricsReceived(Metrics)), this, SLOT(drawGraph()));

  dataTimer = new QTimer();

  m_Plot->addGraph(); // blue line
  m_Plot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
  m_Plot->addGraph(); // red line
  m_Plot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  m_Plot->xAxis->setTicker(timeTicker);
  m_Plot->axisRect()->setupFullAxesBox();
  m_Plot->yAxis->setRange(-1.2, 1.2);

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(m_Plot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_Plot->xAxis2, SLOT(setRange(QCPRange)));
  connect(m_Plot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_Plot->yAxis2, SLOT(setRange(QCPRange)));
  
  connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  dataTimer->start(0);
}

void AccelerometerPlot::drawGraph()
{
  m_Plot->addGraph();
}

void AccelerometerPlot::paintEvent(QPaintEvent * e)
{
  m_Plot->setMinimumHeight(this->height());
  m_Plot->setMinimumWidth(this->width());
}

void AccelerometerPlot::realtimeDataSlot()
{
  static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed() / 1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  if (key - lastPointKey > 0.002) // at most add point every 2 ms
  {
    m_Plot->graph(0)->addData(key, qSin(key));
    m_Plot->graph(1)->addData(key, qCos(key));
    // rescale value (vertical) axis to fit the current data:
    //m_Plot->graph(0)->rescaleValueAxis();
    //m_Plot->graph(1)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  m_Plot->xAxis->setRange(key, 5, Qt::AlignRight);
  m_Plot->replot();

}
