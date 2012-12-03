// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ResultantFollowup.h - Declaration of class ResultantFollowup
// Member functions are defined in ResultantFollowup.cpp

#ifndef RESULTANTFOLLOWUP_H
#define RESULTANTFOLLOWUP_H

#include <string>
#include "Followup.h"

using namespace std;

class ResultantFollowup : public Followup
{
public:
	// Constructor
	ResultantFollowup ();

	// Class attribute get() & set() methods

    ModelObject::ObjectType getObjectType() = 0;

	string getResults();
	void setResults(const string value);

protected:
private:
		string results;
};


#endif // RESULTANTFOLLOWUP_H

// EOF
