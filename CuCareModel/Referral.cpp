// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Referral.h - Declaration of base class Referral
// Member functions are defined in Referral.cpp

#include "Referral.h"

// Constructor
Referral::Referral
(   int idParam,
    FollowupStatus statusParam,
    Date dateDueParam,
    Date dateReceivedParam,
    Date dateCompletedParam,
    string resultsParam,
    string specialistNameParam,
    bool deletedParam)
    : ResultantFollowup (idParam,
                         statusParam,
                         dateDueParam,
                         dateReceivedParam,
                         dateCompletedParam,
                         resultsParam,
                         deletedParam),
      specialistName (specialistNameParam)
{
}

// Destructor
Referral::~Referral()
{
}

string Referral::getSpecialistName() { return specialistName; }
void Referral::setSpecialistName(const string value) { specialistName = value; }


//Special getters and setters for serialization purposes
//
QString Referral::qGetSpecialistName(){return QString::fromStdString(specialistName);}
void Referral::qSetSpecialistName(const QString value){specialistName = value.toStdString();}

// EOF
