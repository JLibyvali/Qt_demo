#include "stddialog.hpp"

#include <QDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QProgressDialog>
#include <QMessageBox>

// Standard Dialogs
StdDialog::StdDialog(QGroupBox *parent) : QObject(parent), m_obj(parent) {}
