// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Patient.h - Declaration of base class Patient
// Member functions are defined in Patient.cpp

#include "Patient.h"

// Constructor
Patient::Patient
(   int idParam,
    string firstNameParam,
    string lastNameParam,
    string notesParam,
    ContactInfo contactParam,
    Address addressParam,
    Date dateOfBirthParam,
    Date dateAddedToSystemParam,
    Physician* pPhysicianParam,
    HealthCard healthCardParam,
    bool deletedParam)
    : id (idParam),
      firstName (firstNameParam),
      lastName (lastNameParam),
      notes (notesParam),
      contact (contactParam),
      address (addressParam),
      dateOfBirth (dateOfBirthParam),
      dateAddedToSystem (dateAddedToSystemParam),
      pPhysician (pPhysicianParam),
      healthCard (healthCardParam),
      deleted (deletedParam)
{
}

// Destructor
Patient::~Patient()
{
}

int Patient::getId() { return id; }
void setId(int value) { id = value; }

string Patient::getFirstName() { return firstName; }
void Patient::setFirstName(const string value) { firstName = value; }

string Patient::getLastName() { return lastName; }
void Patient::setLastName(const string value) { lastName = value; }

string Patient::getNotes() { return notes; }
void Patient::setNotes(const string value) { notes = value; }

ContactInfo Patient::getContact() { return contact; }
void Patient::setContact(const ContactInfo value) { contact = value; }

Address Patient::getAddress() { return address; }
void Patient::setAddress(const Address value) { address = value; }

Date Patient::getDateOfBirth() { return dateOfBirth; }
void Patient::setDateOfBirth(const Date value) { dateOfBirth = value; }

Date Patient::getDateAddedToSystem() { return dateAddedToSystem; }
void Patient::setDateAddedToSystem(const Date value) { dateAddedToSystem = value; }

HealthCard Patient::getHealthCard() { return healthCard; }
void Patient::setHealthCard(const HealthCard value) { healthCard = value; }

Physician* Patient::getPhysician() { return pPhysician; }
void Patient::setPhysician(Physician* const value) { pPhysician = value; }

void Patient::markDeleted() { deleted = true; }
bool Patient::isDeleted() { return deleted; }

// EOF
