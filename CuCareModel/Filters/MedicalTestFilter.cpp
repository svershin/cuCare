#include "MedicalTestFilter.h"

MedicalTestFilter::MedicalTestFilter()
{
}

bool MedicalTestFilter::testTypeGetMatch() { return testTypeMatch; }
void MedicalTestFilter::testTypeSetMatch(bool match) { testTypeMatch = match; }
