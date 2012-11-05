// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MedicationRenewal.h - Declaration of base class MedicationRenewal
// Member functions are defined in MedicationRenewal.cpp

#ifndef MEDICATIONRENEWAL_H
#define MEDICATIONRENEWAL_H

#include "Followup.h"
#include <string>

using namespace std;

class MedicationRenewal:public Followup
{
    Q_OBJECT

    Q_PROPERTY(QString medication READ qGetMedication WRITE qSetMedication)

public:

    // Constructor
    MedicationRenewal (int idParam,
                       FollowupStatus statusParam,
                       Date dateDueParam,
                       Date dateReceivedParam,
                       Date dateCompletedParam,
                       string medicationParam,
                       bool deletedParam);

    // Destructor
    ~MedicationRenewal();

    string getMedication();
    void setMedication(const string value);

protected:
private:
    string medication;
};

#endif

// EOF
