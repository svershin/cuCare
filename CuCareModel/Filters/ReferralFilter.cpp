#include "ReferralFilter.h"

ReferralFilter::ReferralFilter()
{
}

bool ReferralFilter::specialistNameGetMatch() { return specialistNameMatch; }
void ReferralFilter::specialistNameSetMatch(bool match) { specialistNameMatch = match; }
