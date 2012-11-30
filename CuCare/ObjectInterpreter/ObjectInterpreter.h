#ifndef OBJECTINTERPRETER_H
#define OBJECTINTERPRETER_H

#include "../../CuCareModel/ModelObject.h"
#include <map>

using namespace std;

class ObjectInterpreter
{
public:
    ObjectInterpreter();

    virtual void abstract() = 0;

    //Initialize the map before calling - this method will fill it out.
    static void ObjectToProperties (ModelObject *modelObject, map<string, string>* properties);

    //Initialize the modelobject before calling - this method will fill it out
    static void PropertiesToObject (map<string, string> *properties, ModelObject *modelObject);
};

#endif // OBJECTINTERPRETER_H
