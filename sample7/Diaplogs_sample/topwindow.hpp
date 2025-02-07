#ifndef TOPWINDOW_HPP
#define TOPWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TopWindow;
}
QT_END_NAMESPACE

class TopWindow : public QMainWindow
{
    Q_OBJECT

public:
    TopWindow(QWidget *parent = nullptr);
    ~TopWindow();

private:
    Ui::TopWindow *ui;
};
#endif // TOPWINDOW_HPP
