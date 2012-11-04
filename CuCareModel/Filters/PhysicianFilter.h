#ifndef PHYSICIANFILTER_H
#define PHYSICIANFILTER_H

#include "UserFilter.h"

class PhysicianFilter : public UserFilter
{
public:
    PhysicianFilter();

    bool idGetMatch();
    void idSetMatch(bool match);

private:
    bool idMatch;
};

#endif // PHYSICIANFILTER_H
