// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Followup.h - Declaration of base class Followup
// Member functions are defined in Followup.cpp

#include "Followup.h"

// Constructor
Followup::Followup
(   int idParam,
    Followup::FollowupStatus statusParam,
    Date dateDueParam,
    Date dateReceivedParam,
    Date dateCompletedParam,
    bool deletedParam)
    : id (idParam),
      status (statusParam),
      dateDue (dateDueParam),
      dateReceived (dateReceivedParam),
      dateCompleted (dateCompletedParam),
      deleted (deletedParam)
{}

Followup::Followup(){}

// Destructor
Followup::~Followup()
{
}

int Followup::getId() { return id; }
void Followup::setId(int newId) { id = newId; }

Followup::FollowupStatus Followup::getStatus() { return status; }
void Followup::setStatus(const FollowupStatus value) { status = value; }

Date Followup::getDateDue() { return dateDue; }
void Followup::setDateDue(const Date value) { dateDue = value; }

Date Followup::getDateReceived() { return dateReceived; }
void Followup::setDateReceived(const Date value) { dateReceived = value; }

Date Followup::getDateCompleted() { return dateCompleted; }
void Followup::setDateCompleted(const Date value) { dateCompleted = value; }

void Followup::markDeleted() { deleted = true; }
bool Followup::isDeleted() { return deleted; }


// Special getters and setters for serialization purposes
//
QVariantMap Followup::qGetDateDue(){return QJson::QObjectHelper::qobject2qvariant(&dateDue);}
void Followup::qSetDateDue(const QVariantMap value){QJson::QObjectHelper::qvariant2qobject(value, &dateDue);}

QVariantMap Followup::qGetDateReceived(){return QJson::QObjectHelper::qobject2qvariant(&dateReceived);}
void Followup::qSetDateReceived(const QVariantMap value){QJson::QObjectHelper::qvariant2qobject(value, &dateReceived);}

QVariantMap Followup::qGetDateCompleted(){return QJson::QObjectHelper::qobject2qvariant(&dateCompleted);}
void Followup::qSetDateCompleted(const QVariantMap value){QJson::QObjectHelper::qvariant2qobject(value, &dateCompleted);}

void Followup::qPutDeleted(const bool value){deleted = value;}

// EOF
