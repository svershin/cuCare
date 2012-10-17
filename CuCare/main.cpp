#include <QtGui/QApplication>
#include "cucare.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CuCare w;
    w.show();
    
    return a.exec();
}
