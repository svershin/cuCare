// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Followup.h - Declaration of base class Followup
// Member functions are defined in Followup.cpp

#include "Followup.h"

// Constructor
Followup::Followup
(   int idParam,
    FollowupStatus statusParam,
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
{
}

// Destructor
Followup::~Followup()
{
}

int Followup::getId() { return id; }

FollowupStatus Followup::getStatus() { return status; }
void Followup::setStatus(const FollowupStatus value) { status = value; }

Date Followup::getDateDue() { return dateDue; }
void Followup::setDateDue(const Date value) { dateDue = value; }

Date Followup::getDateReceived() { return dateReceived; }
void Followup::setDateReceived(const Date value) { dateReceived = value; }

Date Followup::getDateCompleted() { return dateCompleted; }
void Followup::setDateCompleted(const Date value) { dateCompleted = value; }

void Followup::markDeleted() { deleted = true; }

// EOF
