#include "AuditTimer.h"
#include <QTime>

AuditTimer::AuditTimer(string dailyTimeoutStr, QObject *parent)
    : QTimer()
{
    connect(this, SIGNAL(timeout()), this, SLOT(set24HourInterval()));
    connect(this, SIGNAL(timeout()), parent, SLOT(runAudit()));
    setInitialInterval(dailyTimeoutStr);
}

AuditTimer::AuditTimer(const AuditTimer& origin)
    : QTimer()
{}

AuditTimer::~AuditTimer()
{

}


void AuditTimer::setInitialInterval(string dailyTime)
{
    QTime dailyTimeoutTime = QTime::fromString(QString::fromStdString(dailyTime), "h:mm:ss");

    if (dailyTimeoutTime.isValid())
    {
        int timeToWait = QTime::currentTime().msecsTo(dailyTimeoutTime);
        if(timeToWait < 0)
        {
            setInterval(MSECS_IN_A_DAY + timeToWait);
        }
        else
        {
            setInterval(timeToWait);
        }
    }
    else
    {
        throw(string("Invalid time string passed in the creation of an AuditTimer"));
    }

    return;
}

void AuditTimer::set24HourInterval()
{
    setInterval(MSECS_IN_A_DAY);
}
