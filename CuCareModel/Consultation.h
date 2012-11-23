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
#include "ModelObject.h"

using namespace std;

class Consultation : public ModelObject
{
public:

    enum ConsultationStatus
    {
        CSTAT_ERROR,
        CSTAT_PENDING,
        CSTAT_OCCURED,
        CSTAT_COMPLETED
    };

    Consultation (); //Change constructor to a default one

    ~Consultation();

    //Leave normal getters and setters with string or int parameters alone
    int getConsultId();
    void setConsultId(int newConsultID);

    string getReason();
    void setReason(const string value);

    string getDiagnosis();
    void setDiagnosis(const string value);

    string getComments();
    void setComments(const string value);

    //This enum is really just an int, so it can stay the same
    ConsultationStatus getStatus();
    void setStatus(const ConsultationStatus value);

    //Getters and setters for nested objects have to be broken out into their fields
//    Date getDate();
//    void setDate(const Date value);

//    Time getTime();
//    void setTime(const Time value);

    //So instead of getDate, we have these three
    int getDay();
    void setDay(int value);

    int getMonth();
    void setMonth(int value);

    int getYear();
    void setYear(int value);

    //And likewise for getTime
    int getHour();
    void setHour(int value);

    int getMinute();
    void setMinute(int value);

    //Pointers become int ids
//    Physician* getConsultingPhys();
//    void setConsultingPhys(Physician *const value);

    //Like this
    int getConsultingPhysId();
    void setConsultingPhysId(int value);

    //Lists of nested objects are not stored in the db.  We'll store parent ids instead.
    //So, when a consultation goes through object storage, it's parent patient's id will get added to properties
    //But that doesn't have to be reflected here

    //Since the lists are still useful on the client side, we'll keep them around.
    //But there's no associated property
    vector<int>* getFollowupIds();

    //These changes to get and set methods need to be reflected in the .cpp file too

protected:
private:
    //Also in the parameter list
    int consultId;
    string reason;
    string diagnosis;
    string comments;
    ConsultationStatus status;
    Date date;
    Time time;
    vector<int> followupIds;
    int consultingPhysId;
};


#endif

// EOF
