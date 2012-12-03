#include "Utility.h"
#include <execinfo.h>

Utility::Utility()
{
}

string Utility::itos(int value)
{
    stringstream integer;
    integer << value;
    return integer.str();
}

int Utility::stoi(string value)
{
    int retval;
    stringstream integer(value);
    integer >> retval;
    return retval;
}

void Utility::printStackTrace()
{
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    backtrace_symbols_fd(array, size, 2);
}
