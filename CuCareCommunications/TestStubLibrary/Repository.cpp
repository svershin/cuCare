#include "Repository.h"

/*
NOTE: THIS IS A STUB, NOT A LEGITIMATE REPOSITORY
*/

extern int testNumber;

Repository::Repository() {}

bool Repository::create(StorageObject sObj, int &uid)
{
    switch (testNumber)
    {
        case 0:
        {
            uid = 654321;
            return true;
        }
        case 1:
        {
            throw(string("test create mess-up"));
        }
        default:
        {
            throw(string("default create mess-up"));
        }
    }
}
bool Repository::push(StorageObject sObj)
{
    switch (testNumber)
    {
        case 0:
        {
            return true;
        }
        case 1:
        {
            throw(string("test push mess-up"));
        }
        default:
        {
            throw(string("default push mess-up"));
        }
    }
}

bool Repository::pull(StorageObject sObj, list<StorageObject> *&pResults)
{
    switch (testNumber)
    {
        case 0:
        {
            map<string, string> map1;
            map<string, string> map2;

            map1["Name"] = "John";
            map1["Other Info"] = "Stuff";

            map2["Name"] = "Sandwich";
            map2["Other Info"] = "Something";

            pResults = new list<StorageObject>;
            pResults->push_back(StorageObject("Patient", "Patient", map1));
            pResults->push_back(StorageObject("Patient", "Patient", map2));
            return true;
        }
        case 1:
        {
            throw(string("test pull mess-up"));
        }
        default:
        {
        throw(string("default pull mess-up"));
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
