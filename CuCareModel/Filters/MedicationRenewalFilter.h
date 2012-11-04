#ifndef MEDICATIONRENEWALFILTER_H
#define MEDICATIONRENEWALFILTER_H

#include "FollowupFilter.h"

class MedicationRenewalFilter : public FollowupFilter
{
public:
    MedicationRenewalFilter();

    bool medicationGetMatch();
    void medicationSetMatch(bool match);

private:
    bool medicationMatch;
};

#endif // MEDICATIONRENEWALFILTER_H
