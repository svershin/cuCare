// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Address.h - Declaration of base class Address
// Member functions are defined in Address.cpp

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address
{
public:

    // Constructor
    Address();

    Address (string countryParam,
             string cityParam,
             string lineOneParam,
             string lineTwoParam,
             string postalCodeParam);

    // Destructor
    ~Address();

    string getCountry();
    void setCountry(const string value);

    string getCity();
    void setCity(const string value);

    string getLineOne();
    void setLineOne(const string value);

    string getLineTwo();
    void setLineTwo(const string value);

    string getPostalCode();
    void setPostalCode(const string value);

protected:
private:
    string country;
    string city;
    string lineOne;
    string lineTwo;
    string postalCode;
};


#endif

// EOF
