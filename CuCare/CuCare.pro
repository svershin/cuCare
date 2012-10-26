#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T19:38:21
#
#-------------------------------------------------

QT       += core gui

TARGET = CuCare
TEMPLATE = app


SOURCES += main.cpp\
        cucare.cpp \
    Model/User.cpp \
    Model/Time.cpp \
    Model/SysAdmin.cpp \
    Model/ReturnConsultation.cpp \
    Model/ResultantFollowup.cpp \
    Model/Referral.cpp \
    Model/Physician.cpp \
    Model/Patient.cpp \
    Model/HealthCard.cpp \
    Model/Followup.cpp \
    Model/Date.cpp \
    Model/ContactInfo.cpp \
    Model/Consultation.cpp \
    Model/AdminAssistant.cpp \
    Model/Address.cpp \
    Model/MedicationRenewal.cpp \
    Model/MedicalTest.cpp

HEADERS  += cucare.h \
    Model/User.h \
    Model/Time.h \
    Model/SysAdmin.h \
    Model/ReturnConsultation.h \
    Model/ResultantFollowup.h \
    Model/Referral.h \
    Model/Physician.h \
    Model/Patient.h \
    Model/HealthCard.h \
    Model/Followup.h \
    Model/Date.h \
    Model/ContactInfo.h \
    Model/Consultation.h \
    Model/AdminAssistant.h \
    Model/Address.h \
    Model/MedicationRenewal.h \
    Model/MedicalTest.h

FORMS    += cucare.ui
