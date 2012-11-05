#include "ReturnConsultationFilter.h"

ReturnConsultationFilter::ReturnConsultationFilter()
    : pConsultMatch(false)
{
}

bool ReturnConsultationFilter::pConsultGetMatch() { return pConsultMatch; }
void ReturnConsultationFilter::pConsultSetMatch(bool match) { pConsultMatch = match; }
