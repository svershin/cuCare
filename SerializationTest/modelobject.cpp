#include "modelobject.h"
#include "stringproperty.h"

ModelObject::ModelObject()
    : generalField ("Some data in general field"),
      properties ()
{
    properties.push_back(new StringProperty("generalField", this, &ModelObject::getGeneralField, &ModelObject::setGeneralField));
}

string ModelObject::getGeneralField()
{
    return generalField;
}

void ModelObject::setGeneralField(string value)
{
    generalField = value;
}

list<Property*>* ModelObject::getProperties()
{
    return &properties;
}
