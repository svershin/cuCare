#include "Repository.h"

/*
NOTE: THIS IS A STUB, NOT A LEGITIMATE REPOSITORY
*/

//extern int testNumber;

Repository::Repository()
{}

bool Repository::create(StorageObject sObj, int &uid)
{

}
bool Repository::push(StorageObject sObj)
{

}

bool Repository::pull(StorageObject sObj, list<StorageObject> *&pResults)
{
    switch (0) //TODO: make variable
    {
        case 0:
        {

            return true;
        }
        case 1:
        {
            throw("test mess-up");
        }
        default:
        {
            return true;
        }
    }
}

bool Repository::runAudit(int day, int month, int year)
{
    switch (0) //TODO: make variable
    {
        case 0:
        {
            return true;
        }
        case 1:
        {
            return false;
        }
        default:
        {
            return true;
        }
    }
}
