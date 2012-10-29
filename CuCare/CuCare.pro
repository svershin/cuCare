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

HEADERS  += cucare.h \

FORMS    += cucare.ui

unix:!macx:!symbian: LIBS += -L$$PWD/ -lCuCareModel

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/libCuCareModel.a
