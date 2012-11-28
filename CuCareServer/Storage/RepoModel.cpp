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
    //DO things with model classes to make tables
}
