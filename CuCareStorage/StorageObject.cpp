#include "StorageObject.h"

StorageObject::StorageObject(string tableParam)
    : table (tableParam),
      idName (""),
      values ()
{
}

StorageObject::StorageObject(string tableParam, string idNameParam, map<string, string> valueParam)
    : table (tableParam),
      idName (idNameParam),
      values (valueParam)
{
}

string StorageObject::getTable() { return table; }

map<string, string>* StorageObject::getValues() { return &values; }

string StorageObject::getIdName() { return idName; }
void StorageObject::setIdName(string value) { idName = value; }
