#ifndef TOPWINDOW_HPP
#define TOPWINDOW_HPP

#include "Actions/ButtonGroup.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TopWindow;
}
QT_END_NAMESPACE

class TopWindow : public QWidget {
  Q_OBJECT

public:
  TopWindow(QWidget *parent = nullptr);
  ~TopWindow();

private:
  Ui::TopWindow *ui;
  ButtonGroup_Act *m_buttongroup_act;
};
#endif // TOPWINDOW_HPP
