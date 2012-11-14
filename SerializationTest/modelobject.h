#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <string>
#include <list>
class Property;

using namespace std;

class ModelObject
{
public:
    ModelObject();

    string getGeneralField();
    void setGeneralField(string value);
    list<Property*>* getProperties();

    virtual string getSomeString()=0;
    virtual void setSomeString(string value)=0;
private:
    string generalField;

    list<Property*> properties;
};

#endif // MODELOBJECT_H
