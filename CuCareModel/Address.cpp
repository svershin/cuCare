// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Address.h - Declaration of base class Address
// Member functions are defined in Address.cpp

#include "Address.h"

// Regular Constuctor
Address::Address
(   string countryParam,
    string cityParam,
    string lineOneParam,
    string lineTwoParam,
    string postalCodeParam)
    : QObject(),
      country (countryParam),
      city (cityParam),
      lineOne (lineOneParam),
      lineTwo (lineTwoParam),
      postalCode (postalCodeParam)
{}

// Blank Constructor
Address::Address()
{
    Address("","","","","");
}


// Copy Constructor
Address::Address(const Address& origin) :
    QObject(),
    country (origin.country),
    city (origin.city),
    lineOne (origin.lineOne),
    lineTwo (origin.lineTwo),
    postalCode (origin.postalCode)
{}

// Assignment Operator
Address& Address::operator=(const Address& origin)
{
    country = origin.country;
    city = origin.city;
    lineOne = origin.lineOne;
    lineTwo = origin.lineTwo;
    postalCode = origin.postalCode;
    return *this;
}








// Destructor
Address::~Address()
{
}

string Address::getCountry() { return country; }
void Address::setCountry(const string value) { country = value; }

string Address::getCity() { return city; }
void Address::setCity(const string value) { city = value; }

string Address::getLineOne() { return lineOne; }
void Address::setLineOne(const string value) { lineOne = value; }

string Address::getLineTwo() { return lineTwo; }
void Address::setLineTwo(const string value) { lineTwo = value; }

string Address::getPostalCode() { return postalCode; }
void Address::setPostalCode(const string value) { postalCode = value; }


//Special getters and setters for object serialization purposes:
QString Address::qGetCountry(){return QString::fromStdString(country);}
void Address::qSetCountry(const QString value){country = value.toStdString(); return;}

QString Address::qGetCity() {return QString::fromStdString(city);}
void Address::qSetCity(const QString value){city = value.toStdString(); return;}

QString Address::qGetLineOne(){return QString::fromStdString(lineOne);}
void Address::qSetLineOne(const QString value){lineOne = value.toStdString(); return;}

QString Address::qGetLineTwo(){return QString::fromStdString(lineTwo);}
void Address::qSetLineTwo(const QString value){lineTwo = value.toStdString(); return;}

QString Address::qGetPostalCode(){return QString::fromStdString(postalCode);}
void Address::qSetPostalCode(const QString value){postalCode = value.toStdString(); return;}

// EOF
