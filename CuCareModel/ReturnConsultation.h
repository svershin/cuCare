// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ReturnConsultation.h - Declaration of base class ReturnConsultation
// Member functions are defined in ReturnConsultation.cpp

#ifndef RETURNCONSULTAION_H
#define RETURNCONSULTAION_H

#include "Consultation.h"
#include "Followup.h"

class ReturnConsultation:public Followup
{
public:

    // Constructor
    ReturnConsultation (int idParam,
                        FollowupStatus statusParam,
                        Date dateDueParam,
                        Date dateReceivedParam,
                        Date dateCompletedParam,
                        Consultation* pConsultParam,
                        bool deletedParam);

    // Destructor
    ~ReturnConsultation();

    Consultation* getConsult();
    void setConsult(Consultation* const value);

protected:
private:
    Consultation* pConsult;
};

#endif

// EOF
