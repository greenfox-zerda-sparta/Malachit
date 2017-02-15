#include "matrix.h"

Matrix::Matrix(QWidget *parent)
  : QWidget(parent)
{
  m_MatrixGridLayout = new QGridLayout(this);
  m_MatrixGridLayout->setHorizontalSpacing(1);
  m_MatrixGridLayout->setVerticalSpacing(1);
  m_MatrixGridLayout->setContentsMargins(0, 0, 0, 0);
  m_Margin = (double)this->width() * Config::proportionOfMargin;
  m_MatrixGridLayout->setMargin(m_Margin);
  m_MatrixGridLayout->setSizeConstraint(QGridLayout::SetDefaultConstraint);
  fillMatrix();
  m_SenderService = new SenderService(this);
  for (int i = 0; i < Config::matrixSize; ++i) {
    for (int j = 0; j < Config::matrixSize; ++j) {
      connect(m_Matrix[i][j], SIGNAL(clicked()), m_SenderService, SLOT(send()));
    }
  }
}

QVector<QVector<QPushButton*>> Matrix::getMatrix()
{
  return m_Matrix;
}

void Matrix::fillMatrix()
{
  m_Matrix.resize(Config::matrixSize);
  for (unsigned int i = 0; i < Config::matrixSize; ++i)
  {
    for (unsigned int j = 0; j < Config::matrixSize; ++j)
    {
      LedLight* button = createButton(i, j);
      m_Matrix[i].push_back(button);
      m_MatrixGridLayout->addWidget(button, i, j, Qt::AlignCenter);
    }
  }
}

LedLight* Matrix::createButton(int i, int j)
{
  LedLight* button = new LedLight(i, j);
  button->setGeometry(QRect(this->width(), this->height(), Config::buttonSize, Config::buttonSize));
  button->setMinimumSize(Config::buttonSize, Config::buttonSize);
  button->setCheckable(true);
  button->setChecked(true);
  button->setStyleSheet("background-color: red");
  return button;
}