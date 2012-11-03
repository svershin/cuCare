#ifndef RETURNCONSULTATIONFILTER_H
#define RETURNCONSULTATIONFILTER_H

#include "FollowupFilter.h"

class ReturnConsultationFilter : public FollowupFilter
{
public:
    ReturnConsultationFilter();

    bool pConsultGetMatch();
    void pConsultSetMatch(bool match);

private:
    bool pConsultMatch;
};

#endif // RETURNCONSULTATIONFILTER_H
