#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>

#include "Actions/InputGroup.hpp"
#include "Actions/TestGroup.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class TopWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::TopWindow *ui;
  InputGroup_Act *m_inputg_act;
  TestGroup_Act *m_testg_act;
};
#endif // MAINWINDOW_HPP
