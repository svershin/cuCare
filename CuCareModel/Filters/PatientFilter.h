#ifndef PATIENTFILTER_H
#define PATIENTFILTER_H

#include "../modelobject.h"

class PatientFilter : public ModelObject
{
    Q_OBJECT

    Q_PROPERTY(bool idMatch READ idGetMatch WRITE idSetMatch)
    Q_PROPERTY(bool firstNameMatch READ firstNameGetMatch WRITE firstNameSetMatch)
    Q_PROPERTY(bool lastNameMatch READ lastNameGetMatch WRITE lastNameSetMatch)
    Q_PROPERTY(bool notesMatch READ notesGetMatch WRITE notesSetMatch)
    Q_PROPERTY(bool contactMatch READ contactGetMatch WRITE contactSetMatch)
    Q_PROPERTY(bool addressMatch READ addressGetMatch WRITE addressSetMatch)
    Q_PROPERTY(bool dateOfBirthMatch READ dateOfBirthGetMatch WRITE dateOfBirthSetMatch)
    Q_PROPERTY(bool dateAddedToSystemMatch READ dateAddedToSystemGetMatch WRITE dateAddedToSystemSetMatch)
    Q_PROPERTY(bool healthCardMatch READ healthCardGetMatch WRITE healthCardSetMatch)
    Q_PROPERTY(bool pPhysicianMatch READ pPhysicianGetMatch WRITE pPhysicianSetMatch)
    Q_PROPERTY(bool deletedMatch READ deletedGetMatch WRITE deletedSetMatch)


public:
    PatientFilter();

    bool idGetMatch();
    void idSetMatch(bool match);

    bool firstNameGetMatch();
    void firstNameSetMatch(bool match);

    bool lastNameGetMatch();
    void lastNameSetMatch(bool match);

    bool notesGetMatch();
    void notesSetMatch(bool match);

    bool contactGetMatch();
    void contactSetMatch(bool match);

    bool addressGetMatch();
    void addressSetMatch(bool match);

    bool dateOfBirthGetMatch();
    void dateOfBirthSetMatch(bool match);

    bool dateAddedToSystemGetMatch();
    void dateAddedToSystemSetMatch(bool match);

    bool healthCardGetMatch();
    void healthCardSetMatch(bool match);

    bool pPhysicianGetMatch();
    void pPhysicianSetMatch(bool match);

    bool deletedGetMatch();
    void deletedSetMatch(bool match);

private:
    bool idMatch;
    bool firstNameMatch;
    bool lastNameMatch;
    bool notesMatch;
    bool contactMatch;
    bool addressMatch;
    bool dateOfBirthMatch;
    bool dateAddedToSystemMatch;
    bool healthCardMatch;
    bool pPhysicianMatch;
    bool deletedMatch;
};

#endif // PATIENTFILTER_H
