#include <QtCore/QCoreApplication>
#include <iostream>
#include "Tests.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Program starts.\n";
    //Tests::databaseExample();
    Tests::repositorySetupTest();

    return a.exec();
}


