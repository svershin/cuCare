#include <QtGui/QApplication>
#include "../CuCareModel/User.h"
#include "loginwindowdialog.h"
#include "mainwindow.h"
#include "MasterController/MasterController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MasterController *controller = new MasterController();

    MainWindow *mainWindow = new MainWindow(controller);

    loginWindow->exec();

    return a.exec();
}
