#include "matrix.h"

Matrix::Matrix(QWidget *parent)
  : QWidget(parent)
{
  m_MatrixGridLayout = new QGridLayout(this);
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
  for (unsigned int i = 0; i < Config::matrixSize; ++i) {
    for (unsigned int j = 0; j < Config::matrixSize; ++j) {
      QPushButton* button = createButton();
      m_Matrix[i].push_back(button);
      m_MatrixGridLayout->addWidget(button, i, j, Qt::AlignCenter);
    }
  }
}

QPushButton* Matrix::createButton()
{
  QPushButton* button = new QPushButton(this);
  button->setGeometry(QRect(this->width(), this->height(), Config::buttonSize, Config::buttonSize));
  button->setMinimumSize(Config::buttonSize, Config::buttonSize);
  button->setCheckable(true);
  button->setChecked(true);
  button->setStyleSheet("background-color: red");
  return button;
}