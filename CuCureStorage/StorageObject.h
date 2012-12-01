#ifndef STORAGEOBJECT_H
#define STORAGEOBJECT_H

#include <string>
#include <map>

using namespace std;

class StorageObject
{
public:
    StorageObject(string tableParam);
    StorageObject(string tableParam, string idNameParam, map<string, string> valueParam);

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
