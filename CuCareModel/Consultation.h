// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Consultation.h - Declaration of base class Consultation
// Member functions are defined in Consultation.cpp

#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <string>
#include <vector>
#include "Date.h"
#include "Time.h"
#include "Followup.h"
#include "Physician.h"

using namespace std;

class Consultation
{
public:

    enum ConsultationStatus
    {
        CSTAT_ERROR,
        CSTAT_PENDING,
        CSTAT_OCCURED,
        CSTAT_COMPLETED
    };

    // Constructor
    Consultation (int consultIDParam,
                  string reasonParam,
                  string diagnosisParam,
                  string commentsParam,
                  ConsultationStatus statusParam,
                  Date dateParam,
                  Time timeParam,
                  Physician* pConsultingPhysParam,
                  bool deletedParam);

    // Destructor
    ~Consultation();

    int getConsultID();

    string getReason();
    void setReason(const string value);

    string getDiagnosis();
    void setDiagnosis(const string value);

    string getComments();
    void setComments(const string value);

    ConsultationStatus getStatus();
    void setStatus(const ConsultationStatus value);

    Date getDate();
    void setDate(const Date value);

    Time getTime();
    void setTime(const Time value);

    Physician* getConsultingPhys();
    void setConsultingPhys(Physician* const value);

    void markDeleted();
    bool isDeleted();

protected:
private:
    int consultID;
    string reason;
    string diagnosis;
    string comments;
    ConsultationStatus status;
    Date date;
    Time time;
    vector<Followup*> Followups;
    Physician* pConsultingPhys;
    bool deleted;
};


#endif

// EOF
