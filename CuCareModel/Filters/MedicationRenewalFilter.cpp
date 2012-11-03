#include "MedicationRenewalFilter.h"

MedicationRenewalFilter::MedicationRenewalFilter()
{
}

bool MedicationRenewalFilter::medicationGetMatch() { return medicationMatch; }
void MedicationRenewalFilter::medicationSetMatch(bool match) { medicationMatch = match; }
