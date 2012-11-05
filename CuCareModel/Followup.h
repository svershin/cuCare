// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Followup.h - Declaration of base class Followup
// Member functions are defined in Followup.cpp

#ifndef FOLLOWUP_H
#define FOLLOWUP_H

#include "Date.h"
#include <QVariant>
#include "modelobject.h"

class Followup : public ModelObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(FollowupStatus status READ getStatus WRITE setStatus)
    Q_PROPERTY(QVariantMap dateDue READ qGetDateDue WRITE qSetDateDue)
    Q_PROPERTY(QVariantMap dateReceived READ qGetDateReceived WRITE qSetDateDue)
    Q_PROPERTY(QVariantMap dateCompleted READ qGetDateCompleted WRITE qSetDateCompleted)
    Q_PROPERTY(bool deleted READ isDeleted WRITE qPutDeleted)
    Q_ENUMS(FollowupStatus)



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


    Followup();

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


    //Special getters and setters for serialization purposes
    QVariantMap qGetDateDue();
    void qSetDateDue(const QVariantMap value);

    QVariantMap qGetDateReceived();
    void qSetDateReceived(const QVariantMap value);

    QVariantMap qGetDateCompleted();
    void qSetDateCompleted(const QVariantMap value);

    void qPutDeleted(const bool value);

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
