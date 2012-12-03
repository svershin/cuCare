#ifndef AUDITTIMER_H
#define AUDITTIMER_H

#include <QTimer>

#define MSECS_IN_A_DAY 86400000

using namespace std;

class AuditTimer : public QTimer
{

    Q_OBJECT

public:
    AuditTimer(string dailyTimeout, QObject *parent);
    AuditTimer(const AuditTimer& origin);

    ~AuditTimer();

    int findInitialInterval(string dailyTime);

public slots:
    void start24HourTick();

};

#endif // AUDITTIMER_H
