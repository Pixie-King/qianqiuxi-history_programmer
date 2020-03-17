#include "mainwindow.h"
#include "mymainscene.h"
#include <QApplication>

int whichone=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainScene w;
    w.show();

    return a.exec();
}
