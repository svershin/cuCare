#include "ResultantFollowupFilter.h"

ResultantFollowupFilter::ResultantFollowupFilter()
    : resultsMatch(false)
{
}

bool ResultantFollowupFilter::resultsGetMatch() { return resultsMatch; }
void ResultantFollowupFilter::resultsSetMatch(bool match) { resultsMatch = match; }
