#include "accelerometerplot.h"
#include <QTimer>

AccelerometerPlot::AccelerometerPlot(QWidget *parent)
  : QWidget(parent),
  m_Plot(new QCustomPlot(parent)),
  m_ReceiverService(new ReceiverService(parent)),
  m_TimeTicker(new QCPAxisTickerTime)
{
  m_Plot->addGraph(); 
  m_Plot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
  m_Plot->addGraph();
  m_Plot->graph(1)->setPen(QPen(QColor(255, 110, 40)));
  m_Plot->addGraph(); 
  m_Plot->graph(2)->setPen(QPen(QColor(40, 255, 110)));

  m_TimeTicker->setTimeFormat("%h:%m:%s");
  m_Plot->xAxis->setTicker(m_TimeTicker);
  m_Plot->axisRect()->setupFullAxesBox();
  m_Plot->yAxis->setRange(-1.2, 1.2);

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(m_Plot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_Plot->xAxis2, SLOT(setRange(QCPRange)));
  connect(m_Plot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_Plot->yAxis2, SLOT(setRange(QCPRange)));

  connect(m_ReceiverService.data(), SIGNAL(metricsReceived(Metrics)), this, SLOT(realtimeDataSlot(Metrics)));
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

void AccelerometerPlot::realtimeDataSlot(Metrics metrics)
{
  static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed() / 1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  if (key - lastPointKey > 0.002) // at most add point every 2 ms
  {
    m_Plot->graph(0)->addData(key, metrics.accelerometerVectors[0] / 100.0);
    m_Plot->graph(1)->addData(key, metrics.accelerometerVectors[1] / 100.0);
    m_Plot->graph(2)->addData(key, metrics.accelerometerVectors[2] / 100.0);

    // rescale value (vertical) axis to fit the current data:
    m_Plot->graph(0)->rescaleValueAxis(true);
    m_Plot->graph(1)->rescaleValueAxis(true);
    m_Plot->graph(2)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  m_Plot->xAxis->setRange(key, 8, Qt::AlignRight);
  m_Plot->replot();

}
