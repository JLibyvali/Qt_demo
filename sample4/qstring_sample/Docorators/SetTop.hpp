#pragma once

#include "ui_TopWindow.h"
#include <QWidget>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class TopWindow;
}
QT_END_NAMESPACE

class SetMainWindow final {
public:
  explicit SetMainWindow(QWidget *_window) : m_window(_window) {}
  void operator()(void) {
    m_window->setWindowTitle("QString Sample");
    m_window->activateWindow();
    m_window->setWindowOpacity(0.50000);
  }

private:
  QWidget *m_window;
};
