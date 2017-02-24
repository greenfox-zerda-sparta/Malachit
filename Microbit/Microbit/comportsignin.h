#pragma once
#include <QWidget>
#include <QStringList>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QSerialPort>
#include <QSerialPortInfo>

class ComPortSignIn : public QWidget {
  Q_OBJECT

public:
  ComPortSignIn(QWidget * parent = Q_NULLPTR);
  void createLabel();
  void createDropdownList();
  void createConnectButton();

signals:
  void comportNameSelected(QString);

private:
  QComboBox* dropdownList;
  QPushButton* connectButton;
  QStringList comPorts;
  QVector<QString> m_Portnames;

private slots:
  void onConnectButtonClicked();
};
