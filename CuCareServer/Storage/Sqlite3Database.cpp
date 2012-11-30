#include "Sqlite3Database.h"
#include <iostream>
#include <stdlib.h>


Sqlite3Database::Sqlite3Database()
    : pDb (NULL)
{
}

bool Sqlite3Database::open()
{
    if(connected)
        return true;

    if(sqlite3_open(dbFilename.c_str(), &pDb) == SQLITE_OK)
        return connected = true;

    close();    //If there's an error, we still have to close the connection
    return false;
}

int Sqlite3Database::lastUid()
{
    return sqlite3_last_insert_rowid(pDb);
}

bool Sqlite3Database::errorCheck()
{
    int errcode = sqlite3_errcode(pDb);
    if(SQLITE_OK != errcode && SQLITE_DONE != errcode)
    {
        errorText = sqlite3_errmsg(pDb);
        return false;
    }
    errorText = "";
    return true;
}

bool Sqlite3Database::command(string query)
{
    if(!connected)
        return false;

    sqlite3_stmt *pStatement;

    if(sqlite3_prepare_v2(pDb, query.c_str(), -1, &pStatement, 0) == SQLITE_OK)
    {
        sqlite3_step(pStatement);
        sqlite3_finalize(pStatement);
    }

    return errorCheck();
}

bool Sqlite3Database::query(string query, QueryResult*& pOutResults)
{
    if(!connected)
        return false;

    sqlite3_stmt *pStatement;

    //This data will be used to create a QueryResult
    vector< vector <string>* >* pRows = new vector< vector <string>* >();
    map<int, string>* pColNames = new map<int, string>();

    //If nothing goes wrong with the query, we get SQLITE_OK
    if(sqlite3_prepare_v2(pDb, query.c_str(), -1, &pStatement, 0) == SQLITE_OK)
    {
        int numCols = sqlite3_column_count(pStatement);

        //Get the column names
        for(int index = 0; index < numCols; index++)
            (*pColNames)[index] = sqlite3_column_name(pStatement, index);

        //Go through the rows
        while(sqlite3_step(pStatement) == SQLITE_ROW)
        {
            vector<string>* pCols = new vector<string>();

            //Go through each row column by column and get the data
            for(int col = 0; col < numCols; col++)
            {
                char* coltext = (char*)sqlite3_column_text(pStatement, col);
                pCols->push_back(coltext == NULL ? "0" : coltext);
            }

            pRows->push_back(pCols);
        }
    }

    pOutResults = new QueryResult(pRows, pColNames);

    return errorCheck();
}

bool Sqlite3Database::close()
{
    if(sqlite3_close(pDb) == SQLITE_OK)
    {
        connected = false;
        return true;
    }
    return false;
}
