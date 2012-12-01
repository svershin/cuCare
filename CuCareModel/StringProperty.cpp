#include "StringProperty.h"

StringProperty::StringProperty(string name, ModelObject* object, Property::stringGetter getter, Property::stringSetter setter)
    : Property (name, object),
      get (getter),
      set (setter)
{
}

string StringProperty::getValue()
{
    return CALL_MEM_FUN(*getModelObject(), get)();
}

void StringProperty::setValue(string value)
{
    CALL_MEM_FUN(*getModelObject(), set)(value);
}
