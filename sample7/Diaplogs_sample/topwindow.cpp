#include "topwindow.hpp"
#include "./ui_topwindow.h"
#include "stddialog.hpp"
#include <QFileDialog>
#include <QObject>
#include <qdir.h>

TopWindow::TopWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TopWindow) {
  ui->setupUi(this);
  auto stdDialogs = new StdDialog(ui->stddialogs);
  auto stdinDialogs = new StdInDialog(ui->stdindialogs);
  auto stdmsgDialogs = new StdMsgDialog(ui->stdmsgdialogs);
}

TopWindow::~TopWindow() { delete ui; }
