#include "IntProperty.h"

IntProperty::IntProperty(string name, ModelObject* object, Property::intGetter getter, Property::intSetter setter)
    : Property(name, object),
      get (getter),
      set (setter)

{
}

string IntProperty::getValue()
{
    return Utility::itos(CALL_MEM_FUN(*getModelObject(), get)());
}

void IntProperty::setValue(string value)
{
    CALL_MEM_FUN(*getModelObject(), set)(Utility::stoi(value));
}
