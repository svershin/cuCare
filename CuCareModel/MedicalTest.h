// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Test.h - Declaration of base class Test
// Member functions are defined in Test.cpp

#ifndef TEST_H
#define TEST_H

#include <string>
#include "ResultantFollowup.h"

using namespace std;

class MedicalTest:public ResultantFollowup
{
    Q_OBJECT

    Q_PROPERTY(QString testType READ qGetTestType WRITE qGetTestType)

public:

    // Constructor
    MedicalTest (int idParam,
                 FollowupStatus statusParam,
                 Date dateDueParam,
                 Date dateReceivedParam,
                 Date dateCompletedParam,
                 string resultsParam,
                 string testTypeParam,
                 bool deletedParam);

    // Destructor
    ~MedicalTest();

    string getTestType();
    void setTestType(const string value);

    //Special getters and setters for serialization purposes
    QString qGetTestType();
    void qSetTestType(const QString value);


protected:
private:
    string testType;
};


#endif

// EOF
