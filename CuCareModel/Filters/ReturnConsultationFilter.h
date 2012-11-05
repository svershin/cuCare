#ifndef RETURNCONSULTATIONFILTER_H
#define RETURNCONSULTATIONFILTER_H

#include "FollowupFilter.h"

class ReturnConsultationFilter : public FollowupFilter
{
    Q_OBJECT

    Q_PROPERTY(bool pConsultMatch READ pConsultGetMatch WRITE pConsultSetMatch)
public:
    ReturnConsultationFilter();

    bool pConsultGetMatch();
    void pConsultSetMatch(bool match);

private:
    bool pConsultMatch;
};

#endif // RETURNCONSULTATIONFILTER_H
