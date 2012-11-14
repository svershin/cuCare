#include "specificobjecttwo.h"
#include "stringproperty.h"

SpecificObjectTwo::SpecificObjectTwo()
    : ModelObject(),
      someString ("Specific object string")
{
    getProperties()->push_back(new StringProperty("someString", this, &ModelObject::getSomeString, &ModelObject::setSomeString));
}

string SpecificObjectTwo::getSomeString()
{
    return someString;
}

void SpecificObjectTwo::setSomeString(string value)
{
    someString = value;
}
