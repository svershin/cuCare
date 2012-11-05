#ifndef FOLLOWUPFILTER_H
#define FOLLOWUPFILTER_H

#include "../modelobject.h"


class FollowupFilter : public ModelObject
{
    Q_OBJECT

    Q_PROPERTY(bool idMatch READ idGetMatch WRITE idSetMatch)
    Q_PROPERTY(bool statusMatch READ statusGetMatch WRITE statusSetMatch)
    Q_PROPERTY(bool dateDueMatch READ dateDueGetMatch WRITE dateDueSetMatch)
    Q_PROPERTY(bool dateReceivedMatch READ dateReceivedGetMatch WRITE dateReceivedSetMatch)
    Q_PROPERTY(bool dateCompletedMatch READ dateCompletedGetMatch WRITE dateCompletedSetMatch)
    Q_PROPERTY(bool deletedMatch READ deletedGetMatch WRITE deletedSetMatch)

public:
    FollowupFilter();

    bool idGetMatch();
    void idSetMatch(bool match);

    bool statusGetMatch();
    void statusSetMatch(bool match);

    bool dateDueGetMatch();
    void dateDueSetMatch(bool match);

    bool dateReceivedGetMatch();
    void dateReceivedSetMatch(bool match);

    bool dateCompletedGetMatch();
    void dateCompletedSetMatch(bool match);

    bool deletedGetMatch();
    void deletedSetMatch(bool match);

private:
    bool idMatch;
    bool statusMatch;
    bool dateDueMatch;
    bool dateReceivedMatch;
    bool dateCompletedMatch;
    bool deletedMatch;
};

#endif // FOLLOWUPFILTER_H
