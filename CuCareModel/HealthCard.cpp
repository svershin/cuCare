// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// HealthCard.h - Declaration of base class HealthCard
// Member functions are defined in HealthCard.cpp

#include "HealthCard.h"

// Constructor
HealthCard::HealthCard(string numberParam, Date expiryParam)
    : number (numberParam),
      expiry (expiryParam)
{
}

// Destructor
HealthCard::~HealthCard()
{
}

string HealthCard::getNumber() { return number; }
void HealthCard::setNumber(const string value) { number = value; }

Date HealthCard::getExpiry() { return expiry; }
void HealthCard::setExpiry(const Date value) { expiry = value; }


// EOF
