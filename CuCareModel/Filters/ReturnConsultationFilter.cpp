#include "ReturnConsultationFilter.h"

ReturnConsultationFilter::ReturnConsultationFilter()
{
}

bool ReturnConsultationFilter::pConsultGetMatch() { return pConsultMatch; }
void ReturnConsultationFilter::pConsultSetMatch(bool match) { pConsultMatch = match; }
