#include "signin.h"

Signin::Signin(QDialog * parent) : QDialog(parent) {
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
  //connect(connectButton, SIGNAL(clicked()), this, SLOT(close()));
}

Signin::~Signin() {

}

void Signin::createLabel()
{
  QLabel* signin = new QLabel(this);
  signin->setGeometry(100, 20, 200, 25);
  signin->setText("Please select your desired COM port:");
}

void Signin::createDropdownList()
{
  dropdownList = new QComboBox(this);
  QStringList comPorts;
  for (unsigned int i = 0; i < m_Portnames.size(); ++i)
  {
    comPorts << m_Portnames[i];
  }
  std::sort(comPorts.begin(), comPorts.end());
  dropdownList->addItems(comPorts);
  dropdownList->setSizeAdjustPolicy(QComboBox::AdjustToContents);
  dropdownList->setGeometry(160, 50, 60, 25);
  //m_gridLayout->addWidget(dropdownList, 0, 0, Qt::AlignCenter);
}

void Signin::createConnectButton()
{
  connectButton = new QPushButton(this);
  connectButton->setText("Connect");
  connectButton->setGeometry(160, 80, 60, 25);
  m_gridLayout->addWidget(connectButton, 1, 1, Qt::AlignLeft);
}

void Signin::onConnectButtonClicked()
{
  canLaunchProgram = true;

}

bool Signin::isProgramLaunchable()
{
  return canLaunchProgram;
}