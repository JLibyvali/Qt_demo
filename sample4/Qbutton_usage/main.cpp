#include "topwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TopWindow w;
    w.show();
    return a.exec();
}
