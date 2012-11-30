#include "Warehouse.h"
#include "../../CuCareModel/Property.h"

Warehouse::Warehouse(Factory *parentFactoryParam)
    : parentFactory (parentFactoryParam)
{
}

Warehouse::~Warehouse()
{
    //TODO: Destruct the rest of the maps the same way
    for(map<int, AdminAssistant*>::iterator it = AdminAssistants.begin(); it != AdminAssistants.end(); ++it)
        delete it->second;
    AdminAssistants.clear();
}

//TODO: other get methods, same as this one
AdminAssistant* Warehouse::getAdminAssistant(int index)
{
    if(0 == AdminAssistants.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        AdminAssistant filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return AdminAssistants[index];
}

//TODO: Other add methods, same as this one
void Warehouse::addAdminAssistant(AdminAssistant *newObject)
{
    if(1 == AdminAssistants.count(newObject->getId()))
    {
        AdminAssistant *obsolete = AdminAssistants[newObject->getId()];
        AdminAssistants[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        AdminAssistants[newObject->getId()] = newObject;
}

