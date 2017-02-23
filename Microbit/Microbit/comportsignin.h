#pragma once
#include <QWidget>
#include <QStringList>
#include <QComboBox>
#include <QGridLayout>
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
  QGridLayout* m_gridLayout;
  QPushButton* connectButton;
  QStringList comPorts;
  QVector<QString> m_Portnames;

private slots:
  void onConnectButtonClicked();
};
