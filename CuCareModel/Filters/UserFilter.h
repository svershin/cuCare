#ifndef USERFILTER_H
#define USERFILTER_H

#include "../modelobject.h"

class UserFilter : public ModelObject
{
    Q_OBJECT

    Q_PROPERTY(bool usernameMatch READ usernameGetMatch WRITE usernameSetMatch)
    Q_PROPERTY(bool firstNameMatch READ firstNameGetMatch WRITE firstNameSetMatch)
    Q_PROPERTY(bool lastNameMatch READ lastNameGetMatch WRITE lastNameSetMatch)
    Q_PROPERTY(bool titleMatch READ titleGetMatch WRITE titleSetMatch)
    Q_PROPERTY(bool dateOfBirthMatch READ dateOfBirthGetMatch WRITE dateOfBirthSetMatch)
    Q_PROPERTY(bool contactMatch READ contactGetMatch WRITE contactSetMatch)
    Q_PROPERTY(bool addressMatch READ addressGetMatch WRITE addressSetMatch)
    Q_PROPERTY(bool deletedMatch READ deletedGetMatch WRITE deletedSetMatch)

public:
    UserFilter();

    bool usernameGetMatch();
    void usernameSetMatch(bool match);

    bool firstNameGetMatch();
    void firstNameSetMatch(bool match);

    bool lastNameGetMatch();
    void lastNameSetMatch(bool match);

    bool titleGetMatch();
    void titleSetMatch(bool match);

    bool dateOfBirthGetMatch();
    void dateOfBirthSetMatch(bool match);

    bool contactGetMatch();
    void contactSetMatch(bool match);

    bool addressGetMatch();
    void addressSetMatch(bool match);

    bool deletedGetMatch();
    void deletedSetMatch(bool match);

private:
    bool usernameMatch;
    bool firstNameMatch;
    bool lastNameMatch;
    bool titleMatch;
    bool dateOfBirthMatch;
    bool contactMatch;
    bool addressMatch;
    bool deletedMatch;
};

#endif // USERFILTER_H
