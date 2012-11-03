#ifndef USERFILTER_H
#define USERFILTER_H

class UserFilter
{
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
