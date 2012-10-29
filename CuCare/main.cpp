#include <QtGui/QApplication>
#include "../CuCareModel/User.h"
#include "loginwindowdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindowDialog w;
    w.show();

    return a.exec();
}
