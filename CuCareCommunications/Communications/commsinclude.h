#ifndef COMMSINCLUDE_H
#define COMMSINCLUDE_H

#define JSON_LEADING_STRIP 4

#include <QString>
#include <QtNetwork>
#include <QtGlobal>
#include <string>
#include <QTcpSocket>
#include <QObject>


#include "../../CuCareModel/Address.h"
#include "../../CuCareModel/AdminAssistant.h"
#include "../../CuCareModel/Consultation.h"
#include "../../CuCareModel/ContactInfo.h"
#include "../../CuCareModel/Date.h"
#include "../../CuCareModel/Followup.h"
#include "../../CuCareModel/HealthCard.h"
#include "../../CuCareModel/MedicalTest.h"
#include "../../CuCareModel/MedicationRenewal.h"
#include "../../CuCareModel/Patient.h"
#include "../../CuCareModel/Physician.h"
#include "../../CuCareModel/Referral.h"
#include "../../CuCareModel/ResultantFollowup.h"
#include "../../CuCareModel/ReturnConsultation.h"
#include "../../CuCareModel/SysAdmin.h"
#include "../../CuCareModel/Time.h"
#include "../../CuCareModel/User.h"

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
