#include <QtCore/QCoreApplication>
#include <iostream>
#include "Tests.h"
#include "../CuCareCommunications/Communications/requesthandler.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Program starts.\n";
    //Tests::databaseExample();
    //Tests::repositoryTest();

    Tests::requestHandlerTest();

    return a.exec();
}


