#include "ObjectInterpreter.h"
#include "../../CuCareModel/Property.h"

ObjectInterpreter::ObjectInterpreter()
{
}

void ObjectInterpreter::ObjectToProperties(ModelObject *modelObject, map<string, string> *properties, int parentid)
{
    list<Property*>* objectProps = modelObject->getProperties();

    for(list<Property*>::iterator it = objectProps->begin(); it != objectProps->end(); ++it)
        (*properties)[(*it)->getName()] = (*it)->getValue();

    (*properties)[OBJECT_TYPE_PROPERTY_NAME] = modelObject->getObjectType();
    if(parentid != -1)
        (*properties)[PARENT_ID_PROPERTY_NAME] = Utility::itos(parentid);
    (*properties)[ID_NAME_PROPERTY_NAME] = modelObject->getIdName();
}

void ObjectInterpreter::PropertiesToObject(map<string, string> *properties, ModelObject *modelObject)
{
    list<Property*>* objectProps = modelObject->getProperties();

    //Object type and id name are not regular properties, and should be handled outside this function.
    properties->erase(OBJECT_TYPE_PROPERTY_NAME);
    properties->erase(PARENT_ID_PROPERTY_NAME);
    properties->erase(ID_NAME_PROPERTY_NAME);

    for(list<Property*>::iterator it = objectProps->begin(); it != objectProps->end(); ++it)
        (*it)->setValue((*properties)[(*it)->getName()]);
}
