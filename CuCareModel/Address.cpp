// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Address.h - Declaration of base class Address
// Member functions are defined in Address.cpp

#include "Address.h"

Address::Address()
    : country (""),
      city (""),
      lineOne (""),
      lineTwo (""),
      postalCode ("")
{
}

// Constructor
Address::Address
(   string countryParam,
    string cityParam,
    string lineOneParam,
    string lineTwoParam,
    string postalCodeParam)
    : country (countryParam),
      city (cityParam),
      lineOne (lineOneParam),
      lineTwo (lineTwoParam),
      postalCode (postalCodeParam)
{
}

// Destructor
Address::~Address()
{
}

string Address::getCountry() { return country; }
void Address::setCountry(string value) { country = value; }

string Address::getCity() { return city; }
void Address::setCity(string value) { city = value; }

string Address::getLineOne() { return lineOne; }
void Address::setLineOne(string value) { lineOne = value; }

string Address::getLineTwo() { return lineTwo; }
void Address::setLineTwo(string value) { lineTwo = value; }

string Address::getPostalCode() { return postalCode; }
void Address::setPostalCode(string value) { postalCode = value; }

// EOF
