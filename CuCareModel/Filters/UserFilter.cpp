#include "UserFilter.h"

UserFilter::UserFilter()
{
}

bool UserFilter::usernameGetMatch() { return usernameMatch; }
void UserFilter::usernameSetMatch(bool match) { usernameMatch = match; }

bool UserFilter::firstNameGetMatch() { return firstNameMatch; }
void UserFilter::firstNameSetMatch(bool match) { firstNameMatch = match; }

bool UserFilter::lastNameGetMatch() { return lastNameMatch; }
void UserFilter::lastNameSetMatch(bool match) { lastNameMatch = match; }

bool UserFilter::titleGetMatch() { return titleMatch; }
void UserFilter::titleSetMatch(bool match) { titleMatch = match; }

bool UserFilter::dateOfBirthGetMatch() { return dateOfBirthMatch; }
void UserFilter::dateOfBirthSetMatch(bool match) { dateOfBirthMatch = match; }

bool UserFilter::contactGetMatch() { return contactMatch; }
void UserFilter::contactSetMatch(bool match) { contactMatch = match; }

bool UserFilter::addressGetMatch() { return addressMatch; }
void UserFilter::addressSetMatch(bool match) { addressMatch = match; }

bool UserFilter::deletedGetMatch() { return deletedMatch; }
void UserFilter::deletedSetMatch(bool match) { deletedMatch = match; }

