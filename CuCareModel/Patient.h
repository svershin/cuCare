// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Patient.h - Declaration of base class Patient
// Member functions are defined in Patient.cpp

#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <string>
#include "Consultation.h"
#include "ContactInfo.h"
#include "Date.h"
#include "Address.h"
#include "HealthCard.h"
#include "Physician.h"
#include "modelobject.h"

using namespace std;

class Patient : public ModelObject
{

    Q_OBJECT

    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(QString firstName READ qGetFirstName WRITE qSetFirstName)
    Q_PROPERTY(QString lastName READ qGetLastName WRITE qSetLastName)
    Q_PROPERTY(QString notes READ qGetNotes WRITE qSetNotes)
    Q_PROPERTY(QVariantMap contact READ qGetContact WRITE qSetContact)
    Q_PROPERTY(QVariantMap address READ qGetAddress WRITE qSetAddress)
    Q_PROPERTY(QVariantMap dateOfBirth READ qGetDateOfBirth WRITE qSetDateOfBirth)
    Q_PROPERTY(QVariantMap dateAddedToSystem READ qGetDateAddedToSystem WRITE qSetDateAddedToSystem)
    Q_PROPERTY(QVariantMap healthCard READ qGetHealthCard WRITE qSetHealthCard)
    Q_PROPERTY(bool deleted READ isDeleted WRITE qPutDeleted)



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

    Patient();

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

    vector<Consultation*>* getConsultations();

    void markDeleted();
    bool isDeleted();


    //Special getters and setters for serialization purposes
    QString qGetFirstName();
    void qSetFirstName(const QString value);

    QString qGetLastName();
    void qSetLastName(const QString value);

    QString qGetNotes();
    void qSetNotes(const QString value);

    QVariantMap qGetContact();
    void qSetContact(const QVariantMap value);

    QVariantMap qGetAddress();
    void qSetAddress(const QVariantMap value);

    QVariantMap qGetDateOfBirth();
    void qSetDateOfBirth(const QVariantMap value);

    QVariantMap qGetDateAddedToSystem();
    void qSetDateAddedToSystem(const QVariantMap value);

    QVariantMap qGetHealthCard();
    void qSetHealthCard(const QVariantMap value);

    void qPutDeleted(const bool value);

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
    vector<Consultation*> Consultations;
};


#endif

// EOF
