#include "PatientFilter.h"

PatientFilter::PatientFilter()
{
}

bool PatientFilter::idGetMatch() { return idMatch; }
void PatientFilter::idSetMatch(bool match) { idMatch = match; }

bool PatientFilter::firstNameGetMatch() { return firstNameMatch; }
void PatientFilter::firstNameSetMatch(bool match) { firstNameMatch = match; }

bool PatientFilter::lastNameGetMatch() { return lastNameMatch; }
void PatientFilter::lastNameSetMatch(bool match) { lastNameMatch = match; }

bool PatientFilter::notesGetMatch() { return notesMatch; }
void PatientFilter::notesSetMatch(bool match) { notesMatch = match; }

bool PatientFilter::contactGetMatch() { return contactMatch; }
void PatientFilter::contactSetMatch(bool match) { contactMatch = match; }

bool PatientFilter::addressGetMatch() { return addressMatch; }
void PatientFilter::addressSetMatch(bool match) { addressMatch = match; }

bool PatientFilter::dateOfBirthGetMatch() { return dateOfBirthMatch; }
void PatientFilter::dateOfBirthSetMatch(bool match) { dateOfBirthMatch = match; }

bool PatientFilter::dateAddedToSystemGetMatch() { return dateAddedToSystemMatch; }
void PatientFilter::dateAddedToSystemSetMatch(bool match) { dateAddedToSystemMatch = match; }

bool PatientFilter::healthCardGetMatch() { return healthCardMatch; }
void PatientFilter::healthCardSetMatch(bool match) { healthCardMatch = match; }

bool PatientFilter::pPhysicianGetMatch() { return pPhysicianMatch; }
void PatientFilter::pPhysicianSetMatch(bool match) { pPhysicianMatch = match; }

bool PatientFilter::deletedGetMatch() { return deletedMatch; }
void PatientFilter::deletedSetMatch(bool match) { deletedMatch = match; }
