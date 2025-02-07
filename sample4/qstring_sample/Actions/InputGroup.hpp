#pragma once

#include "ui_TopWindow.h"
#include <QDebug>
#include <QObject>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TopWindow;
}
QT_END_NAMESPACE

class InputGroup_Act final : public QObject {
  Q_OBJECT
public:
  explicit InputGroup_Act(Ui::TopWindow *_obj) : m_obj(_obj) {}

public slots:
  void on_strunicode_clicked() {

    auto str_text = m_obj->str_linedit->text();
    if (str_text.isEmpty())
      return;

    m_obj->display_result->setReadOnly(true);
    m_obj->display_result->clearHistory();

    // Convert every char
    for (auto &ch : str_text) {
      char16_t uniCode = ch.unicode();
      QString msg = "[" + QString(ch) + "]" +
                    QString::asprintf("\t Unicode value = 0x%X", uniCode);
      m_obj->display_result->append(msg);
    }
  }

  void on_charphbton_clicked() {
    auto text = m_obj->char_linedit->text();
    if (text.isEmpty())
      return;

    auto ch = text[0];
    QString msg = "[" + QString(ch) + "]" +
                  QString::asprintf("\t Unicode value = 0x%X", ch.unicode());
    m_obj->display_result->append(msg);

    m_obj->isdigit->setChecked(ch.isDigit());
    m_obj->isletter->setChecked(ch.isLetter());
    m_obj->isletter_number->setChecked(ch.isLetterOrNumber());
    m_obj->islower->setChecked(ch.isLower());
    m_obj->ismark->setChecked(ch.isMark());
    m_obj->ispunct->setChecked(ch.isPunct());
    m_obj->issymbol->setChecked(ch.isSymbol());
    m_obj->isspace->setChecked(ch.isSpace());
  }

private:
  Ui::TopWindow *m_obj;
};