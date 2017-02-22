#pragma once
#include <QWidget>
#include <QStringList>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class ComPortSignIn : public QWidget {
  Q_OBJECT

public:
  ComPortSignIn(QWidget * parent = Q_NULLPTR);
  void createLabel();
  void createDropdownList();
  void createConnectButton();

private:
  QComboBox* dropdownList;
  QGridLayout* m_gridLayout;
  QPushButton* connectButton;

private slots:
  void onConnectButtonClicked();
};
