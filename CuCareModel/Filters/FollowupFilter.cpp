#include "FollowupFilter.h"

FollowupFilter::FollowupFilter()
    : idMatch(false),
      statusMatch(false),
      dateDueMatch(false),
      dateReceivedMatch(false),
      dateCompletedMatch(false),
      deletedMatch(false)
{
}

bool FollowupFilter::idGetMatch() { return idMatch; }
void FollowupFilter::idSetMatch(bool match) { idMatch = match; }

bool FollowupFilter::statusGetMatch() { return statusMatch; }
void FollowupFilter::statusSetMatch(bool match) { statusMatch = match; }

bool FollowupFilter::dateDueGetMatch() { return dateDueMatch; }
void FollowupFilter::dateDueSetMatch(bool match) { dateDueMatch = match; }

bool FollowupFilter::dateReceivedGetMatch() { return dateReceivedMatch; }
void FollowupFilter::dateReceivedSetMatch(bool match) { dateReceivedMatch = match; }

bool FollowupFilter::dateCompletedGetMatch() { return dateCompletedMatch; }
void FollowupFilter::dateCompletedSetMatch(bool match) { dateCompletedMatch = match; }

bool FollowupFilter::deletedGetMatch() { return deletedMatch; }
void FollowupFilter::deletedSetMatch(bool match) { deletedMatch = match; }
