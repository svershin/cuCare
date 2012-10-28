#include "Repository.h"
#include <stdexcept>

Repository::Repository()
    : db (NULL),
      createScriptFilename ("dbcreate.sql")
{
    bool firstTimeRun = false;

    db = new Database();

    if(!databaseExists())
        firstTimeRun = true;

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
        createSchema();
}

Repository::~Repository()
{
    delete db;
}

void Repository::createSchema()
{
    ifstream createScript;
    createScript.open(createScriptFilename.c_str());

    if(createScript.is_open())
    {
        while(createScript.good())
        {
            string line;
            getline(createScript, line);
            if(!db->command(line))
            {
                createScript.close(); //Have to close the file, even if something went wrong
                throw "Error creating database - " + db->getErrorText();
            }
        }
    }
    else throw "Error opening " + createScriptFilename;
}

bool Repository::databaseExists()
{
    ifstream dbfile(db->dbFilename.c_str());
    return dbfile; //Casts to true if file exists.
}
