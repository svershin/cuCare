// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Address.h - Declaration of base class Address
// Member functions are defined in Address.cpp

#ifndef ADDRESS_H
#define ADDRESS_H


#include <QObject>
#include <QtGlobal>
#include <string>
#include <QString>

using namespace std;

class Address : public QObject
{

    Q_OBJECT

    Q_PROPERTY(QString country READ qGetCountry WRITE qSetCountry)
    Q_PROPERTY(QString city READ qGetCity WRITE qSetCity)
    Q_PROPERTY(QString lineOne READ qGetLineOne WRITE qSetLineOne)
    Q_PROPERTY(QString lineTwo READ qGetLineTwo WRITE qSetLineTwo)
    Q_PROPERTY(QString postalCode READ qGetPostalCode WRITE qSetPostalCode)


public:


    //Copy Constructor and overloaded assignment operator
    Address& operator=(const Address& addr);
    Address(const Address& other);

    //Default constructor
    Address();

    // Regular-use Constructor
    Address (string countryParam,
             string cityParam,
             string lineOneParam,
             string lineTwoParam,
             string postalCodeParam);

    // Destructor
    virtual ~Address();


    string getCountry();
    void setCountry(const string& value);

    string getCity();
    void setCity(const string& value);

    string getLineOne();
    void setLineOne(const string& value);

    string getLineTwo();
    void setLineTwo(const string& value);

    string getPostalCode();
    void setPostalCode(const string& value);


    //Special getters and setters for object serialization purposes:
    QString qGetCountry();
    void qSetCountry(const QString& value);

    QString qGetCity();
    void qSetCity(const QString& value);

    QString qGetLineOne();
    void qSetLineOne(const QString& value);

    QString qGetLineTwo();
    void qSetLineTwo(const QString& value);

    QString qGetPostalCode();
    void qSetPostalCode(const QString& value);

private:
    string country;
    string city;
    string lineOne;
    string lineTwo;
    string postalCode;
};


#endif

// EOF
