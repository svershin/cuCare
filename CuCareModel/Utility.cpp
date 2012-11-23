#include "utility.h"

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
