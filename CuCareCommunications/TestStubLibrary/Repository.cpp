#include "Repository.h"
#include <iostream>

using namespace std;
/*
NOTE: THIS IS A STUB, NOT A LEGITIMATE REPOSITORY
*/

extern int testNumber;
extern void printStorageObject(StorageObject& store);

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
        case 2:
        {
            printStorageObject(sObj);
            uid = 654321;
            return true;
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
        case 2:
        {
            printStorageObject(sObj);
            return true;
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
        case 2:
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

        printStorageObject(sObj);
        return true;

        }
        default:
        {
        throw(string("default pull mess-up"));
        }
    }
}

bool Repository::runAudit(int day, int month, int year)
{



    switch (testNumber) //TODO: make variable
    {
        case 0:
        {
            return true;
        }
        case 1:
        {
            return false;
        }
        case 2:
        {
            cout << "Repository is running audit." << endl;
            return true;
        }
        default:
        {
            return true;
        }
    }
}
