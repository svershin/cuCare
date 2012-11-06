// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ResultantFollowup.h - Declaration of base class ResultantFollowup
// Member functions are defined in ResultantFollowup.cpp

#ifndef RESULTANTFOLLOWUP_H
#define RESULTANTFOLLOWUP_H

#include <string>
#include "Followup.h"

using namespace std;

class ResultantFollowup:public Followup
{
public:

    // Constructor
    ResultantFollowup (int idParam,
                       FollowupStatus statusParam,
                       Date dateDueParam,
                       Date dateReceivedParam,
                       Date dateCompletedParam,
                       string resultsParam,
                       bool deletedParam);

    // Destructor
    ~ResultantFollowup();

    string getResults();
    void setResults(const string value);

    virtual int getType() = 0;

protected:
private:
    string results;
};


#endif

// EOF
