#include "MedicalTestFilter.h"

MedicalTestFilter::MedicalTestFilter()
    : testTypeMatch(false)
{
}

bool MedicalTestFilter::testTypeGetMatch() { return testTypeMatch; }
void MedicalTestFilter::testTypeSetMatch(bool match) { testTypeMatch = match; }
