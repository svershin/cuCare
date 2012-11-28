#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QtCore>
#include "StorageObject.h"

/*
NOTE: THIS IS A STUB, NOT A LEGITIMATE REPOSITORY
*/

class Repository
{
public:
    Repository();

    bool create(StorageObject sObj, int &uid);
    bool push(StorageObject sObj);
    bool pull(StorageObject sObj, list<StorageObject> *&pResults);
    bool runAudit(int day, int month, int year);
};

#endif // REPOSITORY_H
