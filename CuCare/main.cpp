#include <QtGui/QApplication>
#include "../CuCareModel/User.h"
#include "loginwindowdialog.h"
#include "patientselectdialog.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
