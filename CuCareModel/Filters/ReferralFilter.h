#ifndef REFERRALFILTER_H
#define REFERRALFILTER_H

#include "ResultantFollowupFilter.h"

class ReferralFilter : public ResultantFollowupFilter
{
public:
    ReferralFilter();

    bool specialistNameGetMatch();
    void specialistNameSetMatch(bool match);

private:
    bool specialistNameMatch;
};

#endif // REFERRALFILTER_H
