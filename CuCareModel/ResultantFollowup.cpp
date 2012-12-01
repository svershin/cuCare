// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ResultantFollowup.cpp - Implementation of class ResultantFollowup
// Function and attribute declarations are in ResultantFollowup.h

#include "ResultantFollowup.h"
#include "StringProperty.h"

// Constructor
ResultantFollowup::ResultantFollowup() {
	getProperties()->push_back(new StringProperty("results", this, &ModelObject::getResults, &ModelObject::setResults));
}

string ResultantFollowup::getResults() { return results; }
void ResultantFollowup::setResults(const string value) { results = value; }

// EOF