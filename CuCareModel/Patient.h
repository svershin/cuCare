// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Patient.h - Declaration of base class Patient
// Member functions are defined in Patient.cpp

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "ContactInfo.h"
#include "Date.h"
#include "Address.h"
#include "HealthCard.h"
#include "Physician.h"

using namespace std;

class Patient
{
public:

    // Constructor
    Patient (int idParam,
             string firstNameParam,
             string lastNameParam,
             string notesParam,
             ContactInfo contactParam,
             Address addressParam,
             Date dateOfBirthParam,
             Date dateAddedToSystemParam,
             Physician* pPhysicianParam,
             HealthCard healthCardParam,
             bool deletedParam);

    // Destructor
    ~Patient();

    int getId();
    void setId(int value);

    string getFirstName();
    void setFirstName(const string value);

    string getLastName();
    void setLastName(const string value);

    string getNotes();
    void setNotes(const string value);

    ContactInfo getContact();
    void setContact(const ContactInfo value);

    Address getAddress();
    void setAddress(const Address value);

    Date getDateOfBirth();
    void setDateOfBirth(const Date value);

    Date getDateAddedToSystem();
    void setDateAddedToSystem(const Date value);

    HealthCard getHealthCard();
    void setHealthCard(const HealthCard value);

    Physician* getPhysician();
    void setPhysician(Physician* const value);

    void markDeleted();
    bool isDeleted();

protected:
private:
    int id;
    string firstName;
    string lastName;
    string notes;
    ContactInfo contact;
    Address address;
    Date dateOfBirth;
    Date dateAddedToSystem;
    Physician* pPhysician;
    HealthCard healthCard;
    bool deleted;
};


#endif

// EOF
