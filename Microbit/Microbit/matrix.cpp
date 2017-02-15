#include "matrix.h"

Matrix::Matrix(QWidget *parent)
  : QWidget(parent)
{
  m_Margin = (double)this->width() * Config::proportionOfMargin;
  m_Matrix.resize(Config::matrixSize);
  m_HorizontalLayouts.resize(Config::matrixSize);
  m_VerticalLayout = new QVBoxLayout(this);
  m_VerticalLayout->setMargin(m_Margin);
  fillMatrix();
  m_SenderService = new SenderService(this);
  for (int i = 0; i < Config::matrixSize; ++i) {
    for (int j = 0; j < Config::matrixSize; ++j) {
      connect(m_Matrix[i][j], SIGNAL(stateChanged(int, int)), m_SenderService, SLOT(send(int, int)));
    }
  }
}

QVector<QVector<LedLight*>> Matrix::getMatrix()
{
  return m_Matrix;
}

void Matrix::fillMatrix()
{
  for (unsigned int i = 0; i < Config::matrixSize; ++i)
  {
    m_HorizontalLayouts[i] = new QHBoxLayout;
    for (unsigned int j = 0; j < Config::matrixSize; ++j)
    {
      LedLight* button = createButton(i, j);
      m_Matrix[i].push_back(button);
      m_HorizontalLayouts[i]->addWidget(button);
    }
    m_VerticalLayout->addLayout(m_HorizontalLayouts[i]);
  }
}

LedLight* Matrix::createButton(int i, int j)
{
  LedLight* button = new LedLight(i, j);
  button->setGeometry(QRect(this->width(), this->height(), Config::buttonSize, Config::buttonSize));
  button->setMinimumSize(Config::buttonSize * m_Margin, Config::buttonSize* m_Margin);
  button->setCheckable(true);
  button->setChecked(true);
  button->setStyleSheet("background-color: red");
  return button;
}
