#include "messagegenerator.h"
#include <iostream>

MessageGenerator::MessageGenerator()
{

}

QByteArray MessageGenerator::qObjectToJson(const QObject &modelObject)
{
    QJson::Serializer cerealizer;
    QBuffer buffer;
    bool ok = true;

    //Turn the passed object into a QVariantMap, use the serializer to serialize it, and return the JSON in the form of a QByteArray
    const QVariantMap variantMap = QJson::QObjectHelper::qobject2qvariant(&modelObject);

    cerealizer.serialize(variantMap, &buffer, &ok);
    if(!ok)
    {
        cout << "damn: " << ok << endl;
        throw("serialize failed");
    }

    return buffer.data();
}

