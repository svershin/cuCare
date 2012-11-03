#include "Repository.h"
#include <sstream>

Repository::Repository()
    : db (NULL),
      createScriptFilename ("../CuCareServer/dbcreate.sql"),
      adminAssistantColumns ("username, firstname, lastname, country, city, addresslineone, addresslinetwo, postalcode, workphone, cellphone, email, workemail, birthday, birthmonth, birthyear, deleted"),
      physicianColumns ("username, physicianid, lastname, country, city, addresslineone, addresslinetwo, postalcode, workphone, cellphone, email, workemail, birthday, birthmonth, birthyear, deleted"),
      sysAdminColumns (adminAssistantColumns),
      patientColumns ("patientid, firstname, lastname, country, city, addresslineone, addresslinetwo, postalcode, workphone, cellphone, email, workemail, birthday, birthmonth, birthyear, addedday, addedmonth, addedyear, healthcardnumber, healthcardexpiryday, healthcardexpirymonth, healthcardexpiryyear, notes, physicianid, deleted"),
      consultationColumns ("consultationid, physicianid, patientid, reason, diagnosis, status, day, month, year, comments, hours, minutes, deleted"),
      referralColumns ("followupid, specialistname, results, consultationid, dueday, duemonth, dueyear, receivedday, receievedmonth, receivedyear, completedday, completedmonth, completedyear, status, deleted"),
      medicalTestColumns ("followupid, testtype, results, consultationid, dueday, duemonth, dueyear, receivedday, receievedmonth, receivedyear, completedday, completedmonth, completedyear, status, deleted"),
      returnConsultationColumns ("followupid, nextconsultationid, consultationid, dueday, duemonth, dueyear, receivedday, receievedmonth, receivedyear, completedday, completedmonth, completedyear, status, deleted"),
      medicationRenewalColumns ("followupid, medication, consultationid, dueday, duemonth, dueyear, receivedday, receievedmonth, receivedyear, completedday, completedmonth, completedyear, status, deleted")
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

string Repository::getDbErrorText()
{
    return db->getErrorText();
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

string Repository::squote(string stringValue)
{
    stringstream toQuote;
    toQuote << "'" << stringValue << "'";
    return toQuote.str();
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
    valueBracket << "(";
    bool firstvalue = true;
    for(map<string, string>::iterator it = values.begin(); it != values.end(); it++)
    {
        if(firstvalue)
        {
            firstvalue = false;
            statement << it->first;
            valueBracket << it->second;
        }
        else
        {
            statement << ", " << it->first;
            valueBracket << ", " << it->second;
        }
    }
    statement << ") VALUES ";
    valueBracket << ")";
    statement << valueBracket.str() << ";";

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
            statement << it->first << " = " << it->second;
        }
        else
            statement << ", " << it->first << " = " << it->second;
    }
    statement << ") WHERE " << idname << " = " << idvalue << ";";

    string command = statement.str();
    return db->command(command);
}

bool Repository::selectStatement(string table, map<string, string> where, string columns, QueryResult *&pResults)
{
    stringstream statement;
    statement << "SELECT " << columns << " FROM " << table << " WHERE ";
    bool firstvalue = true;
    for(map<string, string>::iterator it = where.begin(); it != where.end(); it++)
    {
        if(firstvalue)
        {
            firstvalue = false;
            statement << it->first << " = " << it->second;
        }
        else
            statement << " AND " << it->first << " = " << it->second;
    }
    statement << ";";

    string query = statement.str();
    return db->query(query, pResults);
}

map<string, string> Repository::getConsultationValues(Consultation* pInputConsultation, int physicianId, int patientId)
{
    map<string,string> values;
    values["physicianid"] = itos(physicianId);
    values["patientid"] = itos(patientId);
    values["reason"] = squote(pInputConsultation->getReason());
    values["diagnosis"] = squote(pInputConsultation->getDiagnosis());
    values["status"] = itos(pInputConsultation->getStatus());
    values["day"] = itos(pInputConsultation->getDate().getDay());
    values["month"] = itos(pInputConsultation->getDate().getMonth());
    values["year"] = itos(pInputConsultation->getDate().getYear());
    values["comments"] = squote(pInputConsultation->getComments());
    values["hours"] = itos(pInputConsultation->getTime().getHour());
    values["minutes"] = itos(pInputConsultation->getTime().getMinute());
    values["deleted"] = (pInputConsultation->isDeleted()) ? ("1") : ("0");
    return values;
}

map<string, string> Repository::getPatientValues(Patient *pInputPatient, int physicianId)
{
    map<string,string> values;
    values["physicianid"] = itos(physicianId);
    values["firstname"] = squote(pInputPatient->getFirstName());
    values["lastname"] = squote(pInputPatient->getLastName());
    values["country"] = squote(pInputPatient->getAddress().getCountry());
    values["city"] = squote(pInputPatient->getAddress().getCity());
    values["addresslineone"] = squote(pInputPatient->getAddress().getLineOne());
    values["addresslinetwo"] = squote(pInputPatient->getAddress().getLineTwo());
    values["postalcode"] = squote(pInputPatient->getAddress().getPostalCode());
    values["workphone"] = squote(pInputPatient->getContact().getWorkPhone());
    values["cellphone"] = squote(pInputPatient->getContact().getCellPhone());
    values["email"] = squote(pInputPatient->getContact().getEmail());
    values["workemail"] = squote(pInputPatient->getContact().getWorkEmail());
    values["birthday"] = itos(pInputPatient->getDateOfBirth().getDay());
    values["birthmonth"] = itos(pInputPatient->getDateOfBirth().getMonth());
    values["birthyear"] = itos(pInputPatient->getDateOfBirth().getYear());
    values["addedday"] = itos(pInputPatient->getDateAddedToSystem().getDay());
    values["addedmonth"] = itos(pInputPatient->getDateAddedToSystem().getMonth());
    values["addedyear"] = itos(pInputPatient->getDateAddedToSystem().getYear());
    values["healthcardnumber"] = squote(pInputPatient->getHealthCard().getNumber());
    values["healthcardexpiryday"] = itos(pInputPatient->getHealthCard().getExpiry().getDay());
    values["healthcardexpirymonth"] = itos(pInputPatient->getHealthCard().getExpiry().getMonth());
    values["healthcardexpiryyear"] = itos(pInputPatient->getHealthCard().getExpiry().getYear());
    values["notes"] = squote(pInputPatient->getNotes());
    values["deleted"] = (pInputPatient->isDeleted()) ? ("1") : ("0");
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
    values["deleted"] = (pInputFollowup->isDeleted()) ? ("1") : ("0");
    return values;
}

map<string, string> Repository::getResultantFollowupValues(ResultantFollowup *pInputResultantFollowup)
{
    map<string,string> values;
    values["results"] = squote(pInputResultantFollowup->getResults());
    return values;
}

map<string, string> Repository::getMedicalTestValues(MedicalTest *pInputMedicalTest)
{
    map<string,string> values;
    values["testtype"] = squote(pInputMedicalTest->getTestType());
    return values;
}

map<string, string> Repository::getReferralValues(Referral *pInputReferral)
{
    map<string,string> values;
    values["specialistname"] = squote(pInputReferral->getSpecialistName());
    return values;
}

map<string, string> Repository::getMedicationRenewalValues(MedicationRenewal *pInputMedicationRenewal)
{
    map<string,string> values;
    values["medication"] = squote(pInputMedicationRenewal->getMedication());
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
    values["username"] = squote(pInputUser->getUsername());
    values["firstname"] = squote(pInputUser->getFirstName());
    values["lastname"] = squote(pInputUser->getLastName());
    values["country"] = squote(pInputUser->getAddress().getCountry());
    values["city"] = squote(pInputUser->getAddress().getCity());
    values["addresslineone"] = squote(pInputUser->getAddress().getLineOne());
    values["addresslinetwo"] = squote(pInputUser->getAddress().getLineTwo());
    values["postalcode"] = squote(pInputUser->getAddress().getPostalCode());
    values["workphone"] = squote(pInputUser->getContact().getWorkPhone());
    values["cellphone"] = squote(pInputUser->getContact().getCellPhone());
    values["email"] = squote(pInputUser->getContact().getEmail());
    values["workemail"] = squote(pInputUser->getContact().getWorkEmail());
    values["birthday"] = itos(pInputUser->getDateOfBirth().getDay());
    values["birthmonth"] = itos(pInputUser->getDateOfBirth().getMonth());
    values["birthyear"] = itos(pInputUser->getDateOfBirth().getYear());
    values["deleted"] = (pInputUser->isDeleted()) ? ("1") : ("0");
    return values;
}

map<string, string> Repository::getUserConditions(User *pUserValues, UserFilter userFilter)
{
    map<string,string> values;
    if(userFilter.usernameGetMatch())
        values["username"] = squote(pUserValues->getUsername());
    if(userFilter.firstNameGetMatch())
        values["firstname"] = squote(pUserValues->getFirstName());
    if(userFilter.lastNameGetMatch())
        values["lastname"] = squote(pUserValues->getLastName());
    if(userFilter.addressGetMatch())
    {
        values["country"] = squote(pUserValues->getAddress().getCountry());
        values["city"] = squote(pUserValues->getAddress().getCity());
        values["addresslineone"] = squote(pUserValues->getAddress().getLineOne());
        values["addresslinetwo"] = squote(pUserValues->getAddress().getLineTwo());
        values["postalcode"] = squote(pUserValues->getAddress().getPostalCode());
    }
    if(userFilter.contactGetMatch())
    {
        values["workphone"] = squote(pUserValues->getContact().getWorkPhone());
        values["cellphone"] = squote(pUserValues->getContact().getCellPhone());
        values["email"] = squote(pUserValues->getContact().getEmail());
        values["workemail"] = squote(pUserValues->getContact().getWorkEmail());
    }
    if(userFilter.dateOfBirthGetMatch())
    {
        values["birthday"] = itos(pUserValues->getDateOfBirth().getDay());
        values["birthmonth"] = itos(pUserValues->getDateOfBirth().getMonth());
        values["birthyear"] = itos(pUserValues->getDateOfBirth().getYear());
    }
    if(userFilter.deletedGetMatch())
        values["deleted"] = (pUserValues->isDeleted()) ? ("1") : ("0");
    return values;
}

map<string, string> Repository::getPhysicianConditions(Physician *pPhysicianValues, PhysicianFilter physicianFilter)
{
    map<string, string> values = getUserConditions(pPhysicianValues, physicianFilter);
    if(physicianFilter.idGetMatch())
        values["physicianid"] = itos(pPhysicianValues->getId());
    return values;
}

map<string, string> Repository::getPatientConditions(Patient *pPatientValues, PatientFilter patientFilter, int physicianId)
{
    map<string,string> values;
    if(patientFilter.pPhysicianGetMatch())
        values["physicianid"] = itos(physicianId);
    if(patientFilter.firstNameGetMatch())
        values["firstname"] = squote(pPatientValues->getFirstName());
    if(patientFilter.lastNameGetMatch())
        values["lastname"] = squote(pPatientValues->getLastName());
    if(patientFilter.addressGetMatch())
    {
        values["country"] = squote(pPatientValues->getAddress().getCountry());
        values["city"] = squote(pPatientValues->getAddress().getCity());
        values["addresslineone"] = squote(pPatientValues->getAddress().getLineOne());
        values["addresslinetwo"] = squote(pPatientValues->getAddress().getLineTwo());
        values["postalcode"] = squote(pPatientValues->getAddress().getPostalCode());
    }
    if(patientFilter.contactGetMatch())
    {
        values["workphone"] = squote(pPatientValues->getContact().getWorkPhone());
        values["cellphone"] = squote(pPatientValues->getContact().getCellPhone());
        values["email"] = squote(pPatientValues->getContact().getEmail());
        values["workemail"] = squote(pPatientValues->getContact().getWorkEmail());
    }
    if(patientFilter.dateOfBirthGetMatch())
    {
        values["birthday"] = itos(pPatientValues->getDateOfBirth().getDay());
        values["birthmonth"] = itos(pPatientValues->getDateOfBirth().getMonth());
        values["birthyear"] = itos(pPatientValues->getDateOfBirth().getYear());
    }
    if(patientFilter.dateAddedToSystemGetMatch())
    {
        values["addedday"] = itos(pPatientValues->getDateAddedToSystem().getDay());
        values["addedmonth"] = itos(pPatientValues->getDateAddedToSystem().getMonth());
        values["addedyear"] = itos(pPatientValues->getDateAddedToSystem().getYear());
    }
    if(patientFilter.healthCardGetMatch())
    {
        values["healthcardnumber"] = squote(pPatientValues->getHealthCard().getNumber());
        values["healthcardexpiryday"] = itos(pPatientValues->getHealthCard().getExpiry().getDay());
        values["healthcardexpirymonth"] = itos(pPatientValues->getHealthCard().getExpiry().getMonth());
        values["healthcardexpiryyear"] = itos(pPatientValues->getHealthCard().getExpiry().getYear());
    }
    if(patientFilter.notesGetMatch())
        values["notes"] = squote(pPatientValues->getNotes());
    if(patientFilter.deletedGetMatch())
        values["deleted"] = (pPatientValues->isDeleted()) ? ("1") : ("0");
    return values;
}

map<string, string> Repository::getConsultationConditions(Consultation *pConsultationValues, ConsultationFilter consultationFilter, int physicianId, int patientId)
{
    map<string,string> values;
    if(consultationFilter.pConsultingPhysGetMatch())
        values["physicianid"] = itos(physicianId);
    if(consultationFilter.patientIdGetMatch())
        values["patientid"] = itos(patientId);
    if(consultationFilter.reasonGetMatch())
        values["reason"] = squote(pConsultationValues->getReason());
    if(consultationFilter.diagnosisGetMatch())
        values["diagnosis"] = squote(pConsultationValues->getDiagnosis());
    if(consultationFilter.statusGetMatch())
        values["status"] = itos(pConsultationValues->getStatus());
    if(consultationFilter.commentsGetMatch())
        values["comments"] = squote(pConsultationValues->getComments());
    if(consultationFilter.dateGetMatch())
    {
        values["day"] = itos(pConsultationValues->getDate().getDay());
        values["month"] = itos(pConsultationValues->getDate().getMonth());
        values["year"] = itos(pConsultationValues->getDate().getYear());
    }
    if(consultationFilter.timeGetMatch())
    {
        values["hours"] = itos(pConsultationValues->getTime().getHour());
        values["minutes"] = itos(pConsultationValues->getTime().getMinute());
    }
    if(consultationFilter.deletedGetMatch())
        values["deleted"] = (pConsultationValues->isDeleted()) ? ("1") : ("0");
    return values;
}

map<string, string> Repository::getFollowupConditions(Followup *pFollowupValues, FollowupFilter followupFilter, int consultationId)
{
    map<string,string> values;
    if(followupFilter.idGetMatch())
        values["consultationid"] =consultationId;
    if(followupFilter.statusGetMatch())
        values["status"] = itos(pFollowupValues->getStatus());
    if(followupFilter.dateDueGetMatch())
    {
        values["dueday"] = itos(pFollowupValues->getDateDue().getDay());
        values["duemonth"] = itos(pFollowupValues->getDateDue().getMonth());
        values["dueyear"] = itos(pFollowupValues->getDateDue().getYear());
    }
    if(followupFilter.dateReceivedGetMatch())
    {
        values["receivedday"] = itos(pFollowupValues->getDateReceived().getDay());
        values["receivedmonth"] = itos(pFollowupValues->getDateReceived().getMonth());
        values["receivedyear"] = itos(pFollowupValues->getDateReceived().getYear());
    }
    if(followupFilter.dateCompletedGetMatch())
    {
        values["completedday"] = itos(pFollowupValues->getDateCompleted().getDay());
        values["completedmonth"] = itos(pFollowupValues->getDateCompleted().getMonth());
        values["completedyear"] = itos(pFollowupValues->getDateCompleted().getYear());
    }
    if(followupFilter.deletedGetMatch())
        values["deleted"] = (pFollowupValues->isDeleted()) ? ("1") : ("0");
    return values;
}

map<string, string> Repository::getResultantFollowupConditions(ResultantFollowup *pResultantFollowupValues, ResultantFollowupFilter resultantFollowupFilter, int consultationId)
{
    map<string, string> values = getFollowupConditions(pResultantFollowupValues, resultantFollowupFilter, consultationId);
    if(resultantFollowupFilter.resultsGetMatch())
        values["results"] = squote(pResultantFollowupValues->getResults());
    return values;
}

map<string, string> Repository::getReferralConditions(Referral *pReferralValues, ReferralFilter referralFilter, int consultationId)
{
    map<string, string> values = getResultantFollowupConditions(pReferralValues, referralFilter, consultationId);
    if(referralFilter.specialistNameGetMatch())
        values["specialistname"] = squote(pReferralValues->getSpecialistName());
    return values;
}

map<string, string> Repository::getMedicalTestConditions(MedicalTest *pMedicalTestValues, MedicalTestFilter medicalTestFilter, int consultationId)
{
    map<string, string> values = getResultantFollowupConditions(pMedicalTestValues, medicalTestFilter, consultationId);
    if(medicalTestFilter.testTypeGetMatch())
        values["testtype"] = squote(pMedicalTestValues->getTestType());
    return values;
}

map<string, string> Repository::getReturnConsultationConditions(ReturnConsultation* pReturnConsultationValues, ReturnConsultationFilter returnConsultationFilter, int nextConsultationId, int consultationId)
{
    map<string, string> values = getFollowupConditions(pReturnConsultationValues, returnConsultationFilter, consultationId);
    if(returnConsultationFilter.pConsultGetMatch())
        values["consultationid"] = itos(nextConsultationId);
    return values;
}

map<string, string> Repository::getMedicationRenewalConditions(MedicationRenewal* pMedicationRenewalValues, MedicationRenewalFilter medicationRenewalFilter, int consultationId)
{
    map<string, string> values = getFollowupConditions(pMedicationRenewalValues, medicationRenewalFilter, consultationId);
    if(medicationRenewalFilter.medicationGetMatch())
        values["consultationid"] = squote(pMedicationRenewalValues->getMedication());
    return values;
}

void Repository::instantiateAdminAssistants(vector<AdminAssistant *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<AdminAssistant *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        AdminAssistant* retrieved = new AdminAssistant((*pQueryResult)[0],
                                                       (*pQueryResult)[1],
                                                       (*pQueryResult)[2],
                                                       Date(stoi((*pQueryResult)[12]),
                                                            stoi((*pQueryResult)[13]),
                                                            stoi((*pQueryResult)[14])),
                                                       ContactInfo((*pQueryResult)[8],
                                                                   (*pQueryResult)[9],
                                                                   (*pQueryResult)[10],
                                                                   (*pQueryResult)[11]),
                                                       Address((*pQueryResult)[3],
                                                               (*pQueryResult)[4],
                                                               (*pQueryResult)[5],
                                                               (*pQueryResult)[6],
                                                               (*pQueryResult)[7]),
                                                       (bool)stoi((*pQueryResult)[15]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiateConsultations(vector<Consultation *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<Consultation *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        Consultation* retrieved = new Consultation(stoi((*pQueryResult)[0]),
                                                   (*pQueryResult)[3],
                                                   (*pQueryResult)[4],
                                                   (*pQueryResult)[9],
                                                   (Consultation::ConsultationStatus)stoi((*pQueryResult)[5]),
                                                   Date(stoi((*pQueryResult)[6]),
                                                        stoi((*pQueryResult)[7]),
                                                        stoi((*pQueryResult)[8])),
                                                   Time(stoi((*pQueryResult)[10]),
                                                        stoi((*pQueryResult)[11])),
                                                   NULL,
                                                   (bool)stoi((*pQueryResult)[12]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiateMedicalTests(vector<MedicalTest *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<MedicalTest *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        MedicalTest* retrieved = new MedicalTest(stoi((*pQueryResult)[0]),
                                                 (Followup::FollowupStatus)stoi((*pQueryResult)[13]),
                                                 Date(stoi((*pQueryResult)[4]),
                                                      stoi((*pQueryResult)[5]),
                                                      stoi((*pQueryResult)[6])),
                                                 Date(stoi((*pQueryResult)[7]),
                                                      stoi((*pQueryResult)[8]),
                                                      stoi((*pQueryResult)[9])),
                                                 Date(stoi((*pQueryResult)[10]),
                                                      stoi((*pQueryResult)[11]),
                                                      stoi((*pQueryResult)[12])),
                                                 (*pQueryResult)[2],
                                                 (*pQueryResult)[1],
                                                 (bool)stoi((*pQueryResult)[14]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiateReferrals(vector<Referral *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<Referral *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        Referral* retrieved = new Referral(stoi((*pQueryResult)[0]),
                                           (Followup::FollowupStatus)stoi((*pQueryResult)[13]),
                                           Date(stoi((*pQueryResult)[4]),
                                                stoi((*pQueryResult)[5]),
                                                stoi((*pQueryResult)[6])),
                                           Date(stoi((*pQueryResult)[7]),
                                                stoi((*pQueryResult)[8]),
                                                stoi((*pQueryResult)[9])),
                                           Date(stoi((*pQueryResult)[10]),
                                                stoi((*pQueryResult)[11]),
                                                stoi((*pQueryResult)[12])),
                                           (*pQueryResult)[2],
                                           (*pQueryResult)[1],
                                           (bool)stoi((*pQueryResult)[14]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiatePatients(vector<Patient *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<Patient *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        Patient* retrieved = new Patient(stoi((*pQueryResult)[0]),
                                         (*pQueryResult)[1],
                                         (*pQueryResult)[2],
                                         (*pQueryResult)[22],
                                         ContactInfo((*pQueryResult)[8],
                                                     (*pQueryResult)[9],
                                                     (*pQueryResult)[10],
                                                     (*pQueryResult)[11]),
                                         Address((*pQueryResult)[3],
                                                 (*pQueryResult)[4],
                                                 (*pQueryResult)[5],
                                                 (*pQueryResult)[6],
                                                 (*pQueryResult)[7]),
                                         Date(stoi((*pQueryResult)[12]),
                                              stoi((*pQueryResult)[13]),
                                              stoi((*pQueryResult)[14])),
                                         Date(stoi((*pQueryResult)[15]),
                                              stoi((*pQueryResult)[16]),
                                              stoi((*pQueryResult)[17])),
                                         NULL,
                                         HealthCard((*pQueryResult)[18],
                                                    Date(stoi((*pQueryResult)[19]),
                                                         stoi((*pQueryResult)[20]),
                                                         stoi((*pQueryResult)[21]))),
                                         (bool)stoi((*pQueryResult)[24]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiateMedicationRenewals(vector<MedicationRenewal *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<MedicationRenewal *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        MedicationRenewal* retrieved = new MedicationRenewal(stoi((*pQueryResult)[0]),
                                                             (Followup::FollowupStatus)stoi((*pQueryResult)[12]),
                                                             Date(stoi((*pQueryResult)[3]),
                                                                  stoi((*pQueryResult)[4]),
                                                                  stoi((*pQueryResult)[5])),
                                                             Date(stoi((*pQueryResult)[6]),
                                                                  stoi((*pQueryResult)[7]),
                                                                  stoi((*pQueryResult)[8])),
                                                             Date(stoi((*pQueryResult)[9]),
                                                                  stoi((*pQueryResult)[10]),
                                                                  stoi((*pQueryResult)[11])),
                                                             (*pQueryResult)[1],
                                                             (bool)stoi((*pQueryResult)[13]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiateReturnConsultations(vector<ReturnConsultation *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<ReturnConsultation *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        ReturnConsultation* retrieved = new ReturnConsultation(stoi((*pQueryResult)[0]),
                                                               (Followup::FollowupStatus)stoi((*pQueryResult)[12]),
                                                               Date(stoi((*pQueryResult)[3]),
                                                                    stoi((*pQueryResult)[4]),
                                                                    stoi((*pQueryResult)[5])),
                                                               Date(stoi((*pQueryResult)[6]),
                                                                    stoi((*pQueryResult)[7]),
                                                                    stoi((*pQueryResult)[8])),
                                                               Date(stoi((*pQueryResult)[9]),
                                                                    stoi((*pQueryResult)[10]),
                                                                    stoi((*pQueryResult)[11])),
                                                               NULL,
                                                               (bool)stoi((*pQueryResult)[13]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiatePhysicians(vector<Physician *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<Physician *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        Physician* retrieved = new Physician(stoi((*pQueryResult)[1]),
                                             (*pQueryResult)[0],
                                             (*pQueryResult)[2],
                                             (*pQueryResult)[3],
                                             Date(stoi((*pQueryResult)[13]),
                                                  stoi((*pQueryResult)[14]),
                                                  stoi((*pQueryResult)[15])),
                                             ContactInfo((*pQueryResult)[9],
                                                         (*pQueryResult)[10],
                                                         (*pQueryResult)[11],
                                                         (*pQueryResult)[12]),
                                             Address((*pQueryResult)[4],
                                                     (*pQueryResult)[5],
                                                     (*pQueryResult)[6],
                                                     (*pQueryResult)[7],
                                                     (*pQueryResult)[8]),
                                             (bool)stoi((*pQueryResult)[16]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
}

void Repository::instantiateSysAdmins(vector<SysAdmin *> *pResults, QueryResult *pQueryResult)
{
    pResults = new vector<SysAdmin *>();
    do
    {   //column order is defined in the const strings "[classname]Columns"
        SysAdmin* retrieved = new SysAdmin((*pQueryResult)[0],
                                           (*pQueryResult)[1],
                                           (*pQueryResult)[2],
                                           Date(stoi((*pQueryResult)[12]),
                                                stoi((*pQueryResult)[13]),
                                                stoi((*pQueryResult)[14])),
                                           ContactInfo((*pQueryResult)[8],
                                                       (*pQueryResult)[9],
                                                       (*pQueryResult)[10],
                                                       (*pQueryResult)[11]),
                                           Address((*pQueryResult)[3],
                                                   (*pQueryResult)[4],
                                                   (*pQueryResult)[5],
                                                   (*pQueryResult)[6],
                                                   (*pQueryResult)[7]),
                                           (bool)stoi((*pQueryResult)[15]));
        pResults->push_back(retrieved);
    }
    while (pQueryResult->nextRow());
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
    values["username"] = squote(pInputPhysician->getUsername());
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
    values["username"] = squote(pInputAdminAssistant->getUsername());

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
    values["username"] = squote(pInputSysAdmin->getUsername());

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

bool Repository::pullAdminAssistant(AdminAssistant *pAdminAssistantValues, UserFilter userFilter, vector<AdminAssistant*> *pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("adminassistants NATURAL JOIN users", getUserConditions(pAdminAssistantValues, userFilter), adminAssistantColumns, pQueryResults))
        return false;

    instantiateAdminAssistants(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullPhysician(Physician *pPhysicianValues, PhysicianFilter physicianFilter, vector<Physician*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("physicians NATURAL JOIN users", getPhysicianConditions(pPhysicianValues, physicianFilter), physicianColumns, pQueryResults))
        return false;

    instantiatePhysicians(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullSysAdmin(SysAdmin *pSysAdminValues, UserFilter userFilter, vector<SysAdmin*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("sysadmins NATURAL JOIN users", getUserConditions(pSysAdminValues, userFilter), sysAdminColumns, pQueryResults))
        return false;

    instantiateSysAdmins(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullPatient(Patient* pPatientValues, PatientFilter patientFilter, int physicianId, vector<Patient*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("patients", getPatientConditions(pPatientValues, patientFilter, physicianId), patientColumns, pQueryResults))
        return false;

    instantiatePatients(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullConsultation(Consultation* pConsultationValues, ConsultationFilter consultationFilter, int physicianId, int patientId, vector<Consultation*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("consultations", getConsultationConditions(pConsultationValues, consultationFilter, physicianId, patientId), consultationColumns, pQueryResults))
        return false;

    instantiateConsultations(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullReferral(Referral* pReferralValues, ReferralFilter referralFilter, int consultationId, vector<Referral*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("(referrals NATURAL JOIN resultantfollowups) NATURAL JOIN followups", getReferralConditions(pReferralValues, referralFilter, consultationId), referralColumns, pQueryResults))
        return false;

    instantiateReferrals(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullMedicalTest(MedicalTest* pMedicalTestValues, MedicalTestFilter medicalTestFilter, int consultationId, vector<MedicalTest*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("(medicaltests NATURAL JOIN resultantfollowups) NATURAL JOIN followups", getMedicalTestConditions(pMedicalTestValues, medicalTestFilter, consultationId), medicalTestColumns, pQueryResults))
        return false;

    instantiateMedicalTests(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullReturnConsultation(ReturnConsultation* pReturnConsultationValues, ReturnConsultationFilter returnConsultationFilter, int consultationId, int nextConsultationId, vector<ReturnConsultation*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("returnconsultations NATURAL JOIN followups", getReturnConsultationConditions(pReturnConsultationValues, returnConsultationFilter, nextConsultationId, consultationId), returnConsultationColumns, pQueryResults))
        return false;

    instantiateReturnConsultations(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}

bool Repository::pullMedicationRenewal(MedicationRenewal* pMedicationRenewalValues, MedicationRenewalFilter medicationRenewalFilter, int consultationId, vector<MedicationRenewal*>* pResults)
{
    QueryResult* pQueryResults = NULL;
    if(!selectStatement("medicationrenewals NATURAL JOIN followups", getMedicationRenewalConditions(pMedicationRenewalValues, medicationRenewalFilter, consultationId), medicationRenewalColumns, pQueryResults))
        return false;

    instantiateMedicationRenewals(pResults, pQueryResults);
    delete pQueryResults;
    return true;
}






