// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
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
{
}

// Destructor
MedicationRenewal::~MedicationRenewal()
{
}

string MedicationRenewal::getMedication() { return medication; }
void MedicationRenewal::setMedication(const string value) { medication = value; }

int MedicationRenewal::getType() { return 2; }

// EOF
