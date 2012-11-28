#-------------------------------------------------
#
# Project created by QtCreator 2012-11-09T15:13:13
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = OutsideTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    CommsTesting.cpp

unix:!macx:!symbian: LIBS += -L$$PWD/../Communications/ -lCommunications

INCLUDEPATH += $$PWD/../Communications
DEPENDPATH += $$PWD/../Communications

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../Communications/libCommunications.a




unix:!macx:!symbian: LIBS += -L$$PWD/../qjson/build/lib/ -lqjson

INCLUDEPATH += $$PWD/../qjson/build
DEPENDPATH += $$PWD/../qjson/build

HEADERS += \
    CommsTesting.h
