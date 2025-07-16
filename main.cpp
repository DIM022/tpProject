#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

     w.setWindowIcon(QIcon("C:/Users/Urano/Documents/Final/iconoLib.ico"));//SETEO DE ICONIO

    w.show();
    return a.exec();
}
