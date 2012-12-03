#include "AuditTimer.h"
#include <QTime>
#include <iostream>

using namespace std;

AuditTimer::AuditTimer(string dailyTimeoutStr, QObject *parent)
    : QTimer()
{
    connect(this, SIGNAL(timeout()), this, SLOT(start24HourTick()));
    connect(this, SIGNAL(timeout()), parent, SLOT(runAudit()));

    start(findInitialInterval(dailyTimeoutStr));
}

AuditTimer::AuditTimer(const AuditTimer& origin)
    : QTimer()
{}

AuditTimer::~AuditTimer()
{

}


int AuditTimer::findInitialInterval(string dailyTime)
{
    QTime dailyTimeoutTime = QTime::fromString(QString::fromStdString(dailyTime), "h:mm:ss");

    if (dailyTimeoutTime.isValid())
    {
        int timeToWait = QTime::currentTime().msecsTo(dailyTimeoutTime);
        if(timeToWait < 0)
        {
            return MSECS_IN_A_DAY + timeToWait;
        }
        else
        {
            return timeToWait;
        }
    }
    else
    {
        throw(string("Invalid time string passed in the creation of an AuditTimer"));
    }

    return -1;
}

void AuditTimer::start24HourTick()
{
    start(MSECS_IN_A_DAY);
}
