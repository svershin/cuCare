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
    Filters/MedicalTestFilter.cpp

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
    Filters/ConsultationFilter.h \
    Filters/MedicalTestFilter.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

unix:!macx:!symbian: LIBS += -L$$PWD/../CuCareCommunications/qjson/lib/ -lqjson

INCLUDEPATH += $$PWD/../CuCareCommunications/qjson/include
DEPENDPATH += $$PWD/../CuCareCommunications/qjson/include
