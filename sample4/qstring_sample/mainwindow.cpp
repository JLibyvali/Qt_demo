#include "mainwindow.hpp"
#include "Actions/InputGroup.hpp"
#include "Actions/TestGroup.hpp"
#include "Docorators/SetTop.hpp"
#include "ui_TopWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::TopWindow) {

  ui->setupUi(this); // Set basic properties from Qt Designer.
  /**
   * @brief  Call Custom Class.
   *
   */
  SetMainWindow{this}();
  m_inputg_act = new InputGroup_Act(ui);
  m_testg_act = new TestGroup_Act(ui);

  m_inputg_act->connect(ui->strunicode_phbton, SIGNAL(clicked()),
                        SLOT(on_strunicode_clicked()));
  m_inputg_act->connect(ui->charfeat_phbton, SIGNAL(clicked()),
                        SLOT(on_charphbton_clicked()));

  m_testg_act->connect(ui->tolatin_phbton, SIGNAL(clicked()),
                       SLOT(on_2Latin_clicked()));
  m_testg_act->connect(ui->toutf16_phbton, SIGNAL(clicked()),
                       SLOT(on_2Utf16_clicked()));
  m_testg_act->connect(ui->cmpqch_phbton, SIGNAL(clicked()),
                       SLOT(on_Cmpbton_clicked()));
  m_testg_act->connect(ui->clcinput_phbton, SIGNAL(clicked()),
                       SLOT(on_Clear_clicked()));
}

MainWindow::~MainWindow() {
  delete ui;
  delete m_inputg_act;
  delete m_testg_act;
}
