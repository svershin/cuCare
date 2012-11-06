#include <QtGui/QApplication>
#include "loginwindowdialog.h"
#include "mainwindow.h"
#include "MasterController/MasterController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MasterController *controller = new MasterController;

    LoginWindowDialog *loginWindow = new LoginWindowDialog(controller);
    MainWindow *mainWindow = new MainWindow(controller);


    if (loginWindow->exec() == 1) {
        mainWindow->show();
        return a.exec();
    }

    return 0;
}
