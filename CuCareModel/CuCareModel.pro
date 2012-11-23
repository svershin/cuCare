#-------------------------------------------------
#
# Project created by QtCreator 2012-10-29T12:31:07
#
#-------------------------------------------------

QT       -= gui

TARGET = CuCareModel
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    User.cpp \
    Time.cpp \
    SysAdmin.cpp \
    ReturnConsultation.cpp \
    ResultantFollowup.cpp \
    Referral.cpp \
    Physician.cpp \
    Patient.cpp \
    MedicationRenewal.cpp \
    MedicalTest.cpp \
    HealthCard.cpp \
    Followup.cpp \
    Date.cpp \
    ContactInfo.cpp \
    Consultation.cpp \
    AdminAssistant.cpp \
    Address.cpp \
    Filters/ConsultationFilter.cpp \
    Filters/FollowupFilter.cpp \
    Filters/MedicationRenewalFilter.cpp \
    Filters/PatientFilter.cpp \
    Filters/PhysicianFilter.cpp \
    Filters/ReferralFilter.cpp \
    Filters/ResultantFollowupFilter.cpp \
    Filters/ReturnConsultationFilter.cpp \
    Filters/UserFilter.cpp \
    Filters/MedicalTestFilter.cpp \
    ModelObject.cpp \
    Property.cpp \
    StringProperty.cpp \
    IntProperty.cpp \
    Utility.cpp

HEADERS += \
    User.h \
    Time.h \
    SysAdmin.h \
    ReturnConsultation.h \
    ResultantFollowup.h \
    Referral.h \
    Physician.h \
    Patient.h \
    MedicationRenewal.h \
    MedicalTest.h \
    HealthCard.h \
    Followup.h \
    Date.h \
    ContactInfo.h \
    Consultation.h \
    AdminAssistant.h \
    Address.h \
    ModelFiles.h \
    Filters/ReturnConsultationFilter.h \
    Filters/ResultantFollowupFilter.h \
    Filters/UserFilter.h \
    Filters/ReferralFilter.h \
    Filters/PhysicianFilter.h \
    Filters/PatientFilter.h \
    Filters/MedicationRenewalFilter.h \
    Filters/FollowupFilter.h \
    Filters/MedicalTestFilter.h \
    ModelObject.h \
    Property.h \
    StringProperty.h \
    IntProperty.h \
    Utility.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
