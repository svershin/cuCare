#ifndef MEDICALTESTFILTER_H
#define MEDICALTESTFILTER_H

#include "ResultantFollowupFilter.h"

class MedicalTestFilter : public ResultantFollowupFilter
{
public:
    MedicalTestFilter();

    bool testTypeGetMatch();
    void testTypeSetMatch(bool match);

private:
    bool testTypeMatch;
};

#endif // MEDICALTESTFILTER_H
