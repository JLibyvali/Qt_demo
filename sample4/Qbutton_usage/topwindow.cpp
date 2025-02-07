#include "topwindow.hpp"
#include "./ui_topwindow.h"
#include <qobjectdefs.h>

// Set some Widget Property.
void buttons_properties(Ui::TopWindow *_obj) {
  // Align Buttons
  _obj->alignL_phbton->setAutoExclusive(true);
  _obj->alignC_phbton->setAutoExclusive(true);
  _obj->alignR_phbton->setAutoExclusive(true);
  _obj->alignL_phbton->setCheckable(false);
  _obj->alignC_phbton->setCheckable(false);
  _obj->alignR_phbton->setCheckable(false);
  _obj->alignL_phbton->setFlat(true);
  _obj->alignC_phbton->setFlat(true);
  _obj->alignR_phbton->setFlat(true);

  // Font style buttons
  _obj->bold_phbton->setAutoExclusive(false);
  _obj->italic_phbton->setAutoExclusive(false);
  _obj->underline_phbton->setAutoExclusive(false);
  _obj->bold_phbton->setCheckable(true);
  _obj->italic_phbton->setCheckable(true);
  _obj->underline_phbton->setCheckable(true);

  // Check box
  _obj->rdonly_chkbox->setTristate(false);
  _obj->enabled_chkbox->setTristate(false);
  _obj->clcbtonenabled_chkbox->setTristate(false);

  // Text Browser Content.
  _obj->lineEdit->clear();
  _obj->lineEdit->setText("Test Text, Hello World!\n");
}

TopWindow::TopWindow(QWidget *parent) : QWidget(parent), ui(new Ui::TopWindow) {
  ui->setupUi(this);
  buttons_properties(ui);

  // Connect Signals and Slots
  m_buttongroup_act = new ButtonGroup_Act(ui);

  // push buttons
  m_buttongroup_act->connect(ui->alignL_phbton, SIGNAL(clicked()),
                             SLOT(on_alignL_clicked()));
  m_buttongroup_act->connect(ui->alignC_phbton, SIGNAL(clicked()),
                             SLOT(on_alignC_clicked()));
  m_buttongroup_act->connect(ui->alignR_phbton, SIGNAL(clicked()),
                             SLOT(on_alignR_clicked()));
  m_buttongroup_act->connect(ui->bold_phbton, SIGNAL(clicked(bool)),
                             SLOT(on_bold_clicked(bool)));
  m_buttongroup_act->connect(ui->italic_phbton, SIGNAL(clicked(bool)),
                             SLOT(on_italic_clicked(bool)));
  m_buttongroup_act->connect(ui->underline_phbton, SIGNAL(clicked(bool)),
                             SLOT(on_underline_clicked(bool)));
  // check box
  m_buttongroup_act->connect(ui->rdonly_chkbox, SIGNAL(clicked(bool)),
                             SLOT(on_rdonly_chkbox(bool)));
  m_buttongroup_act->connect(ui->enabled_chkbox, SIGNAL(clicked(bool)),
                             SLOT(on_enabled_chkbox(bool)));
  m_buttongroup_act->connect(ui->clcbtonenabled_chkbox, SIGNAL(clicked(bool)),
                             SLOT(on_clcenabled_chkbox(bool)));

  // ratio push button
  m_buttongroup_act->connect(ui->black_ratiobton, SIGNAL(clicked()),
                             SLOT(on_ratioblack_clicked()));
  m_buttongroup_act->connect(ui->red_ratiobton, SIGNAL(clicked()),
                             SLOT(on_ratiored_clicked()));
  m_buttongroup_act->connect(ui->yellow_ratiobton, SIGNAL(clicked()),
                             SLOT(on_ratioyellow_clicked()));
}

TopWindow::~TopWindow() {
  delete ui;
  delete m_buttongroup_act;
}
