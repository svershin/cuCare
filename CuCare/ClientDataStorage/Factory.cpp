#include "Factory.h"
#include "Warehouse.h"

    //TODO: Interface with comms

Factory::Factory()
    : warehouse (new Warehouse(this))
{
    instantiationMap[ModelObject::ADMINASSISTANT] = &Factory::instantiateAdminAssistant;
}

Factory::~Factory()
{
    delete warehouse;
}

void Factory::create(ModelObject *object)
{
    map<string, string> objectProps;
    ObjectInterpreter::ObjectToProperties(object, &objectProps);
    string tableName = object->getTableName();
    int uid;

    //uid = comms.doStuff(things);

    CALL_MEM_FUN((*this), instantiationMap[object->getObjectType()]) (&objectProps, uid);
}

void Factory::modify(ModelObject *object)
{
    map<string, string> objectProps;
    ObjectInterpreter::ObjectToProperties(object, &objectProps);
    string tableName = object->getTableName();

    //comms.doOtherStuff(things)

    CALL_MEM_FUN((*this), instantiationMap[object->getObjectType()]) (&objectProps, object->getId());
}

list<int> Factory::pull(ModelObject *filteredObject)
{
    map<string, string> filteredProps;
    ObjectInterpreter::ObjectToProperties(filteredObject, &filteredProps);
    string tableName = filteredObject->getTableName();

    list<map<string, string> *>* objectsList = NULL; // = comms.getStuff(things)
    list<int> pulledIds;

    for(list<map<string, string> *>::iterator it = objectsList->begin(); it != objectsList->end(); ++it)
    {
        map<string, string> *objectProps = (*it);

        //Object type is a special property.  It is used to decide which instantiation function to call.
        ModelObject::ObjectType type = (ModelObject::ObjectType)(Utility::stoi((*objectProps)[OBJECT_TYPE_PROPERTY_NAME]));

        int pulledId = CALL_MEM_FUN((*this), instantiationMap[type]) (objectProps, -1);

        pulledIds.push_back(pulledId);
    }

    return pulledIds;
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



