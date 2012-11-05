// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ResultantFollowup.h - Declaration of base class ResultantFollowup
// Member functions are defined in ResultantFollowup.cpp

#include "ResultantFollowup.h"

// Constructor
ResultantFollowup::ResultantFollowup
(   int idParam,
    FollowupStatus statusParam,
    Date dateDueParam,
    Date dateReceivedParam,
    Date dateCompletedParam,
    string resultsParam,
    bool deletedParam)
    : Followup (idParam,
                statusParam,
                dateDueParam,
                dateReceivedParam,
                dateCompletedParam,
                deletedParam),
      results (resultsParam)
{
}

// Destructor
ResultantFollowup::~ResultantFollowup()
{
}

string ResultantFollowup::getResults() { return results; }
void ResultantFollowup::setResults(const string value) { results = value; }

int ResultantFollowup::getType() { return 4; }

// EOF
