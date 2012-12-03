#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <sstream>

using namespace std;

class Utility
{
public:
    Utility();
    virtual void abstract() = 0;

    static string itos(int value);
    static int stoi(string value);
    static void printStackTrace();
};

#endif // UTILITY_H
