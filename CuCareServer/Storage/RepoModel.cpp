#include "RepoModel.h"

RepoModel::RepoModel()
{
}

string RepoModel::getAuditCommand()
{
//    string table = Followup::TABLE_NAME;
//    stringstream statement;
//    statement << "UPDATE " << table << " SET status = '" << Followup::FSTAT_OVERDUE
//              << "' WHERE ('" << today.getYear() << "' > dueyear OR ('" << today.getYear()
//              << "' = dueyear AND '" << today.getMonth() << "' > duemonth) OR ('" << today.getYear()
//              << "' = dueyear AND '" << today.getMonth() << "' = duemonth AND '" << today.getDay()
//              << "' > dueday)) AND status = '" << Followup::FSTAT_PENDING << "';";
    return "";
}

bool RepoModel::dbexists(Database db)
{
    ifstream dbfile(db->dbFilename.c_str());
    return dbfile; //Casts to true if file exists.
}

void RepoModel::createDb(Database db)
{
    ifstream createScript;
    createScript.open(createScriptFilename.c_str());
    if(!createScript)
        throw "Failed to find file.\n";

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

    //For the physicianid autoincrement, there needs to be a dummy entry with a physid of zero.
    if(!db->command("INSERT INTO physicians (username, physicianid) VALUES ('dummyentry', 0);"))
        throw "Error inserting dummy entry.";
}
