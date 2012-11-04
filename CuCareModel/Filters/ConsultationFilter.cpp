#include "ConsultationFilter.h"

ConsultationFilter::ConsultationFilter()
    : consultIDMatch(false),
      patientIdMatch(false),
      reasonMatch(false),
      diagnosisMatch(false),
      commentsMatch(false),
      statusMatch(false),
      dateMatch(false),
      timeMatch(false),
      pConsultingPhysMatch(false),
      deletedMatch(false)
{
}

bool ConsultationFilter::consultIDGetMatch() { return consultIDMatch; }
void ConsultationFilter::consultIDSetMatch(bool match) { consultIDMatch = match; }

bool ConsultationFilter::patientIdGetMatch() { return patientIdMatch; }
void ConsultationFilter::patientIdSetMatch(bool match) { patientIdMatch = match; }

bool ConsultationFilter::reasonGetMatch() { return reasonMatch; }
void ConsultationFilter::reasonSetMatch(bool match) { reasonMatch = match; }

bool ConsultationFilter::diagnosisGetMatch() { return diagnosisMatch; }
void ConsultationFilter::diagnosisSetMatch(bool match) { diagnosisMatch = match; }

bool ConsultationFilter::commentsGetMatch() { return commentsMatch; }
void ConsultationFilter::commentsSetMatch(bool match) { commentsMatch = match; }

bool ConsultationFilter::statusGetMatch() { return statusMatch; }
void ConsultationFilter::statusSetMatch(bool match) { statusMatch = match; }

bool ConsultationFilter::dateGetMatch() { return dateMatch; }
void ConsultationFilter::dateSetMatch(bool match) { dateMatch = match; }

bool ConsultationFilter::timeGetMatch() { return timeMatch; }
void ConsultationFilter::timeSetMatch(bool match) { timeMatch = match; }

bool ConsultationFilter::pConsultingPhysGetMatch() { return pConsultingPhysMatch; }
void ConsultationFilter::pConsultingPhysSetMatch(bool match) { pConsultingPhysMatch = match; }

bool ConsultationFilter::deletedGetMatch() { return deletedMatch; }
void ConsultationFilter::deletedSetMatch(bool match) { deletedMatch = match; }
