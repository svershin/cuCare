#ifndef REFERRALFILTER_H
#define REFERRALFILTER_H

#include "ResultantFollowupFilter.h"

class ReferralFilter : public ResultantFollowupFilter
{
    Q_OBJECT

    Q_PROPERTY(bool specialistNameMatch READ specialistNameGetMatch WRITE specialistNameSetMatch)
public:
    ReferralFilter();

    bool specialistNameGetMatch();
    void specialistNameSetMatch(bool match);

private:
    bool specialistNameMatch;
};

#endif // REFERRALFILTER_H
