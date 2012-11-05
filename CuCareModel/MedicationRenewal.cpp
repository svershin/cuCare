// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// MedicationRenewal.h - Declaration of base class MedicationRenewal
// Member functions are defined in MedicationRenewal.cpp

#include "MedicationRenewal.h"

// Constructor
MedicationRenewal::MedicationRenewal
(   int idParam,
    FollowupStatus statusParam,
    Date dateDueParam,
    Date dateReceivedParam,
    Date dateCompletedParam,
    string medicationParam,
    bool deletedParam)
    : Followup (idParam,
                statusParam,
                dateDueParam,
                dateReceivedParam,
                dateCompletedParam,
                deletedParam),
      medication (medicationParam)
{}

MedicationRenewal::MedicationRenewal(){}

// Destructor
MedicationRenewal::~MedicationRenewal()
{
}

string MedicationRenewal::getMedication() { return medication; }
void MedicationRenewal::setMedication(const string value) { medication = value; }


// Special getters and setters for serialization purposes
//
QString MedicationRenewal::qGetMedication(){return QString::fromStdString(medication);}
void MedicationRenewal::qSetMedication(const QString value){medication = value.toStdString();}

// EOF
