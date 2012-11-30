#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "Utility.h"
#include "ModelObject.h"

using namespace std;

#define CALL_MEM_FUN(object,ptrToMemFun)  ((object).*(ptrToMemFun))

class Property
{
public:

    typedef int (ModelObject::*intGetter) ();
    typedef string (ModelObject::*stringGetter) ();
    typedef void (ModelObject::*intSetter) (int value);
    typedef void (ModelObject::*stringSetter) (string value);

    Property(string nameParam, ModelObject* modelObject);

    virtual string getValue()=0;
    virtual void setValue(string value)=0;
    virtual string getName();

    ModelObject* getModelObject();
private:
    string name;
    ModelObject* modelObj;
};

#endif // PROPERTY_H
