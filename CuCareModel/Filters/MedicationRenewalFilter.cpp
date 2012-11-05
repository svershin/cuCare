#include "MedicationRenewalFilter.h"

MedicationRenewalFilter::MedicationRenewalFilter()
    : medicationMatch(false)
{
}

bool MedicationRenewalFilter::medicationGetMatch() { return medicationMatch; }
void MedicationRenewalFilter::medicationSetMatch(bool match) { medicationMatch = match; }
