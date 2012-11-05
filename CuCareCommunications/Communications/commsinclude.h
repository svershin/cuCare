#ifndef COMMSINCLUDE_H
#define COMMSINCLUDE_H

#define JSON_LEADING_STRIP 4

#include <QString>
#include <QtNetwork>
#include <QtGlobal>
#include <string>
#include <QTcpSocket>
#include <QObject>

#include "../../CuCareModel/ModelFiles.h"

#include "../../CuCareModel/Filters/ConsultationFilter.h"
#include "../../CuCareModel/Filters/FollowupFilter.h"
#include "../../CuCareModel/Filters/MedicalTestFilter.h"
#include "../../CuCareModel/Filters/MedicationRenewalFilter.h"
#include "../../CuCareModel/Filters/PatientFilter.h"
#include "../../CuCareModel/Filters/PhysicianFilter.h"
#include "../../CuCareModel/Filters/ReferralFilter.h"
#include "../../CuCareModel/Filters/ResultantFollowupFilter.h"
#include "../../CuCareModel/Filters/ReturnConsultationFilter.h"
#include "../../CuCareModel/Filters/UserFilter.h"

#include "../qjson/src/serializer.h"
#include "../qjson/src/qobjecthelper.h"


#endif // COMMSINCLUDE_H
