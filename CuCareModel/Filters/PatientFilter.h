#ifndef PATIENTFILTER_H
#define PATIENTFILTER_H

class PatientFilter
{
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
    bool deletedMatch;
};

#endif // PATIENTFILTER_H
