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
    Address.cpp

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
    ModelFiles.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
