#include "Repository.h"

Repository::Repository()
    : db (NULL),
      errorText ("")
{
    //instantiate db
}

Repository::~Repository()
{
    db->close();
    delete db;
}

bool Repository::create(StorageObject sObj, int &uid)
{
    if(!insertStatement(sObj))
        return false;
    uid = db->lastUid();
    return true;
}

bool Repository::push(StorageObject sObj)
{
    return updateStatement(sObj);
}

bool Repository::pull(StorageObject sObj, list<StorageObject> *&pResults)
{
    QueryResult *queryResult = NULL;
    if(!selectStatement(sObj, queryResult))
        return false;
    pResults = new list<StorageObject>();
    //instantiate(queryResult, pResults);
    return true;
}

bool Repository::runAudit(Date today)
{
    //TODO: Break this out into another object, so that repo doesn't depend on the model at all.
//    string table = Followup::TABLE_NAME;
//    stringstream statement;
//    statement << "UPDATE " << table << " SET status = '" << Followup::FSTAT_OVERDUE
//              << "' WHERE ('" << today.getYear() << "' > dueyear OR ('" << today.getYear()
//              << "' = dueyear AND '" << today.getMonth() << "' > duemonth) OR ('" << today.getYear()
//              << "' = dueyear AND '" << today.getMonth() << "' = duemonth AND '" << today.getDay()
//              << "' > dueday)) AND status = '" << Followup::FSTAT_PENDING << "';";
//    return db->command(statement.str());
    return false;
}

bool Repository::insertStatement(StorageObject sObj)
{
    stringstream statement;
    stringstream valueBracket;
    statement << "INSERT INTO " << sObj.getTable() << "(" << sObj.getIdName();
    valueBracket << "(NULL";
    map<string, string> values = sObj.getValues();
    values.erase(sObj.getIdName());
    for(map<string, string>::iterator it = values.begin(); it != values.end(); it++)
    {
        statement << ", " << it->first;
        valueBracket << ", '" << it->second << "'";
    }
    statement << ") VALUES ";
    valueBracket << ")";
    statement << valueBracket.str() << ";";

    string command = statement.str();
    return db->command(command);
}

bool Repository::updateStatement(StorageObject sObj)
{
    stringstream statement;
    statement << "UPDATE " << sObj.getTable() << " SET ";
    bool firstvalue = true;
    map<string, string> values = sObj.getValues();
    string idValue = values[sObj.getIdName()];
    values.erase(sObj.getIdName());
    for(map<string, string>::iterator it = values.begin(); it != values.end(); it++)
    {
        if(firstvalue)
        {
            firstvalue = false;
            statement << it->first << " = '" << it->second << "'";
        }
        else
            statement << ", " << it->first << " = '" << it->second << "'";
    }
    statement << " WHERE " << sObj.getIdName() << " = '" << idValue << "';";

    string command = statement.str();
    return db->command(command);
}

bool Repository::selectStatement(StorageObject sObj, QueryResult *&results)
{
    stringstream statement;
    statement << "SELECT * FROM " << sObj.getTable() << " WHERE ";
    bool firstvalue = true;
    map<string, string> values = sObj.getValues();
    for(map<string, string>::iterator it = values.begin(); it != values.end(); it++)
    {
        if(firstvalue)
        {
            firstvalue = false;
            statement << it->first << " = '" << it->second << "'";
        }
        else
            statement << " AND " << it->first << " = '" << it->second << "'";
    }
    statement << ";";

    string query = statement.str();
    return db->query(query, results);
}





