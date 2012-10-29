#include <QtGui/QApplication>
#include "cucare.h"
#include "../CuCareModel/User.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CuCare w;
    w.show();

    User* newUser = new User("Yellow", "Newton", "Really", "Mr", Date(12,12,1991), ContactInfo("555-555-5555", "555-555-5555", "me@fake.com", "you@real.ca"),Address("Canada","Ottawa", "1268 Cobden", "", "K2C 3A2"),false);

    return a.exec();
}
