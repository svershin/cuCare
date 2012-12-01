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
              << "' WHERE ('" << year << "' > dueyear OR ('" << year
              << "' = dueyear AND '" << month << "' > duemonth) OR ('" << year
              << "' = dueyear AND '" << month << "' = duemonth AND '" << day
              << "' > dueday)) AND status = '" << Followup::FSTAT_PENDING << "';";
    return "";
}

bool RepoModel::dbexists(Database *db)
{
    ifstream dbfile(db->dbFilename.c_str());
    cout << "Checking for db: " << (bool)dbfile << endl;
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
    statement << ");";
    return statement.str();
    //statement << ", FOREIGN KEY (physicianid) REFERENCES" << User::TABLE_NAME << "(physicianid));";
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
    statement << ", medication TEXT DEFAULT NULL);";
    return statement.str();
    //statement << ", FOREIGN KEY (physicianid) REFERENCES" << User::TABLE_NAME << "(physicianid)"; Can't do this till we know what fields are ints and what fields are strings
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
    statement << ", UNIQUE (username));";
    return statement.str();
}
