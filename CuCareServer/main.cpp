#include <QtCore/QCoreApplication>
#include <iostream>
#include "Tests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Tests::DatabaseExample();

    return a.exec();
}


