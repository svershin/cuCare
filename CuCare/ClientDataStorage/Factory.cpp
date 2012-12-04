#include "Factory.h"
#include "Warehouse.h"

Factory::Factory(string ip, int port)
    : warehouse (new Warehouse(this)),
      cni (ip, (quint16)port)
{
    instantiationMap[ModelObject::ADMINASSISTANT] = &Factory::instantiateAdminAssistant;
    instantiationMap[ModelObject::SYSADMIN] = &Factory::instantiateSysAdmin;
    instantiationMap[ModelObject::PHYSICIAN] = &Factory::instantiatePhysician;
    instantiationMap[ModelObject::CONSULTATION] = &Factory::instantiateConsultation;
    instantiationMap[ModelObject::PATIENT] = &Factory::instantiatePatient;
    instantiationMap[ModelObject::REFERRAL] = &Factory::instantiateReferral;
    instantiationMap[ModelObject::MEDICALTEST] = &Factory::instantiateMedicalTest;
    instantiationMap[ModelObject::MEDICATIONRENEWAL] = &Factory::instantiateMedicationRenewal;
    instantiationMap[ModelObject::RETURNCONSULTATION] = &Factory::instantiateReturnConsultation;
}

Factory::~Factory()
{
    delete warehouse;
}

int Factory::create(ModelObject *object, int parentId)
{
    map<string, string> objectProps;
    ObjectInterpreter::ObjectToProperties(object, &objectProps, parentId);
    string tableName = object->getTableName();
    int uid;
    string errString;

    if(!cni.create(tableName, object->getIdName(), &objectProps, &uid, &errString) )
        throw errString;

    CALL_MEM_FUN((*this), instantiationMap[object->getObjectType()]) (&objectProps, uid);

    return uid;
}

void Factory::modify(ModelObject *object)
{
    map<string, string> objectProps;
    ObjectInterpreter::ObjectToProperties(object, &objectProps);
    string tableName = object->getTableName();
    string errString;

    if(!cni.push(tableName, object->getIdName(), &objectProps, &errString) )
        throw errString;

    CALL_MEM_FUN((*this), instantiationMap[object->getObjectType()]) (&objectProps, object->getId());
}

list<int> Factory::pull(ModelObject *filteredObject, int parentId)
{
    map<string, string> filteredProps;

    ObjectInterpreter::ObjectToProperties(filteredObject, &filteredProps, parentId);
    string tableName = filteredObject->getTableName();
    string errString;
    list<map<string, string> *> objectsList;

    if(!cni.pull(tableName, filteredObject->getIdName(), &filteredProps, &objectsList, &errString))
        throw errString;

    list<int> pulledIds;

    for(list<map<string, string> *>::iterator it = objectsList.begin(); it != objectsList.end(); ++it)
    {
        map<string, string> *objectProps = (*it);

        //Object type is a special property.  It is used to decide which instantiation function to call.
        ModelObject::ObjectType type = (ModelObject::ObjectType)(Utility::stoi((*objectProps)[OBJECT_TYPE_PROPERTY_NAME]));

        int pulledId = CALL_MEM_FUN((*this), instantiationMap[type]) (objectProps, -1);

        pulledIds.push_back(pulledId);
        \
        delete objectProps;
    }

    return pulledIds;
}

list<int> Factory::pullPatientsByFollowupStatus(ModelObject::FollowupStatus status)
{
    //This pull is specialized for the sake of efficiency.
    //The table name includes joins, allowing the SQL to do most of the work for the query
    //Unfortunately this ties the factory to the storage implementation to some degree
    //In future versions, we would like to find a better way to solve this problem
    map<string, string> filteredProps;
    filteredProps["c.status"] = Utility::itos((int)status);

    stringstream tablename;
    tablename << Patient::TABLE_NAME << " a LEFT OUTER JOIN " << Consultation::TABLE_NAME << " b ON a." << Patient::ID_NAME
              << " = b." << PARENT_ID_PROPERTY_NAME << " LEFT OUTER JOIN " << Followup::TABLE_NAME << " c ON b." << Consultation::ID_NAME
              << " = c." << PARENT_ID_PROPERTY_NAME;
    string errString;
    list<map<string, string> *> objectsList;

    if(!cni.pull(tablename.str(), "", &filteredProps, &objectsList, &errString))
        throw errString;

    list<int> pulledIds;

    for(list<map<string, string> *>::iterator it = objectsList.begin(); it != objectsList.end(); ++it)
    {
        map<string, string> *objectProps = (*it);

        int pulledId = instantiatePatient(objectProps, -1);

        pulledIds.push_back(pulledId);

        delete objectProps;
    }

    return pulledIds;
}

Warehouse *Factory::getWarehouse()
{
    return warehouse;
}

int Factory::propertyify(map<string, string> *properties, ModelObject *newObject, int uid)
{
    ObjectInterpreter::PropertiesToObject(properties, newObject);

    //On a pull, the uid will be given as negative one
    //In this case, PropertiesToObject will have already taken care of setting it
    if(uid != -1)
        newObject->setId(uid);

    return newObject->getId();
}

int Factory::instantiateAdminAssistant(map<string, string> *properties, int uid)
{
    AdminAssistant *newObject = new AdminAssistant();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addAdminAssistant(newObject);

    return ret;
}

int Factory::instantiatePhysician(map<string, string> *properties, int uid)
{
    Physician *newObject = new Physician();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addPhysician(newObject);

    return ret;
}

int Factory::instantiateSysAdmin(map<string, string> *properties, int uid)
{
    SysAdmin *newObject = new SysAdmin();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addSysAdmin(newObject);

    return ret;
}

int Factory::instantiateConsultation(map<string, string> *properties, int uid)
{
    Consultation *newObject = new Consultation();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addConsultation(newObject);

    return ret;
}

int Factory::instantiatePatient(map<string, string> *properties, int uid)
{
    Patient *newObject = new Patient();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addPatient(newObject);

    return ret;
}

int Factory::instantiateReferral(map<string, string> *properties, int uid)
{
    Referral *newObject = new Referral();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addReferral(newObject);

    return ret;
}

int Factory::instantiateMedicalTest(map<string, string> *properties, int uid)
{
    MedicalTest *newObject = new MedicalTest();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addMedicalTest(newObject);

    return ret;
}

int Factory::instantiateMedicationRenewal(map<string, string> *properties, int uid)
{
    MedicationRenewal *newObject = new MedicationRenewal();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addMedicationRenewal(newObject);

    return ret;
}

int Factory::instantiateReturnConsultation(map<string, string> *properties, int uid)
{
    ReturnConsultation *newObject = new ReturnConsultation();

    int ret = propertyify(properties, newObject, uid);

    warehouse->addReturnConsultation(newObject);

    return ret;
}



