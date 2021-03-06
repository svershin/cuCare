#ifndef SQLITE3DATABASE_H
#define SQLITE3DATABASE_H

#include <string>
#include <vector>
#include "Database.h"

using namespace std;

class Sqlite3Database : public Database
{
public:
    Sqlite3Database();

    bool open();

    //For issuing sql statements which do not return results
    bool command(const string query);

    //For issuing sql statements which do return results
    bool query(const string query, QueryResult*& pOutResults);

    int lastUid();

    bool close();

private:
    bool errorCheck();
    sqlite3 *pDb;
};

#endif
