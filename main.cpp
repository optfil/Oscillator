#include "form.h"
#include "dynsystem.h"

#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{/*
    QApplication a(argc, argv);
    Form w;
    w.show();
    return a.exec();*/

    DynSystem sys(1.0, 0.0, 10.0, 1.0, 0.0, 0.0, 1.0e-3);

    qDebug() << sys.m() << sys.gamma() << sys.k();
    qDebug() << sys.t() << sys.x() << sys.v();
}
