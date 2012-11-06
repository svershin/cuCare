// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Followup.h - Declaration of base class Followup
// Member functions are defined in Followup.cpp

#ifndef FOLLOWUP_H
#define FOLLOWUP_H

#include "Date.h"

class Followup
{
public:

    enum FollowupStatus
    {
        FSTAT_ERROR,
        FSTAT_PENDING,
        FSTAT_OVERDUE,
        FSTAT_RECEIVED,
        FSTAT_COMPLETED
    };

    // Constructor
    Followup (int idParam,
              FollowupStatus statusParam,
              Date dateDueParam,
              Date dateReceivedParam,
              Date dateCompletedParam,
              bool deletedParam);

    // Destructor
    ~Followup();

    int getId();
    void setId(int newId);

    FollowupStatus getStatus();
    void setStatus(const FollowupStatus value);

    Date getDateDue();
    void setDateDue(const Date value);

    Date getDateReceived();
    void setDateReceived(const Date value);

    Date getDateCompleted();
    void setDateCompleted(const Date value);

    void markDeleted();
    bool isDeleted();

    virtual int getType() = 0;

protected:
private:
    int id;
    FollowupStatus status;
    Date dateDue;
    Date dateReceived;
    Date dateCompleted;
    bool deleted;
};


#endif

// EOF
