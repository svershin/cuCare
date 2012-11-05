// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Referral.h - Declaration of base class Referral
// Member functions are defined in Referral.cpp

#ifndef REFERRAL_H
#define REFERRAL_H

#include "ResultantFollowup.h"
#include <string>

using namespace std;

class Referral:public ResultantFollowup
{

    Q_OBJECT

    Q_PROPERTY(QString specialistName READ qGetSpecialistName WRITE qSetSpecialistName)
public:

    // Constructor
    Referral (int idParam,
              FollowupStatus statusParam,
              Date dateDueParam,
              Date dateReceivedParam,
              Date dateCompletedParam,
              string resultsParam,
              string specialistNameParam,
              bool deletedParam);

    // Destructor
    ~Referral();

    string getSpecialistName();
    void setSpecialistName(const string value);


    //Special getters and setters for serialization purposes
    QString qGetSpecialistName();
    void qSetSpecialistName(const QString value);


protected:
private:
    string specialistName;
};


#endif

// EOF
