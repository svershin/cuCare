#include "ReferralFilter.h"

ReferralFilter::ReferralFilter()
    : specialistNameMatch(false)
{
}

bool ReferralFilter::specialistNameGetMatch() { return specialistNameMatch; }
void ReferralFilter::specialistNameSetMatch(bool match) { specialistNameMatch = match; }
