#include "mainwindow.h"
#include "ajout.h"
#include "annoncewindow.h"
#include <QApplication>
#include <QDomDocument>
#include <QtXml>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
