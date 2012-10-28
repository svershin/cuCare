#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Database.h"
#include <iostream>
#include <fstream>

class Repository
{
public:
    Repository();

    ~Repository();

private:
    Database* db;

    void createSchema();
    bool databaseExists();

    const string createScriptFilename;
};

#endif // REPOSITORY_H
