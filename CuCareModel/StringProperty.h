#ifndef STRINGPROPERTY_H
#define STRINGPROPERTY_H

#include "Property.h"

class StringProperty : public Property
{
public:
    StringProperty(string name, ModelObject* object, Property::stringGetter getter, Property::stringSetter setter);

    string getValue();
    void setValue(string value);

private:
    Property::stringGetter get;
    Property::stringSetter set;
};

#endif // STRINGPROPERTY_H
