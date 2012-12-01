// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// HealthCard.cpp - Implementation of class HealthCard
// Function and attribute declarations are in HealthCard.h

#include "HealthCard.h"

HealthCard::HealthCard()
    : number (""),
      expiry ()
{
}

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

Date* HealthCard::getExpiryPtr() { return &expiry; }

// EOF
