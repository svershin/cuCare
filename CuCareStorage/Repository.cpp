#include "Repository.h"
#include "Sqlite3Database.h"

Repository::Repository()
    : db (NULL),
      errorText (""),
      rModel ()
{
    cout << "Creating repository." << endl;

    db = new Sqlite3Database();

    bool firstTimeRun = !rModel.dbexists(db);

    int timeout = 0;
    bool success = false;
    while(timeout < 30)
    {
        if(db->open())
        {
            success = true;
            break;
        }
        sleep(1);
        timeout++;
    }
    if(!success)
        throw "Connection to db timed out.";

    if(firstTimeRun)
        rModel.createDb(db);
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
    instantiate(queryResult, pResults, sObj);
    return true;
}

bool Repository::runAudit(int day, int month, int year)
{
    return db->command(rModel.getAuditCommand(day, month, year));
}

bool Repository::insertStatement(StorageObject sObj)
{
    stringstream statement;
    stringstream valueBracket;
    statement << "INSERT INTO " << sObj.getTable() << "(" << sObj.getIdName();
    valueBracket << "(NULL";
    map<string, string> *values = sObj.getValues();
    values->erase(sObj.getIdName());
    for(map<string, string>::iterator it = values->begin(); it != values->end(); it++)
    {
        statement << ", " << it->first;
        valueBracket << ", '" << it->second << "'";
    }
    statement << ") VALUES ";
    valueBracket << ")";
    statement << valueBracket.str() << ";";

    string command = statement.str();
    cout << command << endl;
    return db->command(command);
}

bool Repository::updateStatement(StorageObject sObj)
{
    stringstream statement;
    statement << "UPDATE " << sObj.getTable() << " SET ";
    bool firstvalue = true;
    map<string, string> *values = sObj.getValues();
    string idValue = (*values)[sObj.getIdName()];
    values->erase(sObj.getIdName());
    for(map<string, string>::iterator it = values->begin(); it != values->end(); it++)
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
    cout << command << endl;
    return db->command(command);
}

bool Repository::selectStatement(StorageObject sObj, QueryResult *&results)
{
    //Normally SELECT * is a bad idea, but in this case we don't know what sort of data we're working with
    //Because our storage object only contains fields we want to search by, we don't have a full list of the columns we need
    //So we get all the columns and store their names, which are the same as the names of the properties in the objects we're storing
    //The column names will be in the QueryResult when it comes back.

    stringstream statement;
    statement << "SELECT * FROM " << sObj.getTable() << " WHERE ";
    bool firstvalue = true;
    map<string, string> *values = sObj.getValues();
    for(map<string, string>::iterator it = values->begin(); it != values->end(); it++)
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

void Repository::instantiate(QueryResult *pResults, list<StorageObject> *pObjects, StorageObject pullObject)
{
    if(!(pResults->numRows() > 0))
        return;
    map<string, string> values;
    do
    {
        for(unsigned int i = 0; i < pResults->rowSize(); i++)
        {
            string name = pResults->getColName(i);
            string value = (*pResults)[i];
            values[name] = value;
        }
        StorageObject newObject(pullObject.getTable(), pullObject.getIdName(), values);
        pObjects->push_back(newObject);
    }
    while(pResults->nextRow());
}
