#include "property.h"

Property::Property(string nameParam, ModelObject* object)
    : name (nameParam),
      modelObj (object)
{
}

string Property::getName()
{
    return name;
}

ModelObject* Property::getModelObject()
{
    return modelObj;
}
