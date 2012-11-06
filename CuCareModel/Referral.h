// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
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

    int getType();

protected:
private:
    string specialistName;
};


#endif

// EOF
