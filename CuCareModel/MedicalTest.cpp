// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Test.h - Declaration of base class Test
// Member functions are defined in Test.cpp

#include "MedicalTest.h"

// Constructor
MedicalTest::MedicalTest
(   int idParam,
    FollowupStatus statusParam,
    Date dateDueParam,
    Date dateReceivedParam,
    Date dateCompletedParam,
    string resultsParam,
    string testTypeParam,
    bool deletedParam)
    : ResultantFollowup (idParam,
                         statusParam,
                         dateDueParam,
                         dateReceivedParam,
                         dateCompletedParam,
                         resultsParam,
                         deletedParam),
      testType (testTypeParam)
{
}

// Destructor
MedicalTest::~MedicalTest()
{
}

string MedicalTest::getTestType() { return testType; }
void MedicalTest::setTestType(const string value) { testType = value; }

//Special getters and setters for serialization purposes
//
QString MedicalTest::qGetTestType(){return QString::fromStdString(testType);}
void MedicalTest::qSetTestType(const QString value){testType = value.toStdString();}

// EOF
