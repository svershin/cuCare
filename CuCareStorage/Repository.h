#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "StorageObject.h"
#include "Database.h"
#include "RepoModel.h"
#include <list>
#include <sstream>

using namespace std;

class Repository
{
public:
    Repository();

    ~Repository();

    bool create(StorageObject sObj, int &uid);
    bool push(StorageObject sObj);
    bool pull(StorageObject sObj, list<StorageObject> *&pResults);
    bool runAudit(int day, int month, int year);

    string getErrorText();
private:
    Database* db;
    string errorText;
    RepoModel rModel;

    bool insertStatement(StorageObject sObj);
    bool updateStatement(StorageObject sObj);
    bool selectStatement(StorageObject sObj, QueryResult *&results);

    void instantiate(QueryResult *results, list<StorageObject> *pObjects, StorageObject pullObject);
};

#endif // REPOSITORY_H
