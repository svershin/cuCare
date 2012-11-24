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

    virtual string getTableName() = 0;

    list<Property*>* getProperties();

    //All getters and setters used in properties must be declared here as virtual functions
    //Do not use pure virtual - that will require all inherited classes to implement the virtual function
    //The body's of these functions should be empty, but you cannot inline them, because of the way virtual functions work.
    //The signiture must be exactly the same as the getter or setter's signiture in the derived class.
    virtual int getConsultId();
    virtual void setConsultId(int value);

    virtual string getReason();
    virtual void setReason(string value);

private:
    list<Property*> properties;
};

#endif // MODELOBJECT_H
