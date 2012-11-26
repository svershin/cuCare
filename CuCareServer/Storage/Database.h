#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "sqlite3.h"
#include "QueryResult.h"

using namespace std;

class Database
{
public:
    Database();
    virtual ~Database();

    virtual bool open() = 0;

    //For issuing sql statements which do not return results
    virtual bool command(const string query) = 0;

    //For issuing sql statements which do return results
    virtual bool query(const string query, QueryResult*& pOutResults) = 0;

    virtual int lastUid() = 0;

    string getErrorText();
    const string dbFilename;

    virtual bool close();

protected:
    bool connected;
    string errorText;
};

#endif
