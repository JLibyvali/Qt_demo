#pragma once

#include "ui_topwindow.h"
#include <QObject>
#include <QWidget>
#include <endian.h>
#include <qcolor.h>
#include <qnamespace.h>
#include <qpalette.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class TopWindow;
}
QT_END_NAMESPACE

class ButtonGroup_Act final : public QObject {
  Q_OBJECT
public:
  explicit ButtonGroup_Act(Ui::TopWindow *_obj) : m_obj(_obj) {}
public slots:
  void on_alignL_clicked() { m_obj->lineEdit->setAlignment(Qt::AlignLeft); }
  void on_alignC_clicked() { m_obj->lineEdit->setAlignment(Qt::AlignCenter); }

  void on_alignR_clicked() { m_obj->lineEdit->setAlignment(Qt::AlignRight); }

  void on_bold_clicked(bool checked) {
    QFont font;
    font.setPointSize(20);
    font.setBold(checked);
    m_obj->lineEdit->setFont(font);
  }

  void on_italic_clicked(bool checked) {
    QFont font;
    font.setPointSize(20);
    font.setItalic(checked);
    m_obj->lineEdit->setFont(font);
  }

  void on_underline_clicked(bool checked) {
    QFont font;
    font.setPointSize(20);
    font.setUnderline(checked);
    m_obj->lineEdit->setFont(font);
  }

  void on_rdonly_chkbox(bool checked) { m_obj->lineEdit->setReadOnly(checked); }
  void on_enabled_chkbox(bool checked) { m_obj->lineEdit->setEnabled(checked); }
  void on_clcenabled_chkbox(bool checked) {
    m_obj->lineEdit->setClearButtonEnabled(checked);
  }

  void on_ratioblack_clicked() {
    auto plet = m_obj->lineEdit->palette();
    plet.setColor(QPalette::Text, Qt::black);
    m_obj->lineEdit->setPalette(plet);
  }

  void on_ratiored_clicked() {
    auto plet = m_obj->lineEdit->palette();
    plet.setColor(QPalette::Text, Qt::red);
    m_obj->lineEdit->setPalette(plet);
  }

  void on_ratioyellow_clicked() {
    auto plet = m_obj->lineEdit->palette();
    plet.setColor(QPalette::Text, Qt::yellow);
    m_obj->lineEdit->setPalette(plet);
  }

private:
  Ui::TopWindow *m_obj;
};