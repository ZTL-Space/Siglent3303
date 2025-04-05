#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // comment 2025-04-05

    // to be used by QSettings, determines the path where settings are stored
    a.setOrganizationName("ztl.space");
    a.setOrganizationDomain("ztl.space");
    a.setApplicationName("Siglent3303");

    MainWindow w;

    w.setWindowTitle( a.applicationName()+ " Testing" );

    w.show();
    return a.exec();
}

