#ifndef CONSULTATIONFILTER_H
#define CONSULTATIONFILTER_H

class ConsultationFilter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool consultIDMatch READ consultIDGetMatch WRITE consultIDSetMatch)
    Q_PROPERTY(bool patientIdMatch READ paitentIdGetMatch WRITE patientIdSetMatch)
    Q_PROPERTY(bool reasonMatch READ diagnosisGetMatch WRITE diagnosisSetMatch)
    Q_PROPERTY(bool diagnosisMatch READ diagnosisGetMatch WRITE diagnosisSetMatch)
    Q_PROPERTY(bool commentsMatch READ commentsGetMatch WRITE commentsSetMatch)
    Q_PROPERTY(bool statusMatch READ statusGetMatch WRITE statusSetMatch)
    Q_PROPERTY(bool dateMatch READ dateGetMatch WRITE dateSetMatch)
    Q_PROPERTY(bool timeMatch READ timeGetMatch WRITE timeSetMatch)
    Q_PROPERTY(bool pConsultingPhysMatch READ pConsultingPhysGetMatch WRITE pConsultingPhysSetMatch)
    Q_PROPERTY(bool deletedMatch READ deletedGetMatch WRITE deletedSetMatch)

    bool consultIDMatch;
    bool patientIdMatch;
    bool reasonMatch;
    bool diagnosisMatch;
    bool commentsMatch;
    bool statusMatch;
    bool dateMatch;
    bool timeMatch;
    bool pConsultingPhysMatch;
    bool deletedMatch;



public:
    ConsultationFilter();

    bool consultIDGetMatch();
    void consultIDSetMatch(bool match);

    bool patientIdGetMatch();
    void patientIdSetMatch(bool match);

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
    bool patientIdMatch;
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
