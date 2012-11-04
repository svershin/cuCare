#ifndef FOLLOWUPFILTER_H
#define FOLLOWUPFILTER_H

class FollowupFilter
{
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
