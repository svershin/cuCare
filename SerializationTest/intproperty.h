#ifndef INTPROPERTY_H
#define INTPROPERTY_H

#include "property.h"

class IntProperty : public Property
{
public:
    IntProperty(string name, ModelObject* object, Property::intGetter getter, Property::intSetter setter);

    virtual string getValue();
    virtual void setValue(string value);
private:
    Property::intGetter get;
    Property::intSetter set;
};

#endif // INTPROPERTY_H
