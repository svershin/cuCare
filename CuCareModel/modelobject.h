#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <QObject>
#include "../CuCareCommunications/qjson/src/qobjecthelper.h"

class ModelObject : public QObject
{
    Q_OBJECT
public:

    //Regular Constructor
    ModelObject();

    //Copy Constructor
    ModelObject(const ModelObject& origin);

    //Assignment operator
    ModelObject& operator=(const ModelObject& origin);

    //virtual void toBeAbstract() = 0;

};

#endif // MODELOBJECT_H
