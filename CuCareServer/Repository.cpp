#include "Repository.h"
#include <sstream>

Repository::Repository()
    : db (NULL),
      createScriptFilename ("../CuCareServer/dbcreate.sql")
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
    if(!createScript)
        cout << "Failed to find file.\n";

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

string Repository::itos(int integer)
{
    stringstream number;
    number << integer;
    return number.str();
}

int Repository::stoi(string stringvalue)
{
    stringstream number(stringvalue);
    int results;
    number >> results;
    return results;
}

bool Repository::databaseExists()
{
    ifstream dbfile(db->dbFilename.c_str());
    return dbfile; //Casts to true if file exists.
}

bool Repository::insertStatement(string table, string idname, map<string, string> values)
{
    values[idname] = "NULL";
    return insertStatement(table, values);
}

bool Repository::insertStatement(string table, map<string, string> values)
{
    stringstream statement;
    stringstream valueBracket;
    statement << "INSERT INTO " << table << "(";
    valueBracket << "('";
    bool firstvalue = true;
    for(map<string, string>::iterator it = values.begin(); it != values.end(); it++)
    {
        if(firstvalue)
        {
            firstvalue = false;
            statement << it->first;
            valueBracket << it->second << "'";
        }
        else
        {
            statement << ", " << it->first;
            valueBracket << ", '" << it->second << "'";
        }
    }
    statement << ") VALUES ";
    valueBracket << ")";
    statement << valueBracket << ";";

    string command = statement.str();
    return db->command(command);
}

bool Repository::updateStatement(string table, string idname, string idvalue, map<string, string> values)
{
    stringstream statement;
    statement << "UPDATE " << table << " SET (";
    bool firstvalue = true;
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
    statement << ") WHERE " << idname << " = '" << idvalue << "';";

    string command = statement.str();
    return db->command(command);
}

map<string, string> Repository::getConsultationValues(Consultation* pInputConsultation, int physicianId, int patientId)
{
    map<string,string> values;
    values["physicianid"] = itos(physicianId);
    values["patientid"] = itos(patientId);
    values["reason"] = pInputConsultation->getReason();
    values["diagnosis"] = pInputConsultation->getDiagnosis();
    values["status"] = itos(pInputConsultation->getStatus());
    values["day"] = itos(pInputConsultation->getDate().getDay());
    values["month"] = itos(pInputConsultation->getDate().getMonth());
    values["year"] = itos(pInputConsultation->getDate().getYear());
    return values;
}

map<string, string> Repository::getPatientValues(Patient *pInputPatient, int physicianId)
{
    map<string,string> values;
    values["physicianid"] = itos(physicianId);
    values["firstname"] = pInputPatient->getFirstName();
    values["lastname"] = pInputPatient->getLastName();
    values["country"] = pInputPatient->getAddress().getCountry();
    values["city"] = pInputPatient->getAddress().getCity();
    values["addresslineone"] = pInputPatient->getAddress().getLineOne();
    values["addresslinetwo"] = pInputPatient->getAddress().getLineTwo();
    values["postalcode"] = pInputPatient->getAddress().getPostalCode();
    values["workphone"] = pInputPatient->getContact().getWorkPhone();
    values["cellphone"] = pInputPatient->getContact().getCellPhone();
    values["email"] = pInputPatient->getContact().getEmail();
    values["workemail"] = pInputPatient->getContact().getWorkEmail();
    values["birthday"] = itos(pInputPatient->getDateOfBirth().getDay());
    values["birthmonth"] = itos(pInputPatient->getDateOfBirth().getMonth());
    values["birthyear"] = itos(pInputPatient->getDateOfBirth().getYear());
    values["addedday"] = itos(pInputPatient->getDateAddedToSystem().getDay());
    values["addedmonth"] = itos(pInputPatient->getDateAddedToSystem().getMonth());
    values["addedyear"] = itos(pInputPatient->getDateAddedToSystem().getYear());
    values["healthcardnumber"] = pInputPatient->getHealthCard().getNumber();
    values["healthcardexpiryday"] = itos(pInputPatient->getHealthCard().getExpiry().getDay());
    values["healthcardexpirymonth"] = itos(pInputPatient->getHealthCard().getExpiry().getMonth());
    values["healthcardexpiryyear"] = itos(pInputPatient->getHealthCard().getExpiry().getYear());
    values["notes"] = pInputPatient->getNotes();
    return values;
}

map<string, string> Repository::getFollowupValues(Followup *pInputFollowup, int consultationId)
{
    map<string,string> values;
    values["consultationid"] =consultationId;
    values["status"] = itos(pInputFollowup->getStatus());
    values["dueday"] = itos(pInputFollowup->getDateDue().getDay());
    values["duemonth"] = itos(pInputFollowup->getDateDue().getMonth());
    values["dueyear"] = itos(pInputFollowup->getDateDue().getYear());
    values["receivedday"] = itos(pInputFollowup->getDateReceived().getDay());
    values["receivedmonth"] = itos(pInputFollowup->getDateReceived().getMonth());
    values["receivedyear"] = itos(pInputFollowup->getDateReceived().getYear());
    values["completedday"] = itos(pInputFollowup->getDateCompleted().getDay());
    values["completedmonth"] = itos(pInputFollowup->getDateCompleted().getMonth());
    values["completedyear"] = itos(pInputFollowup->getDateCompleted().getYear());
    return values;
}

map<string, string> Repository::getResultantFollowupValues(ResultantFollowup *pInputResultantFollowup)
{
    map<string,string> values;
    values["results"] = pInputResultantFollowup->getResults();
    return values;
}

map<string, string> Repository::getMedicalTestValues(MedicalTest *pInputMedicalTest)
{
    map<string,string> values;
    values["testtype"] = pInputMedicalTest->getTestType();
    return values;
}

map<string, string> Repository::getReferralValues(Referral *pInputReferral)
{
    map<string,string> values;
    values["specialistname"] = pInputReferral->getSpecialistName();
    return values;
}

map<string, string> Repository::getMedicationRenewalValues(MedicationRenewal *pInputMedicationRenewal)
{
    map<string,string> values;
    values["medication"] = pInputMedicationRenewal->getMedication();
    return values;
}

map<string, string> Repository::getReturnConsultationValues(int nextConsultationId)
{
    map<string,string> values;
    values["nextconsultationid"] = itos(nextConsultationId);
    return values;
}

map<string, string> Repository::getUserValues(User *pInputUser)
{
    map<string,string> values;
    values["username"] = pInputUser->getUsername();
    values["firstname"] = pInputUser->getFirstName();
    values["lastname"] = pInputUser->getLastName();
    values["country"] = pInputUser->getAddress().getCountry();
    values["city"] = pInputUser->getAddress().getCity();
    values["addresslineone"] = pInputUser->getAddress().getLineOne();
    values["addresslinetwo"] = pInputUser->getAddress().getLineTwo();
    values["postalcode"] = pInputUser->getAddress().getPostalCode();
    values["workphone"] = pInputUser->getContact().getWorkPhone();
    values["cellphone"] = pInputUser->getContact().getCellPhone();
    values["email"] = pInputUser->getContact().getEmail();
    values["workemail"] = pInputUser->getContact().getWorkEmail();
    values["birthday"] = itos(pInputUser->getDateOfBirth().getDay());
    values["birthmonth"] = itos(pInputUser->getDateOfBirth().getMonth());
    values["birthyear"] = itos(pInputUser->getDateOfBirth().getYear());
    return values;
}

bool Repository::createConsultation(Consultation *pInputConsultation, int physicianId, int patientId, int *uid)
{
    if(!insertStatement("consultations", "consulationid", getConsultationValues(pInputConsultation, physicianId, patientId)))
        return false;
    *uid = db->lastUid();
    return true;
}

bool Repository::createPatient(Patient *pInputPatient, int physicianId, int *uid)
{
    if(!insertStatement("patients", "patientid", getPatientValues(pInputPatient, physicianId)))
        return false;
    *uid = db->lastUid();
    return true;
}

bool Repository::createFollowup(Followup *pInputFollowup, int consultationId, int *uid)
{
    if(!insertStatement("followups", "followupid", getFollowupValues(pInputFollowup, consultationId)))
        return false;
    *uid = db->lastUid();
    return true;
}

bool Repository::createResultantFollowup(ResultantFollowup *pInputResultantFollowup, int consultationId, int *uid)
{
    Followup* pInputFollowup = pInputResultantFollowup;
    if(!createFollowup(pInputFollowup, consultationId, uid))
        return false;

    string table = "resultantfollowups";
    map<string, string> values = getResultantFollowupValues(pInputResultantFollowup);
    values["followupid"] = itos(*uid);

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::createMedicalTest(MedicalTest *pInputMedicalTest, int consultationId, int *uid)
{
    ResultantFollowup* pInputResultantFollowup = pInputMedicalTest;
    if(!createResultantFollowup(pInputResultantFollowup, consultationId, uid))
        return false;

    string table = "medicaltests";
    map<string,string> values = getMedicalTestValues(pInputMedicalTest);
    values["followupid"] = itos(*uid);

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::createReferral(Referral *pInputReferral, int consultationId, int *uid)
{
    ResultantFollowup* pInputResultantFollowup = pInputReferral;
    if(!createResultantFollowup(pInputResultantFollowup, consultationId, uid))
        return false;

    string table = "referrals";
    map<string,string> values = getReferralValues(pInputReferral);
    values["followupid"] = itos(*uid);

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::createMedicationRenewal(MedicationRenewal *pInputMedicationRenewal, int consultationId, int *uid)
{
    Followup* pInputFollowup = pInputMedicationRenewal;
    if(!createFollowup(pInputFollowup, consultationId, uid))
        return false;

    string table = "medicationrenewals";
    map<string,string> values = getMedicationRenewalValues(pInputMedicationRenewal);
    values["followupid"] = itos(*uid);

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::createReturnConsultation(ReturnConsultation *pInputMedicationRenewal, int consultationId, int nextConsultationId, int *uid)
{
    Followup* pInputFollowup = pInputMedicationRenewal;
    if(!createFollowup(pInputFollowup, consultationId, uid))
        return false;

    string table = "returnconsultations";
    map<string,string> values = getReturnConsultationValues(nextConsultationId);
    values["followupid"] = itos(*uid);

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::createUser(User *pInputUser)
{
    stringstream checkName;
    checkName << "SELECT * FROM users WHERE username = '" << pInputUser->getUsername() << "';";
    string query = checkName.str();
    QueryResult* pResults = NULL;
    if(!db->query(query, pResults))
        return false;
    if(pResults->numRows() > 0)
        throw "Username is already in use";

    if(!insertStatement("users", getUserValues(pInputUser)))
        return false;
    return true;
}

bool Repository::createPhysician(Physician* pInputPhysician, int* uid)
{
    User* pInputUser = pInputPhysician;
    if(!createUser(pInputUser))
        return false;

    //Autoincrementing ids only works for primary keys, so we have to do something else for physid
    stringstream getUid;
    getUid << "SELECT MAX(ISNULL(physicianid, 0) + 1) FROM physicians";
    string query = getUid.str();
    QueryResult* pResults = NULL;
    if(!db->query(query, pResults))
        return false;
    *uid = stoi((*pResults)[0]);

    string table = "physicians";
    map<string,string> values;
    values["username"] = pInputPhysician->getUsername();
    values["physicianid"] = itos(*uid);

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::createAdminAssistant(AdminAssistant *pInputAdminAssistant)
{
    User* pInputUser = pInputAdminAssistant;
    if(!createUser(pInputUser))
        return false;

    string table = "adminassistants";
    map<string,string> values;
    values["username"] = pInputAdminAssistant->getUsername();

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::createSysAdmin(SysAdmin *pInputSysAdmin)
{
    User* pInputUser = pInputSysAdmin;
    if(!createUser(pInputUser))
        return false;

    string table = "sysadmins";
    map<string,string> values;
    values["username"] = pInputSysAdmin->getUsername();

    if(!insertStatement(table, values))
        return false;
    return true;
}

bool Repository::pushUser(User* pInputUser)
{
    if(!updateStatement("users", "username", pInputUser->getUsername(), getUserValues(pInputUser)))
        return false;
    return true;
}

bool Repository::pushPatient(Patient *pInputPatient, int physicianId)
{
    if(!updateStatement("patients", "patientid", itos(pInputPatient->getId()), getPatientValues(pInputPatient, physicianId)))
        return false;
    return true;
}

bool Repository::pushConsultation(Consultation *pInputConsultation, int physicianId, int patientId)
{
    if(!updateStatement("consultations", "consultationid", itos(pInputConsultation->getConsultID()), getConsultationValues(pInputConsultation, physicianId, patientId)))
        return false;
    return true;
}

bool Repository::pushFollowup(Followup *pInputFollowup, int consultationId)
{
    if(!updateStatement("followups", "followupid", itos(pInputFollowup->getId()), getFollowupValues(pInputFollowup, consultationId)))
        return false;
    return true;
}

bool Repository::pushResultantFollowup(ResultantFollowup *pInputResultantFollowup, int consultationId)
{
    Followup* pInputFollowup = pInputResultantFollowup;
    if(!pushFollowup(pInputFollowup, consultationId))
        return false;

    if(!updateStatement("resultantfollowups", "followupid", itos(pInputResultantFollowup->getId()), getResultantFollowupValues(pInputResultantFollowup)))
        return false;
    return true;
}

bool Repository::pushReferral(Referral *pInputReferral, int consultationId)
{
    ResultantFollowup* pInputResultantFollowup = pInputReferral;
    if(!pushResultantFollowup(pInputResultantFollowup, consultationId))
        return false;

    if(!updateStatement("referrals", "followupid", itos(pInputReferral->getId()), getReferralValues(pInputReferral)))
        return false;
    return true;
}

bool Repository::pushMedicalTest(MedicalTest *pInputMedicalTest, int consultationId)
{
    ResultantFollowup* pInputResultantFollowup = pInputMedicalTest;
    if(!pushResultantFollowup(pInputResultantFollowup, consultationId))
        return false;

    if(!updateStatement("medicaltests", "followupid", itos(pInputMedicalTest->getId()), getMedicalTestValues(pInputMedicalTest)))
        return false;
    return true;
}

bool Repository::pushReturnConsultation(ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId)
{
    Followup* pInputFollowup = pInputReturnConsultation;
    if(!pushFollowup(pInputFollowup, consultationId))
        return false;

    if(!updateStatement("returnconsultations", "followupid", itos(pInputReturnConsultation->getId()), getReturnConsultationValues(nextConsultationId)))
        return false;
    return true;
}

bool Repository::pushMedicationRenewal(MedicationRenewal *pInputMedicationRenewal, int consultationId)
{
    Followup* pInputFollowup = pInputMedicationRenewal;
    if(!pushFollowup(pInputFollowup, consultationId))
        return false;

    if(!updateStatement("medicationrenewal", "followupid", itos(pInputMedicationRenewal->getId()), getMedicationRenewalValues(pInputMedicationRenewal)))
        return false;
    return true;
}





