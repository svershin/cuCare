#ifndef STORAGEOBJECT_H
#define STORAGEOBJECT_H

#include <string>
#include <map>
#include <list>

using namespace std;

class StorageObject
{
public:
    StorageObject(string, string, map<string, string>);


    map<string, string>& getValues();
    string getTable();

    string getIdName();
    void setIdName(string value);

private:
    string table;
    string idName;
    map<string, string> values;
};

#endif // STORAGEOBJECT_H
