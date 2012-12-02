// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// ModelObject.h - Declaration of base class ModelObject
// Member functions are defined in ModelObject.cpp

#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <string>
#include <list>
#define OBJECT_TYPE_PROPERTY_NAME "objectType"
#define ID_NAME_PROPERTY_NAME "idname"
#define PARENT_ID_PROPERTY_NAME "parentid"
class Property;

using namespace std;

class ModelObject
{
public:
	// Object type enumeration, used to identify leaf class type for conversion to/from an STL map

	enum ObjectType
	{
        OBJECT_ERROR,
		ADMINASSISTANT,
		SYSADMIN,
		PHYSICIAN,
		PATIENT,
		CONSULTATION,
		MEDICATIONRENEWAL,
		RESULTANTFOLLOWUP,
		MEDICALTEST,
		REFERRAL,
		RETURNCONSULTATION
	};

	// Consultation status enumeration, included because it is used as a return type for a virtual function below

	enum ConsultationStatus
	{
        CSTAT_PENDING,
        CSTAT_OCCURED,
        CSTAT_COMPLETED
	};

	// Follow-up status enumeration, included because it is used as a return type for a virtual function below

	enum FollowupStatus
	{
        FSTAT_PENDING,
        FSTAT_OVERDUE,
        FSTAT_RECEIVED,
        FSTAT_COMPLETED
	};

	ModelObject();

	~ModelObject();

	// Functions to be implemented by leaf Model classes

	virtual string getTableName() = 0;
    virtual string getIdName() = 0;

    virtual ObjectType getObjectType();

	// ModelObject member functions

	list<Property*>* getProperties();

    int isDeleted();
    void markDeleted(int value);

	// Child class member function declarations (enables Properties functionality)

	// From User.h

	virtual int getId();
    virtual void setId(const int value);

	virtual string getUsername();
    virtual void setUsername(const string value);

	virtual string getFirstName();
	virtual void setFirstName(const string value);

	virtual string getLastName();
	virtual void setLastName(const string value);

	virtual string getCountry();
	virtual void setCountry(const string value);

	virtual string getCity();
	virtual void setCity(const string value);

	virtual string getLineOne();
	virtual void setLineOne(const string value);

	virtual string getLineTwo();
	virtual void setLineTwo(const string value);

	virtual string getPostalCode();
	virtual void setPostalCode(const string value);

	virtual string getWorkPhone();
	virtual void setWorkPhone(const string value);

	virtual string getCellPhone();
	virtual void setCellPhone(const string value);

	virtual string getEmail();
	virtual void setEmail(const string value);

	virtual string getWorkEmail();
	virtual void setWorkEmail(const string value);

	virtual int getDay();
	virtual void setDay(const int value);

	virtual int getMonth();
	virtual void setMonth(const int value);

	virtual int getYear();
	virtual void setYear(const int value);

	// from Physician.h

	virtual int getPhysicianId();
	virtual void setPhysicianId(const int value);

	// from Patient.h

	virtual int getDay1();
	virtual void setDay1(const int value);

	virtual int getMonth1();
	virtual void setMonth1(const int value);

	virtual int getYear1();
	virtual void setYear1(const int value);

	virtual string getHCNumber();
	virtual void setHCNumber(const string value);

	virtual int getHCExpiryDay();
	virtual void setHCExpiryDay(const int value);

	virtual int getHCExpiryMonth();
	virtual void setHCExpiryMonth(const int value);

	virtual int getHCExpiryYear();
	virtual void setHCExpiryYear(const int value);

	virtual string getNotes();
	virtual void setNotes(const string value);

	// from Consultation.h

	virtual string getReason();
	virtual void setReason(const string value);

	virtual string getDiagnosis();
	virtual void setDiagnosis(const string value);

	virtual string getComments();
	virtual void setComments(const string value);

    virtual int getCStatus();
    virtual void setCStatus(const int value);

	virtual int getHour();
	virtual void setHour(int value);

	virtual int getMinute();
	virtual void setMinute(int value);

	// from Followup.h

    virtual int getFStatus();
    virtual void setFStatus(const int value);

	virtual int getDay2();
	virtual void setDay2(const int value);

	virtual int getMonth2();
	virtual void setMonth2(const int value);

	virtual int getYear2();
	virtual void setYear2(const int value);

	// from MedicationRenewal.h

	virtual string getMedication();
	virtual void setMedication(const string value);

	// from ResultantFollowup.h

	virtual string getResults();
	virtual void setResults(const string value);

	// from MedicalTest.h

	virtual string getTestType();
	virtual void setTestType(const string value);

	// from Referral.h

	virtual string getSpecialistName();
	virtual void setSpecialistName(const string value);

	// from ReturnConsultation.h

	virtual int getConsultId();
	virtual void setConsultId(const int value);

private:
	list<Property*> properties;
	bool deleted;
};

#endif // MODELOBJECT_H

// EOF
