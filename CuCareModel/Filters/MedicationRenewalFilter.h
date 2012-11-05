#ifndef MEDICATIONRENEWALFILTER_H
#define MEDICATIONRENEWALFILTER_H

#include "FollowupFilter.h"

class MedicationRenewalFilter : public FollowupFilter
{
    Q_OBJECT

    Q_PROPERTY(bool Match READ GetMatch WRITE SetMatch)
public:
    MedicationRenewalFilter();

    bool medicationGetMatch();
    void medicationSetMatch(bool match);

private:
    bool medicationMatch;
};

#endif // MEDICATIONRENEWALFILTER_H
