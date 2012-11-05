// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// HealthCard.h - Declaration of base class HealthCard
// Member functions are defined in HealthCard.cpp

#ifndef HEALTHCARD_H
#define HEALTHCARD_H

#include <string>
#include "Date.h"
#include <QString>
#include <QVariantMap>

using namespace std;

class HealthCard : public ModelObject
{

    Q_OBJECT

    Q_PROPERTY(QString number READ qGetNumber WRITE qSetNumber)
    Q_PROPERTY(QVariantMap expiry READ qGetExpiry WRITE qSetExpiry)

public:

    // Constructor
    HealthCard(string numberParam, Date expiryParam);

    HealthCard();

    // Destructor
    ~HealthCard();

    string getNumber();
    void setNumber(const string value);

    Date getExpiry();
    void setExpiry(const Date value);


    //Special getters and setters for serialization purposes
    QString qGetNumber();
    void qSetNumber(const QString value);

    QVariantMap qGetExpiry();
    void qSetExpiry(const QVariantMap value);

protected:
private:
    string number;
    Date expiry;
};


#endif

// EOF
