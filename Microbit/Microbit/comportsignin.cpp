﻿#include "comportsignin.h"

ComPortSignIn::ComPortSignIn(QWidget * parent) : QWidget(parent)
{
  QVector<QString> portnames;
  foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
    portnames.push_back(serialPortInfo.portName());
  }
  m_Portnames = portnames;
  m_gridLayout = new QGridLayout;
  createLabel();
  createDropdownList();
  createConnectButton();
  connect(connectButton, SIGNAL(clicked()), this, SLOT(onConnectButtonClicked()));
  
}

void ComPortSignIn::createLabel()
{
  QLabel* signin = new QLabel(this);
  signin->setGeometry(100, 20, 200, 25);
  signin->setText("Please select your desired COM port:");
}

void ComPortSignIn::createDropdownList()
{
  dropdownList = new QComboBox(this);
  //QStringList comPorts;
  for (unsigned int i = 0; i < m_Portnames.size(); ++i)
  {
    comPorts << m_Portnames[i];
  }
  std::sort(comPorts.begin(), comPorts.end());
  //comPorts << "COM1" << "COM2" << "COM3" << "COM4" << "COM5" << "COM6" << "COM7" << "COM8" << "COM9" << "COM10";
  dropdownList->addItems(comPorts);
  dropdownList->setSizeAdjustPolicy(QComboBox::AdjustToContents);
  dropdownList->setGeometry(160, 50, 60, 25);
  //m_gridLayout->addWidget(dropdownList, 0, 0, Qt::AlignCenter);
}

void ComPortSignIn::createConnectButton()
{
  connectButton = new QPushButton(this);
  connectButton->setText("Connect");
  connectButton->setGeometry(160, 80, 60, 25);
  m_gridLayout->addWidget(connectButton, 1, 1, Qt::AlignLeft);
}

void ComPortSignIn::onConnectButtonClicked()
{
  int portIndex = dropdownList->currentIndex();
  emit comportNameSelected(comPorts[portIndex]);
}