#ifndef SPECIFICOBJECTTWO_H
#define SPECIFICOBJECTTWO_H

#include "modelobject.h"

class SpecificObjectTwo : public ModelObject
{
public:
    SpecificObjectTwo();

    string getSomeString();
    void setSomeString(string value);
private:
    string someString;
};

#endif // SPECIFICOBJECTTWO_H
