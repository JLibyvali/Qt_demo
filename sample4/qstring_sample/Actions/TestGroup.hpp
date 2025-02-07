#pragma once

#include "ui_TopWindow.h"
#include <QObject>
#include <qhashfunctions.h>
#include <qobject.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class TopWindow;
}
QT_END_NAMESPACE

class TestGroup_Act final : public QObject {
  Q_OBJECT
public:
  explicit TestGroup_Act(Ui::TopWindow *_obj) : m_obj(_obj) {}

public slots:
  void on_2Latin_clicked() {
    m_obj->display_result->clear();

    QString str{"\" P \" Latin1 code:\n"};
    m_obj->display_result->append(str);

    QChar lp = QChar::fromLatin1('P');
    m_obj->display_result->append({lp});
  }

  void on_2Utf16_clicked() {
    m_obj->display_result->clear();

    QString str = "Hello,世界!";
    m_obj->display_result->append(str + '\n');
    str[0] = QChar(0x9752);
    str[1] = QChar::fromUcs2(0x5c9b);
    m_obj->display_result->append(
        "After construct QChar form UTF-16 code: " + str + '\n');
  }

  void on_Cmpbton_clicked() {
    m_obj->display_result->clear();
    QString str = "Hello 湖南 和 北京";
    m_obj->display_result->append(str + '\n');

    QString info = "湖 -> 河, 北 -> 南";
    m_obj->display_result->append(info);

    auto Hu_code = info[0];
    auto He_code = info[5];
    auto Bei_code = info[8];
    auto Nan_code = info[13];

    for (auto &ch : str) {
      if (ch == Hu_code) {
        ch = He_code;
      } else if (ch == Bei_code) {
        ch = Nan_code;
      }
    }

    m_obj->display_result->append("After Converted: " + str + '\n');
  }
  void on_Clear_clicked() { m_obj->display_result->clear(); }

private:
  Ui::TopWindow *m_obj;
};