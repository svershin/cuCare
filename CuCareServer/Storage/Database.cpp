#include "Database.h"
#include <iostream>
#include <stdlib.h>
#include "sqlite3.h"
#include "QueryResult.h"

Database::Database()
    : dbFilename ("cucare.db"),
      connected (false),
      errorText ("")
{
}

Database::~Database()
{
    if(connected)
        close();
}

string Database::getErrorText()
{
    return errorText;
}

bool Database::close() { return false; }
