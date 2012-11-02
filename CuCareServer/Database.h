#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <sqlite3.h>
#include "QueryResult.h"

using namespace std;

class Database
{
public:
    Database();
    ~Database();

    bool open();

    //For issuing sql statements which do not return results
    bool command(const string query);

    //For issuing sql statements which do return results
    bool query(const string query, QueryResult*& pOutResults);

    int lastUid();

    string getErrorText();
    const string dbFilename;

    bool close();

private:
    bool errorCheck();

    string errorText;
    sqlite3 *pDb;
    bool connected;


};

#endif
