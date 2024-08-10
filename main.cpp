#include "clicker.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);
    Clicker w;
    w.show();
    extern long long VERSION;
    qDebug() << VERSION;
    return a.exec();
}
