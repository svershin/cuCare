#include "ResultantFollowupFilter.h"

ResultantFollowupFilter::ResultantFollowupFilter()
{
}

bool ResultantFollowupFilter::resultsGetMatch() { return resultsMatch; }
void ResultantFollowupFilter::resultsSetMatch(bool match) { resultsMatch = match; }
