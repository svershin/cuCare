#include <QtCore/QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    std::cout << "Hello, Server!\n";

    return a.exec();
}
