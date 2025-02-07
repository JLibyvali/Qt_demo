#ifndef STDDIALOG_HPP
#define STDDIALOG_HPP

#include <QGroupBox>
#include <QObject>
#include <QWidget>


class StdDialog : public QObject {
  Q_OBJECT
public:
  // Detail: https://doc.qt.io/qt-6/qfiledialog.html#details
  explicit StdDialog(QGroupBox *parent = nullptr);

private:
  QGroupBox *m_obj;
};

class StdInDialog : public QObject {
  Q_OBJECT
public:
  explicit StdInDialog(QGroupBox *parent = nullptr)
      : QObject(parent), m_obj(parent) {}

private:
  QGroupBox *m_obj;
};

class StdMsgDialog : public QObject {
  Q_OBJECT
public:
  explicit StdMsgDialog(QGroupBox *parent = nullptr)
      : QObject(parent), m_obj(parent) {}

private:
  QGroupBox *m_obj;
};
#endif // STDDIALOG_HPP
