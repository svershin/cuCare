#include <iostream>

#include "specificobjecttwo.h".h"
#include "property.h"

using namespace std;

int main()
{
    ModelObject* m = new SpecificObjectTwo();
    cout << m->getGeneralField() << endl;
    cout << m->getSomeString() << endl;
    list<Property*>* l = m->getProperties();
    list<Property*>::iterator i;
    for(i = l->begin(); i != l->end(); ++i)
    {
        (*i)->setValue("0");
    }
    for(i = l->begin(); i != l->end(); ++i)
    {
        cout << (*i)->getValue() << endl;
    }
    return 0;
}
