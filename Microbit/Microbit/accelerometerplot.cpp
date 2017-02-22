#include "accelerometerplot.h"
#include <QTimer>

AccelerometerPlot::AccelerometerPlot(QWidget *parent)
  : QWidget(parent),
  m_Plot(new QCustomPlot(parent)),
  m_ReceiverService(new ReceiverService(parent)),
  m_TimeTicker(new QCPAxisTickerTime)
{
  addGraphs();
  setGraphProperties();
  setupConnections();
}

void AccelerometerPlot::realtimeDataSlot(Metrics metrics)
{
  static QTime time(QTime::currentTime());
  double key = time.elapsed() / 1000.0;
  static double lastPointKey = 0;
  if (key - lastPointKey > Config::minTimeElapsed)
  {
    addDataPoints(key, metrics);
    lastPointKey = key;
  }
  m_Plot->xAxis->setRange(key, Config::rateSize, Qt::AlignRight);
  m_Plot->replot();
}

void AccelerometerPlot::addGraphs() 
{
  for (int i = 0; i < Config::colors.size(); ++i) {
    m_Plot->addGraph();
    m_Plot->graph(i)->setPen(QPen(Config::colors[i]));
  }
}

void AccelerometerPlot::setGraphProperties()
{
  m_TimeTicker->setTimeFormat("%h:%m:%s");
  m_Plot->xAxis->setTicker(m_TimeTicker);
  m_Plot->axisRect()->setupFullAxesBox();
}

void AccelerometerPlot::setupConnections() 
{
  connect(m_Plot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_Plot->xAxis2, SLOT(setRange(QCPRange)));
  connect(m_Plot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_Plot->yAxis2, SLOT(setRange(QCPRange)));
  connect(m_ReceiverService.data(), SIGNAL(metricsReceived(Metrics)), this, SLOT(realtimeDataSlot(Metrics)));
}

void AccelerometerPlot::paintEvent(QPaintEvent * e)
{
  m_Plot->setMinimumHeight(this->height());
  m_Plot->setMinimumWidth(this->width());
}

void AccelerometerPlot::addDataPoints(double key, Metrics metrics)
{
  for (int i = 0; i < metrics.accelerometerVectors.size(); ++i) {
    m_Plot->graph(i)->addData(key, metrics.accelerometerVectors[i]);
    m_Plot->graph(i)->rescaleValueAxis(true);
  }
}
