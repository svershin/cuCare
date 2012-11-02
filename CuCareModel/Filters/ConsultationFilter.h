#ifndef CONSULTATIONFILTER_H
#define CONSULTATIONFILTER_H

class ConsultationFilter
{
public:
    ConsultationFilter();

    bool consultIDGetMatch();
    void consultIDSetMatch(bool match);

    bool reasonGetMatch();
    void reasonSetMatch(bool match);

    bool diagnosisGetMatch();
    void diagnosisSetMatch(bool match);

    bool commentsGetMatch();
    void commentsSetMatch(bool match);

    bool statusGetMatch();
    void statusSetMatch(bool match);
//https://www.youtube.com/watch?v=y9K18CGEeiI&feature=plcp
    bool dateGetMatch();
    void dateSetMatch(bool match);

    bool timeGetMatch();
    void timeSetMatch(bool match);

    bool pConsultingPhysGetMatch();
    void pConsultingPhysSetMatch(bool match);

    bool deletedGetMatch();
    void deletedSetMatch(bool match);

private:
    bool consultIDMatch;
    bool reasonMatch;
    bool diagnosisMatch;
    bool commentsMatch;
    bool statusMatch;
    bool dateMatch;
    bool timeMatch;
    bool pConsultingPhysMatch;
    bool deletedMatch;
};

#endif // CONSULTATIONFILTER_H
