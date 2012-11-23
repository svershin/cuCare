#include "ModelObject.h"

ModelObject::ModelObject()
    : properties ()
{

}

list<Property*>* ModelObject::getProperties()
{
    return &properties;
}
