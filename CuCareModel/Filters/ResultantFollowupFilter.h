#ifndef RESULTANTFOLLOWUPFILTER_H
#define RESULTANTFOLLOWUPFILTER_H

#include "FollowupFilter.h"

class ResultantFollowupFilter : public FollowupFilter
{
public:
    ResultantFollowupFilter();

    bool resultsGetMatch();
    void resultsSetMatch(bool match);

private:
    bool resultsMatch;
};

#endif // RESULTANTFOLLOWUPFILTER_H
