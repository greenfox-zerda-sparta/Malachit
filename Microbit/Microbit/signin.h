#pragma once
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QVector>
#include <QSerialPort>
#include <QSerialPortInfo>

class Signin : public QDialog {
  Q_OBJECT

public:
  Signin(QDialog * parent = Q_NULLPTR);
  
  ~Signin();
  void createLabel();
  void createDropdownList();
  void createConnectButton();
  bool isProgramLaunchable();

private:
  QVector<QString> m_Portnames;
  QComboBox* dropdownList;
  QPushButton* connectButton;
  QGridLayout* m_gridLayout;
  bool canLaunchProgram = false;

private slots:
  void onConnectButtonClicked();
};
