#include "RepoModel.h"
#include "../CuCareModel/Property.h"

RepoModel::RepoModel()
{
}

string RepoModel::getAuditCommand(int day, int month, int year)
{
    string table = Followup::TABLE_NAME;
    stringstream statement;
    statement << "UPDATE " << table << " SET status = '" << Followup::FSTAT_OVERDUE
              << "' WHERE ('" << year << "' > CAST (dueyear AS INTEGER) OR ('" << year
              << "' = CAST (dueyear AS INTEGER) AND '" << month << "' > CAST (duemonth AS INTEGER)) OR ('" << year
              << "' = CAST(dueyear AS INTEGER) AND '" << month << "' = CAST(duemonth AS INTEGER) AND '" << day
              << "' > CAST(dueday AS INTEGER))) AND status = '" << Followup::FSTAT_PENDING << "';";
    return statement.str();
}

bool RepoModel::dbexists(Database *db)
{
    ifstream dbfile(db->dbFilename.c_str());
    return dbfile; //Casts to true if file exists.
}

void RepoModel::createDb(Database *db)
{
    db->command(getUserTableCommand());
    db->command(getFollowupTableCommand());
    db->command(getConsultationTableCommand());
    db->command(getPatientTableCommand());
}

string RepoModel::getConsultationTableCommand()
{
    stringstream statement;
    Consultation dummy;
    list<Property*>* props = dummy.getProperties();
    bool first = true;
    statement << "CREATE TABLE " << Consultation::TABLE_NAME << "(";
    for(list<Property*>::iterator it = props->begin(); it != props->end(); it++)
    {
        string name = (*it)->getName();
        if(first)
        {
            if(name == "consultationid")
            {
                statement << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << name << " TEXT DEFAULT NULL";
            }
        }
        else
            if(name == "consultationid")
            {
                statement << ", " << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << ", " << name << " TEXT DEFAULT NULL";
            }
        first = false;
    }
    statement << ", " << OBJECT_TYPE_PROPERTY_NAME << " TEXT DEFAULT NULL";
    statement << ", " << PARENT_ID_PROPERTY_NAME << " TEXT DEFAULT NULL";
    statement << ");";
    return statement.str();
}

string RepoModel::getFollowupTableCommand()
{
    stringstream statement;
    Referral dummy;
    list<Property*>* props = dummy.getProperties();
    bool first = true;
    statement << "CREATE TABLE " << Followup::TABLE_NAME << "(";
    for(list<Property*>::iterator it = props->begin(); it != props->end(); it++)
    {
        string name = (*it)->getName();
        if(first)
        {
            if(name == "followupid")
            {
                statement << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << name << " TEXT DEFAULT NULL";
            }
        }
        else
            if(name == "followupid")
            {
                statement << ", " << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << ", " << name << " TEXT DEFAULT NULL";
            }
        first = false;
    }
    statement << ", nextconsultationid TEXT DEFAULT NULL"; //OH GOD WHY IS THIS SO UGLY
    statement << ", testtype TEXT DEFAULT NULL";
    statement << ", " << OBJECT_TYPE_PROPERTY_NAME << " TEXT DEFAULT NULL";
    statement << ", " << PARENT_ID_PROPERTY_NAME << " TEXT DEFAULT NULL";
    statement << ", medication TEXT DEFAULT NULL);";
    return statement.str();
}

string RepoModel::getPatientTableCommand()
{
    stringstream statement;
    Patient dummy;
    list<Property*>* props = dummy.getProperties();
    bool first = true;
    statement << "CREATE TABLE " << Patient::TABLE_NAME << "(";
    for(list<Property*>::iterator it = props->begin(); it != props->end(); it++)
    {
        string name = (*it)->getName();
        if(first)
        {
            if(name == "patientid")
            {
                statement << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << name << " TEXT DEFAULT NULL";
            }
        }
        else
            if(name == "patientid")
            {
                statement << ", " << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << ", " << name << " TEXT DEFAULT NULL";
            }
        first = false;
    }
    statement << ", " << OBJECT_TYPE_PROPERTY_NAME << " TEXT DEFAULT NULL";
    statement << ");";
    return statement.str();
}

string RepoModel::getUserTableCommand()
{
    stringstream statement;
    Physician dummy;
    list<Property*>* props = dummy.getProperties();
    bool first = true;
    statement << "CREATE TABLE " << Physician::TABLE_NAME << "(";
    for(list<Property*>::iterator it = props->begin(); it != props->end(); it++)
    {
        string name = (*it)->getName();
        if(first)
        {
            if(name == "userid")
            {
                statement << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << name << " TEXT DEFAULT NULL";
            }
        }
        else
            if(name == "userid")
            {
                statement << ", " << name << " INTEGER PRIMARY KEY";
            }
            else
            {
                statement << ", " << name << " TEXT DEFAULT NULL";
            }
        first = false;
    }
    statement << ", " << OBJECT_TYPE_PROPERTY_NAME << " TEXT DEFAULT NULL";
    statement << ", " << PARENT_ID_PROPERTY_NAME << " TEXT DEFAULT NULL";
    statement << ", UNIQUE (username));";
    return statement.str();
}
