// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Physician.h - Declaration of base class Physician
// Member functions are defined in Physician.cpp

#ifndef PHYSICIAN_H
#define PHYSICIAN_H

#include "User.h"

class Physician:public User
{
    Q_OBJECT

    Q_PROPERTY(int physicianId READ getId WRITE setId)

public:

    // Constructor
    Physician (int idParam,
               string usernameParam,
               string firstNameParam,
               string lastNameParam,
               Date dateOfBirthParam,
               ContactInfo contactParam,
               Address addressParam,
               bool deletedParam);

    Physician();

    // Destructor
    ~Physician();

    int getType() { return 2; }

    int getId();
    void setId(int value);

protected:
private:
    int id;
};


#endif

// EOF
